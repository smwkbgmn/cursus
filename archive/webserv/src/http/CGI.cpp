#include "CGI.hpp"

map_str_path_t	CGI::script_bin;
map_uint_str_t	CGI::environ_list;

/*
	.cgi, .exe and files in configured cgi-bin directory
	-> execute directly

	other else .perl, .php, .py.. so on 
	-> call the script interpreter as first arg and script path as second arg
*/

/* METHOD - init: assign keys for running CGI */
void
CGI::init( void ) {
	_assignScriptBin();
	_assignEnvironList();
}

void
CGI::_assignScriptBin( void ) {
	script_bin.insert( std::make_pair<str_t, path_t>( "php", "/usr/bin/php" ) );
	script_bin.insert( std::make_pair<str_t, path_t>( "pl", "/usr/bin/perl" ) );
	script_bin.insert( std::make_pair<str_t, path_t>( "py", "/usr/bin/python" ) );
}

void
CGI::_assignEnvironList( void ) {
	File	file_env( file_environ, READ );
	str_t	key;
	
	for ( uint_t keyidx = 0; std::getline( file_env.fs, key ); ++keyidx )
		environ_list.insert( std::make_pair( keyidx, key ) );
}

/* METHOD - proceed: get outsourcing data */
void
CGI::proceed( const Request& rqst, process_t& procs ) {
	log( "CGI\t: proceed" );

	_valid( rqst );
	_detach( rqst, procs );
}

void
CGI::_valid( const Request& rqst ) {
	if ( rqst.line().method != GET && rqst.line().method != POST ) {
		if ( rqst.line().method == NOT_ALLOWED ) throw errstat_t( 405 );
		else throw errstat_t( 403, err_msg[CGI_WITH_NOT_ALLOWED] );
	}
		
	if ( rqst.header().content_length > rqst.config().client_max_body )
		throw errstat_t( 413, err_msg[POST_OVER_CONTENT_LEN] );
}

void
CGI::_detach( const Request& rqst, process_t& procs ) {
	if ( pipe( procs.fd ) == ERROR ) throwSysErr( "pipe", 500 );
	if ( ( procs.pid = fork() )  == ERROR ) throwSysErr( "fork", 500 );

	if ( !procs.pid ) {
		_buildEnviron( rqst, procs );
		_execve( procs );
	}
}

/* PARENT */
void
CGI::writeTo( const process_t& procs, const char* in_body, const size_t& size ) {
	if ( write( procs.fd[W], in_body, size ) == ERROR )
		throwSysErr( "write", 500 );
}

void
CGI::wait( process_t& procs ) {
	if ( waitpid( procs.pid, &procs.stat, WNOHANG ) == ERROR )
		throwSysErr( "wait", 500 );
}

void
CGI::readFrom( const process_t& procs, sstream_t& out_body) {
	c_buffer_t	buf;
	
	while ( ( buf.read = read( procs.fd[R], buf.ptr, SIZE_BUF ) ) > 0 ) {
		out_body.write( buf.ptr, buf.read );
		buf.total += buf.read;
	}
	if ( buf.read == ERROR ) throwSysErr( "read", 500 );
	
	close( procs.fd[R] );
}

void
CGI::build( msg_buffer_t& out ) {
	_buildLine( out );
	if ( streamsize( out.body ) ) _buildHeader( out );
	if ( out.chunk ) { out.body.seekg( 0 ); _buildChunk( out ); }
}

void
CGI::_buildLine( msg_buffer_t& out ) {
	out.msg << 
	HTTP::http.signature << '/' << HTTP::http.version.at( VERSION_11 ) << SP;

	if ( !streamsize( out.body ) ) out.msg << "204" << SP << HTTP::key.status.at( 204 ) << CRLF;
	else out.msg << "200" << SP << HTTP::key.status.at( 200 );
	
	out.msg << CRLF;
}

void
CGI::_buildHeader( msg_buffer_t& out ) {
	size_t pos_header_end = out.body.str().find( MSG_END );

	_buildHeaderServer( out );

	// Add headers from the CGI contents and adjust out.body buffer 
	if ( found( pos_header_end ) ) {
		out.msg << out.body.str().substr( 0, pos_header_end + 2 );
		out.body.str( out.body.str().substr( pos_header_end + 4 ) );
	}

	_buildHeaderType( out, pos_header_end );
	_buildHeaderLen( out, pos_header_end );
	
	out.msg << CRLF;
}

void
CGI::_buildHeaderServer( msg_buffer_t& out ) {
	// Add server info
	out.msg << 
	HTTP::key.header_out.at( OUT_SERVER ) << ':' << SP <<
	software << CRLF;

	// Add date
	out.msg << 
	HTTP::key.header_out.at( OUT_DATE ) << ':' << SP <<
	timeToStr( getNow() ) << CRLF;

	// Add connection 
	out.msg << 
	HTTP::key.header_out.at( OUT_CONNECTION ) << ':' << SP <<
	HTTP::http.connection.at( CN_KEEP_ALIVE ) << CRLF;
}

void
CGI::_buildHeaderType( msg_buffer_t& out, const size_t& pos_header_end ) {
	if ( !found( pos_header_end ) || ( found( pos_header_end ) &&
		!found( out.msg.str().find( HTTP::key.header_out.at( OUT_CONTENT_TYPE ) ) ) ) ) {
		out.msg <<
		HTTP::key.header_out.at( OUT_CONTENT_TYPE ) << ':' << SP <<
		HTTP::key.mime.at( "txt" ) << CRLF;
	}
}

void
CGI::_buildHeaderLen( msg_buffer_t& out, const size_t& pos_header_end ) {
	if ( !found( pos_header_end ) || ( found( pos_header_end ) &&
		!found( out.msg.str().find( HTTP::key.header_out.at( OUT_CONTENT_LEN ) ) ) ) ) {
		out.msg << 
		HTTP::key.header_out.at( OUT_TRANSFER_ENC ) << ':' << SP <<
		HTTP::http.encoding.at( TE_CHUNKED ) << CRLF;

		out.chunk = TRUE;
	}
}

void
CGI::_buildChunk( msg_buffer_t& out ) {
	sstream_t	chunked;

	char		data[15];
	size_t		size = streamsize( out.body );
	size_t		frac;

	while ( size > 0 ) {
		if ( size > 14 ) frac = 15;
		else frac = size; 
		
		// Add chunk head
		chunked << hexdigt[frac] << CRLF;

		// Add chunk data
		out.body.read( data, frac );
		chunked.write( data, frac );
		chunked << CRLF;

		size -= frac;
	}
	chunked << "0" << CRLF << CRLF;

	out.body.str( chunked.str() );
}

/* CHILD */
void
CGI::_buildEnviron( const Request& rqst, process_t& procs ) {
	for ( uint_t idx = 0; _buildEnvironVar( rqst, procs, idx ); ++idx );
}

bool
CGI::_buildEnvironVar( const Request& rqst, process_t& procs, uint_t idx ) {
	try {
		osstream_t	oss;
		oss << environ_list.at( idx ) << '=';

		switch ( idx ) {
			case SERVER_NAME		: oss << rqst.header().host; break;
			case SERVER_PORT		: oss << rqst.config().listen; break;
			case SERVER_PROTOCOL	: oss << HTTP::http.signature << '/' << HTTP::http.version.at( VERSION_11 ); break;
			case REMOTE_ADDR		: break;
			case REMOTE_HOST		: oss << rqst.header().host; break;
			case GATEWAY_INTERFACE	: break;
			case REQUEST_METHOD		: oss << str_method[rqst.line().method]; break;
			case SCRIPT_NAME		: oss << rqst.line().uri.substr( rqst.line().uri.rfind( '/' ) + 1 ); break;

			case CONTENT_LENGTH		:
				if ( rqst.line().method == POST && rqst.header().transfer_encoding != TE_CHUNKED )
					oss << rqst.header().content_length; break;

			case CONTENT_TYPE		:
				if ( rqst.line().method == POST )
					oss << rqst.header().content_type; break;

			case PATH_INFO			: oss << rqst.line().uri.substr( rqst.location().root.length() + 1 ); break;
			case PATH_TRANSLATED	: oss << rqst.line().uri; break;
			case QUERY_STRING		: oss << rqst.line().query; break;
			case UPLOAD_DIR			: oss << rqst.location().upload; break;
			case HTTP_COOKIE		: oss << rqst.header().cookie; break;
		}
		procs.env.push_back( oss.str() );
		return TRUE;
	}
	catch ( exception_t& exc ) { return FALSE; }
}

bool
CGI::_redirect( const process_t& procs ) {
	if ( dup2( procs.fd[R], STDIN_FILENO ) == ERROR ||
		dup2( procs.fd[W], STDOUT_FILENO ) == ERROR ||
		close( procs.fd[R] ) == ERROR ||
		close( procs.fd[W] ) == ERROR )
		return FALSE;
	return TRUE;	
}

void
CGI::_execve( const process_t& procs ) {
	vec_cstr_t	argv_c;
	vec_cstr_t	env_c;

	_assignVectorChar( argv_c, procs.argv );
	_assignVectorChar( env_c, procs.env );

	if ( !_redirect( procs ) ||
		execve( argv_c[0], argv_c.data(), env_c.data() ) == ERROR )
		exit( EXIT_FAILURE );
}

void
CGI::_assignVectorChar( vec_cstr_t& vec_char, const vec_str_t& vec_str ) {
	for ( vec_str_t::const_iterator iter = vec_str.begin(); iter != vec_str.end(); ++iter )
		vec_char.push_back( const_cast<char*>( iter->c_str() ) );
	vec_char.push_back( NULL );
}

/* STRUCT */
c_buffer_s::c_buffer_s( void ) {
	total	= 0;
	read	= 0;
}

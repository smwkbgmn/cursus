#include "HTTP.hpp"

http_t	HTTP::http;
keys_t	HTTP::key;

/* METHOD - init: assign basic HTTP info and load keys */
void
HTTP::init( const str_t& type, const name_t& cgi ) {
	http.signature		= "HTTP";
	http.typeDefault	= type;
	http.locationCGI	= cgi;
	http.fileAtidx		= cgi + "/autoindex.cgi";

	_assignVec( http.version, strVersion, CNT_VERSION );
	_assignVec( http.method, strMethod, CNT_METHOD );

	_assignHeader();
	_assignStatus();
	_assignMime();
}

void
HTTP::_assignHeader( void ) {
	str_t	header;

	File fileIn( fileHeaderIn, R );
	while ( std::getline( fileIn.fs, header ) )
		key.header_in.push_back( header );

	File fileOut( fileHeaderOut, R );
	while ( std::getline( fileOut.fs, header ) )
		key.header_out.push_back( header );
}

void
HTTP::_assignStatus( void ) {
	File file( fileStatus, R );

	while ( !file.fs.eof() ) {
		uint_t	code;
		str_t	reason;

		file.fs >> code;
		file.fs.get();
		std::getline( file.fs, reason );

		key.status.insert( std::make_pair( code, reason ) );
	}
}

void
HTTP::_assignMime( void ) {
	File	file( fileMime, R );
	str_t	type, exts, ext;

	while ( !file.fs.eof() ) {
		file.fs >> type;
		
		std::getline( file.fs, exts, ';' );
		isstream_t	iss( exts );
		while ( iss >> ext )
			key.mime.insert( std::make_pair( ext, type ) );
	}
}

void
HTTP::_assignVec( vec_str_t& target, const str_t source[], size_t cnt ) {
	for ( size_t idx = 0; idx < cnt; ++idx )
		target.push_back( source[idx] );
}



/* METHOD - getLocationConf: get index of vec_config_t matching with request URI */
size_t
HTTP::getLocationConf( const str_t& uri, const vec_config_t& config ) {
	if ( config.size() > 1 ) {
		size_t idx = 1;
		for ( vec_config_t::const_iterator iter = config.begin(); iter != config.end(); ++iter ) {
			if ( uri.find( iter->location ) == 0 )
				return idx;
			++idx;
		}
	}
	return 0;
}



/* FILTER INIT */
errstat_s::errstat_s( const uint_t& status ) {
	code = status;
}

config_s::config_s( void ) {
	location		= "/";
	root			= "./html";
	file40x			= "./html/40x.html";
	file40x			= "./html/50x.html";

	atidx			= FALSE;
	sizeBodyMax		= 1000;
	 
	allow.insert( std::make_pair( GET, TRUE ) );
	allow.insert( std::make_pair( POST, TRUE ) );
	allow.insert( std::make_pair( DELETE, TRUE ) );
}

request_header_s::request_header_s( void ) {
	connection		= KEEP_ALIVE;
	chunked			= FALSE;
	content_length	= 0;
}

response_line_s::response_line_s( void ) {
	version			= VERSION_11;
	status			= 200;
}

response_header_s::response_header_s( void ) {
	connection		= KEEP_ALIVE;
	chunked			= FALSE;
	content_length	= 0;
}


char*
dupIOBuf( std::ios& obj, size_t& size ) {
	std::streambuf* pbuf = obj.rdbuf();
	size = pbuf->pubseekoff( 0, obj.end, obj.in );
	pbuf->pubseekpos( 0, obj.in );

	char *buf = new char[size];
	pbuf->sgetn( buf, size );
	
	return buf;
}

#include "HTTP.hpp"

http_t HTTP::http;
keys_t HTTP::key;

/* METHOD - init: assign basic HTTP info and load keys */
void
HTTP::init( void ) {
	http.signature			= "HTTP";
	http.type_unknown		= "text/plain";

	_assignVec( http.version, str_version, CNT_VERSION );
	_assignVec( http.method, str_method, CNT_METHOD );
	_assignVec( http.encoding, str_transfer_enc, CNT_ENCODING );

	_assignHeader();
	_assignStatus();
	_assignMime();
}

void
HTTP::_assignHeader( void ) {
	str_t header;

	File fileIn( file_header_in, READ );
	while ( std::getline( fileIn.fs, header ) )
		key.header_in.push_back( header );

	File fileOut( file_header_out, READ );
	while ( std::getline( fileOut.fs, header ) ) key.header_out.push_back( header );
}

void
HTTP::_assignStatus( void ) {
	File file( file_status, READ );

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
HTTP::_assignMime(void) {
	File	file( file_mime, READ );
	str_t	type, exts, ext;

	while ( !file.fs.eof() ) {
		file.fs >> type;

		std::getline( file.fs, exts, ';' );
		isstream_t iss( exts );
		while ( iss >> ext ) key.mime.insert( std::make_pair( ext, type ) );
	}
}

void
HTTP::_assignVec( vec_str_t& target, const str_t source[], size_t cnt ) {
	for ( size_t idx = 0; idx < cnt; ++idx )
		target.push_back(source[idx]);
}

/* METHOD - getLocationConf: get index for location_t matching with request URI */
size_t
HTTP::setLocation( const str_t& uri, const vec_location_t& locations ) {
	if ( locations.size() > 1 ) {
		vec_location_t::const_iterator	iter	= locations.begin() + 1;
		size_t							idx		= 1;

		while ( iter != locations.end() ) {
			if ( uri.find( iter->alias ) == 0 )
				return idx;
			++iter;
			++idx;
		}
	}
	return 0;
}

/* STURCT */
config_s::config_s( void ) {
	name			= "webserv";
	listen			= 8080; // mandatory
	
	root			= "html"; // mandatory

	client_max_body	= 10240; // 10M
	// client_max_body	= 10;

	/*
		The root configuration (i.e. location for "/") could be set or not and
		either case the location conf for the root MUST exist. It works as the 
		default.
	*/
	locations.push_back( location_s( *this ) );
	
	// add location for cgi-bin 
	location_s cgi_bin( *this );

	cgi_bin.alias = "/bin";
	cgi_bin.root += "/cgi-bin";

	cgi_bin.allow.push_back( GET );
	cgi_bin.allow.push_back( POST );
	cgi_bin.allow.push_back( DELETE );

	cgi_bin.index.push_back( "index.txt" );
	cgi_bin.index_auto = TRUE;
	// cgi_bin.index_auto = FALSE;

	locations.push_back( cgi_bin );
}

location_s::location_s( const config_s& serverconf ) {
	alias			= "/"; // mandatory
	root			= serverconf.root; // mandatory

	// allow > may should be removed later ( since using the conf file )
	allow.push_back( GET );
	allow.push_back( POST );
	allow.push_back( DELETE );	

	// index_auto		= FALSE;
	index_auto		= TRUE;

	index.push_back( "index.html" );
}

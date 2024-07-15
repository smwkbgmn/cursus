#include "HTTP.hpp"

void
HTTP::GET( const path_t& uri, sstream_t& body, size_t& size ) {
	try {
		File target( uri, READ_BINARY );
		
		body << target.fs.rdbuf();
		size = streamsize( body );
	}

	catch ( exception_t& exc ) {
		log( "HTTP\t: " + str_t( exc.what() ) );
		throw errstat_t( 500 );
	}
}
 
void
HTTP::POST( const Request& rqst ) {
	try {
		File target( rqst.line().uri, WRITE_APP );

		target.fs << rqst.body().str();
	}
	
	catch ( exception_t& exc ) {
		log( "HTTP\t: " + str_t( exc.what() ) );
		throw errstat_t( 500 );
	}
}

void
HTTP::DELETE( const Request& rqst ) {
	if ( std::remove( rqst.line().uri.c_str() ) == ERROR )
		throwSysErr( "remove", 500 );
}

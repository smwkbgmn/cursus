#include "webserv.hpp"

/*
	- Chunked request/response
	- Vary responses when fail to do method or incorrect message
	- CGI > sorting (script), RPN calculator (execute)
	- autoindex > print list of file
	- Redirecttion
*/

int main( void ) {	
	try {
		Server	server;
		
		// Retrieve http signature and default type from config file
		HTTP::init( "text/plain", "/cgi-bin" );
		server.listening();
	} catch ( err_t &err ) { std::cerr << err.what() << std::endl; }

	return 0;
}
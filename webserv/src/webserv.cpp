#include "webserv.hpp"

int main( void ) {	
	try {
		Server	server;
		
		HTTP::init( "keyHeader", "keyStatus" );
		server.listening();
	} catch ( err_t &err ) { std::cerr << err.what() << std::endl; }

	return 0;
}
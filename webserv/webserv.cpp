#include "webserv.hpp"

int main( void ) {
	try {
		Server	server;
		
		server.listening();
	} catch ( err_t &err ) { std::cout << err.what() << std::endl; }

	return 0;
}
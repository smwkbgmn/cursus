#include "Server.hpp"

Server::Server( void ): ASocket() {}
Server::~Server( void ) { close( sock ); }

void Server::listening( void ) {
	if ( listen( sock, 10 ) == ERROR )
		throw err_t( "fail to listening" );		
		
	std::cout << "Listening on port 8080\n";

	while ( LOOP ) {
		try {
			Client	connection( sock );
			
			connection.receiving();
			connection.sending();
		} catch( err_t &err ) { std::clog << err.what() << std::endl; }
	}
}
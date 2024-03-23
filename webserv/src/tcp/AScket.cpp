#include "ASocket.hpp"

ASocket::ASocket( void ) {
	sock = socket( AF_INET, SOCK_STREAM, 0 );
	if ( sock == ERROR )
		throw err_t( "fail to create socket" );
	
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons( 8080 );

	if ( bind( sock, ( const struct sockaddr* )&addr, sizeof( addr ) ) == ERROR )
		throw err_t( "fail to bind" );
}

ASocket::ASocket( socket_t sockServer ) {
	addrSize = sizeof( addr );
	sock = accept( sockServer, ( struct sockaddr* )&addr, &addrSize );

	if ( sock == ERROR )
		throw err_t( "fail to accepting connection" );
}

ASocket::~ASocket( void ) {}
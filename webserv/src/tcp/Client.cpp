#include "Client.hpp"

Client::Client( socket_t sockServer ): ASocket( sockServer ) {}
Client::~Client( void ) { close( sock ); }

void Client::receiving( void ) { 
	char	buf[1024] = { 0 };
	ssize_t	bytesRead = read( sock, buf, sizeof( buf ) );
	
	if ( bytesRead == ERROR ) 
		throw err_t( "fail to read from socket" );

	std::cout << "Received request:\n" << buf << std::endl;
}

void Client::sending( void ) {
	const char*	response	= "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello, World!";
	ssize_t		bytesSent	= send( sock, response, strlen( response ), 0 );

	if ( bytesSent == ERROR )
		throw err_t( "fail to send response" );
}
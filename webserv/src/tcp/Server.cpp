#include "Server.hpp"

Server::Server( void ) {
	sock = socket( AF_INET, SOCK_STREAM, 0 );
	if ( sock == ERROR )
		throw err_t( "fail to create socket" );
	
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons( 8080 );

	if ( bind( sock, ( const struct sockaddr* )&addr, sizeof( addr ) ) == ERROR ) {
		std::cout << "errno: " << errno << std::endl;
		perror( "bind" );
		close( sock );
		throw err_t( "fail to bind" );
	}

	std::cout << "Listening on port 8080\n";
}

Server::~Server( void ) { close( sock ); }

void Server::listening( void ) {
	if ( listen( sock, 10 ) == ERROR ) {
		close( sock );
		throw err_t( "fail to binding" );
	}

	while ( LOOP ) {
		try {
			Client	connection;
			
			connection.receiving();
			connection.sending();
		} catch( err_t &err ) { std::clog << err.what() << std::endl; }

		// struct sockaddr_in	clientAddr;
		// socklen_t	clientAddrSize	= sizeof( clientAddr );
		// socket_t	clientSock		= accept( sock, (struct sockaddr* )&clientAddr, &clientAddrSize );
		
		// if ( clientSock == ERROR ) {
		// 	std::cout << "fail to accepting connection\n";
		// 	continue;
		// }
		
		// // READ REQUEST
		// char	buf[1024] = {0};
		// ssize_t	bytesRead = read( clientSock, buf, sizeof( buf ) );
		
		// if ( bytesRead == ERROR ) {
		// 	std::cout << "fail to read from socket\n";
		// 	continue;
		// }
		// std::cout << "Received request:\n" << buf << std::endl;

		// // SEND RESPONSE
		// const char*	response	= "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello, World!";
		// ssize_t		bytesSent	= send( clientSock, response, strlen( response ), 0 );

		// if ( bytesSent == ERROR )
		// 	std::cout << "fail to send response\n";
		
		// close( clientSock );
	}
}
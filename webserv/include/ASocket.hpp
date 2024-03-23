#ifndef TCP_HPP
# define TCP_HPP

# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>

# include <cstring>
# include <stdio.h>

# include "structure.hpp"
# include "error.hpp"

# define LOOP 1

/*
	[TCP functions using UNIX]
	socketpair
	htons
	htonl
	nthos
	ntohl

	select / poll / epoll / kqueue
	socket
	accept
	listen
	
	send
	recv
	
	bind
	connect
	
	getaddrinfo
	freeaddrinfo

	setsockpot
	getsockname
	getprotobyname
*/

class ASocket {
	public:
		struct sockaddr_in	addr;
		socklen_t			addrSize;
		socket_t			sock;

		ASocket( void );
		ASocket( socket_t );
		virtual ~ASocket( void ) = 0;
};

#endif
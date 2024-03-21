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


#endif
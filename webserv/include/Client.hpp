#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "tcp.hpp"

class Client {
	public:
		struct sockaddr_in	addr;
		socklen_t			addrSize;
		socket_t			sock;

		Client( void );
		~Client( void );

		void	receiving( void );
		void	sending( void );
		
	private:
	
	
};

#endif
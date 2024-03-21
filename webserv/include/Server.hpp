#ifndef SERVER_HPP
# define SERVER_HPP

# include "Client.hpp"

class Server {
	public:
		struct sockaddr_in	addr;
		socket_t			sock;

		Server( void );
		~Server( void );

		void	listening( void );

	private:
};

#endif
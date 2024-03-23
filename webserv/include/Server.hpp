#ifndef SERVER_HPP
# define SERVER_HPP

# include "ASocket.hpp"
# include "Client.hpp"

class Server: ASocket {
	public:
		Server( void );
		~Server( void );

		void	listening( void );

	private:
		Server( socket_t );
};

#endif
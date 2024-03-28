#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "ASocket.hpp"
# include "Server.hpp"

class Client: ASocket {
	public:
		Client( socket_t );
		~Client( void );

		void	receiving( void );
		void	sending( void );
		
	private:
		Client( void );
};

#endif
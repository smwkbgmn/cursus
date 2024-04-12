#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "ASocket.hpp"
# include "Server.hpp"

class Client: ASocket {
	public:
		const char*	buf;
		
		Client( socket_t, const Server& );
		~Client( void );

		socket_t		socket( void ) const { return sock; }
		const Server&	server( void ) const { return _server; }

		void		receiving( void );
		void		sending( void );
		
	private:
	 	const Server&	_server;
		Client( void );
};

#endif
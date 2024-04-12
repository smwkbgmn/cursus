#ifndef SERVER_HPP
# define SERVER_HPP

# include "ASocket.hpp"

class Server: ASocket {
	public:
		vec_config_t	cnf;
	
		Server( void );
		~Server( void );

		void	listening( void );

		const vec_config_t&	config( void ) const { return cnf; }

	private:
		Server( socket_t );
};

# include "Client.hpp"

#endif
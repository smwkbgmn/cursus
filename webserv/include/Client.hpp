#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "ATCP.hpp"
# include "Server.hpp"

class Client: public TCP {
	public:
		Client( socket_t );
		~Client( void );

		void	receiving( void );
		void	sending( void );
		
	private:
		Client( void );
};

#endif
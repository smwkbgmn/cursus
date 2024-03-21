#ifndef SERVER_HPP
# define SERVER_HPP

# include "ATCP.hpp"
# include "Client.hpp"

class Server: public TCP {
	public:
		Server( void );
		~Server( void );

		void	listening( void );

	private:
		Server( socket_t );
};

#endif
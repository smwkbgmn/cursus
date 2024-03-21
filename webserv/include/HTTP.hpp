#ifndef HTTP_HPP
# define HTTP_HPP

# include "Transaction.hpp"

/*
	[Any HTTP method and resources]
	redirection
*/

class HTTP {
	public:
		static void	respone( Transaction&, socket_t );
	
	private:
		static void	_method( Transaction& );

};

#endif
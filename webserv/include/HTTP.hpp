#ifndef HTTP_HPP
# define HTTP_HPP

# include "Transaction.hpp"

/*
	[Any HTTP method and resources]
	redirection
*/

# define OPTIONS 3

enum methodIdx {
	GET,
	POST,
	DELETE
};

const str_t	methodName[OPTIONS] = {
	"GET",
	"POST",
	"DELETE"
};

class HTTP {
	public:
		static void	response( Transaction&, socket_t );
	
	private:
		static void	_method( Transaction& );

};

#endif
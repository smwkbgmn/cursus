#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>

# include <exception>
# include <string>

// Container
# include <stack>

// Validation
# include <locale>

typedef std::string			str_t;
typedef std::istringstream	isstream_t;
typedef std::stack<int>		stack_int_t;
typedef std::runtime_error	err_t;

const str_t	errPrfx = "error: ";

class RPN
{
	public:
		static int	calculate( const str_t& );

	private:
		RPN( void );
		RPN( const RPN & );
		~RPN( void );

		static void	operate( stack_int_t&, char );
		static void throwBadInput( isstream_t& );

		RPN	&operator=( const RPN & );
};

#endif
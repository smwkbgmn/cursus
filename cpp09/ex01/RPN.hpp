#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>

# include <string>s
# include <exception>

// Container
# include <stack>

// Validation
# include <locale>

typedef std::string			str_t;
typedef std::istringstream	isstream_t;
typedef std::stack<int>		value_t;
typedef std::runtime_error	err_t;

const str_t	errPrfx = "error: ";
const str_t errMsg[] = {
	errPrfx + "not found any value. please enter values for operation.",
	errPrfx + "unoperated value has left",
	errPrfx + "may not divide by 0",
	errPrfx + "ensure the form of input does meet requirement",
	errPrfx + "only arithemetic operations are allowed (+, -, *, /)",
	errPrfx + "fail to get a character",
	errPrfx + "fail to get two value for operation"
};

enum Msg {
	EMPTY_VAL,
	LEFT_VAL,
	DVIDE_ZERO,
	INVALID_INPUT,
	INVALID_OPER,
	FAIL_GET_CHR,
	FAIL_GET_VAL
};

class RPN {
	public:
		static int	calculate( const str_t& );

	private:
		RPN( void );
		RPN( const RPN & );
		~RPN( void );

		static void	_proceed( isstream_t&, value_t& );
		static void	_operate( value_t&, char );
		static void _throwBadInput( isstream_t& );
		static void	_throwBadArg( size_t );

		RPN	&operator=( const RPN & );
};

#endif
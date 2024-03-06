#include "RPN.hpp"

/*
	- Only one value input: "1"
	- Whether allow the trailing spacese or not
		> if may be the spaces at the tail,
		do extract spaces again at the end of while loop

		iss >> std::ws
		while { iss >> c .... iss >> std::ws }
*/

/* METHOD */
int RPN::calculate( const str_t& input ) {
	isstream_t		iss( input );
	stack_int_t		stackVal;

	while ( !iss.eof() ) {
		char	c;
		iss >> std::ws >> c;

		throwBadInput( iss );
		if ( std::isdigit( c ) ) 
			stackVal.push( c - '0' );
		else
			operate( stackVal, c );
	}

	if ( stackVal.size() != 1 )
		throw err_t( errPrfx + "unoperated value has left" );

	return stackVal.top();
}

void RPN::throwBadInput( isstream_t& iss ) {
	if ( iss.fail() )
		throw err_t( errPrfx + "fail to get a character" );

	if ( iss.peek() != ' ' && !iss.eof() )
		throw err_t( errPrfx + "ensure the form of input does meet requirement" );
}

void RPN::operate( stack_int_t& stackVal, char operation ) {
	if ( stackVal.size() < 2 )
		throw err_t( errPrfx + "fail to get two value for operation" );

	int	rval = stackVal.top();
	stackVal.pop();

	switch ( operation ) {
		case '+': stackVal.top() += rval; break;
		case '-': stackVal.top() -= rval; break;
		case '*': stackVal.top() *= rval; break;
		case '/':
			if ( !rval )
				throw err_t( errPrfx + "may not divide by 0");
			stackVal.top() /= rval; break;
		default: throw err_t( errPrfx + "only arithemetic operations are allowed (+, -, *, /)");
	}
}


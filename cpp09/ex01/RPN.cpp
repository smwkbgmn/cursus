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
	isstream_t	iss( input );
	value_t		val;

	while ( !iss.eof() )
		proceedOne( iss, val );

	if ( val.size() != 1 )
		throw err_t( errPrfx + "unoperated value has left" );

	return val.top();
}

void RPN::proceedOne( isstream_t& iss, value_t& val ) {
	char	c;

	iss >> std::ws >> c;
	throwBadInput( iss );

	if ( std::isdigit( c ) ) 
		val.push( c - '0' );
	else
		operate( val, c );
}

void RPN::operate( value_t& val, char operation ) {
	if ( val.size() < 2 )
		throw err_t( errPrfx + "fail to get value for operation" );

	int	rval = val.top();
	val.pop();

	switch ( operation ) {
		case '+': val.top() += rval; break;
		case '-': val.top() -= rval; break;
		case '*': val.top() *= rval; break;
		case '/':
			if ( !rval )
				throw err_t( errPrfx + "may not divide by 0");
			val.top() /= rval; break;
		default: throw err_t( errPrfx + "only arithemetic operations are allowed (+, -, *, /)");
	}
}

void RPN::throwBadInput( isstream_t& iss ) {
	if ( iss.fail() )
		throw err_t( errPrfx + "fail to get a character" );

	if ( iss.peek() != ' ' && !iss.eof() )
		throw err_t( errPrfx + "ensure the form of input does meet requirement" );
}
#include "RPN.hpp"

/*
	- Only one value input: "1"
	- Whether allow the trailing spacese or not
		> if may be the spaces at the tail,
		do extract spaces again at the end of while loop

		iss >> std::ws
		while { iss >> c .... iss >> std::ws }
	- 5 5 5 5 + + 5 5 - - - > -10
*/

/* METHOD */
int RPN::calculate( const str_t& input ) {
	isstream_t	iss( input );
	value_t		val;

	while ( !iss.eof() )
		proceedOne( iss, val );

	if ( val.size() != 1 )
		throw err_t( errMsg[LEFT_VAL] );

	return val.top();
}

void RPN::proceedOne( isstream_t& iss, value_t& val ) {
	char	ch;

	iss >> std::ws >> ch;
	throwBadInput( iss );

	if ( std::isdigit( ch ) ) 
		val.push( ch - '0' );
	else
		operate( val, ch );
}

void RPN::operate( value_t& val, char operation ) {
	if ( val.size() < 2 )
		throw err_t( errMsg[FAIL_GET_VAL] );

	int	rval = val.top();
	val.pop();

	switch ( operation ) {
		case '+': val.top() += rval; break;
		case '-': val.top() -= rval; break;
		case '*': val.top() *= rval; break;
		case '/':
			if ( !rval )
				throw err_t( errMsg[DVIDE_ZERO] );
			val.top() /= rval; break;
		default: throw err_t( errMsg[INVALID_OPER] );
	}
}

void RPN::throwBadInput( isstream_t& iss ) {
	if ( iss.fail() )
		throw err_t( errMsg[FAIL_GET_CHR] );

	if ( iss.peek() != ' ' && !iss.eof() )
		throw err_t( errMsg[INVALID_INPUT] );
}
#include "RPN.hpp"

/* METHOD */
int RPN::calculate( const str_t& input ) {
	isstream_t	iss( input );
	stack_int_t		val;

	iss >> std::ws;
	while ( !iss.eof() ) {
		_proceed( iss, val );
		iss >> std::ws;
	}

	_throwBadValue( val.size() );
	return val.top();
}

void RPN::_proceed( isstream_t& iss, stack_int_t& val ) {
	char	chr;
	
	iss >> chr;
	_throwBadInput( iss );

	if ( std::isdigit( chr ) ) 
		val.push( chr - '0' );
	else if ( arithemetic.find( chr ) != str_t::npos )
		_operate( val, chr );
	else
		throw err_t( errMsg[INVALID_OPER] );
}

void RPN::_operate( stack_int_t& val, char operation ) {
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
	}
}

void RPN::_throwBadInput( isstream_t& iss ) {
	if ( iss.fail() )
		throw err_t( errMsg[FAIL_GET_CHR] );

	if ( iss.peek() != ' ' && !iss.eof() )
		throw err_t( errMsg[INVALID_INPUT] );
}

void RPN::_throwBadValue( size_t size ) {
	if ( size == 0 )
		throw err_t( errMsg[EMPTY_VAL] );
	
	if ( size > 1 )
		throw err_t( errMsg[LEFT_VAL] );
}

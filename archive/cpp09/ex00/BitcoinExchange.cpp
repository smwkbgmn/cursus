#include "BitcoinExchange.hpp"

/* INSTANTIATE */
BitcoinExchange::BitcoinExchange( const str_t& nameData ) {
	_getData( nameData );
	
	std::clog << "[CON-USR] BitcoinExchange has created" << std::endl;
}

BitcoinExchange::~BitcoinExchange( void ) {
	std::clog << "[DES] BitcoinExchange has destroyed" << std::endl;
}

/* METHOD */
void BitcoinExchange::_getData( const str_t& nameData ) {
		File	data( nameData, R );
		str_t	line;
		
		if ( std::getline( data.fs, line ) && line == headData )
			while ( std::getline( data.fs, line ) ) {
				if ( !line.empty() )
					_insertData( line );
			}
		else
			throw err_t( errMsg[FAIL_RD_DATA] );
}

void BitcoinExchange::_insertData( const str_t& line ) {
	isstream_t	iss( line );

	_rate.insert( std::make_pair( _getDate( iss, DATA ), _getValue( iss, DATA ) ) );
}

void BitcoinExchange::outResult( const str_t& nameInput ) const {
		File	input( nameInput, R );
		str_t	line;

		if ( std::getline( input.fs, line ) && line == headInput )
			while ( std::getline( input.fs, line ) ) {
				if ( !line.empty() )
					_printResult( line );
			}
		else
			throw err_t( errMsg[FAIL_RD_INPUT] );
}

void BitcoinExchange::_printResult( const str_t& line ) const {
	try {
		isstream_t				iss( line );

		Date					key		= _getDate( iss, INPUT );
		float					value	= _getValue( iss, INPUT );
		map_t::const_iterator	rate	= _rate.lower_bound( key );

		if ( rate == _rate.end() )
			throw err_t( errMsg[NO_DATA] );

		std::cout << key << " => " << value << " = " << value * rate->second << std::endl;
	} catch ( err_t& err ) { std::cerr << err.what() << std::endl; }
}

Date BitcoinExchange::_getDate( isstream_t& iss, FileType type ) const {
	str_t	substr;
	
	switch ( type ) {
		case DATA: if ( std::getline( iss, substr, ',' ) ) return Date( substr );
			break;
		case INPUT: if ( std::getline( iss, substr, '|' ) ) return Date( substr );
			break;
	}

	throw Date::invalidDateExcpt();
}

float BitcoinExchange::_getValue( isstream_t& iss, FileType type ) const {
	float	val;

	iss >> val;
	if ( !_success( iss ) )
		throw err_t( errMsg[FAIL_GET_VAL] );

	if ( type == INPUT )
		_throwInvalidValue( val );

	return val;
}

void BitcoinExchange::_throwInvalidValue( float rate ) const {
	if ( rate < 0 || rate > 1000 )
		throw err_t( errMsg[OUT_OF_RANGE] );
}

bool BitcoinExchange::_success( const isstream_t& iss ) const {
	return iss.eof() && !iss.fail();
}

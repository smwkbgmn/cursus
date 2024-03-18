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
		file_s	fileData( nameData );
		str_t	line;
		
		if ( std::getline( fileData.in, line ) && line == headData )
			while ( std::getline( fileData.in, line ) ) {
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
		file_s	fileInput( nameInput );
		str_t	line;

		if ( std::getline( fileInput.in, line ) && line == headInput )
			while ( std::getline( fileInput.in, line ) ) {
				if ( !line.empty() )
					_printResult( line );
			}
		else
			throw err_t( errMsg[FAIL_RD_INPUT] );
}

void BitcoinExchange::_printResult( const str_t& line ) const {
	try {
		isstream_t				iss( line );

		date_s					key		= _getDate( iss, INPUT );
		float					value	= _getValue( iss, INPUT );
		map_t::const_iterator	rate	= _rate.lower_bound( key );

		if ( rate == _rate.end() )
			throw err_t( errMsg[NO_DATA] );

		key.print();
		std::cout << " => " << value << " = " << value * rate->second << std::endl;
	} catch ( err_t& err ) { std::cerr << err.what() << std::endl; }
}

BitcoinExchange::date_s BitcoinExchange::_getDate( isstream_t& iss, FileType type ) const {
	str_t	strDate;
	
	switch ( type ) {
		case DATA: if ( std::getline( iss, strDate, ',' ) ) return date_s( strDate );
			break;
		case INPUT: if ( std::getline( iss, strDate, '|' ) ) return date_s( strDate );
			break;
	}

	throw invalidDateExcpt();
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

bool BitcoinExchange::_success( const isstream_t& iss ) {
	return iss.eof() && !iss.fail();
}

/* STRUCT - FileStream */
BitcoinExchange::FileStream::FileStream( const str_t& fileName ) {
	in.open( fileName.c_str() );

	if ( !in.is_open() )
		throw std::ios_base::failure( errMsg[FAIL_OPN_FILE] + fileName );
}

BitcoinExchange::FileStream::~FileStream( void ) { in.close(); }

/* STRUCT - Date */
BitcoinExchange::Date::Date( const str_t& input ): date( 0 ) { convert( input ); }

void BitcoinExchange::Date::convert( const str_t& input ) {
	isstream_t	iss( input );
	str_t		substr;

	for ( int id = 0; id < 3; ++id ) {
		if ( !std::getline( iss, substr, '-' ) && id < 2 )
			throw invalidDateExcpt();

		// Remove trailing spaces
		if ( id == D )
			while ( *substr.rbegin() == ' ' )
				substr.erase( substr.size() - 1 );

		throwInvalidForm( substr, id );
		date = date | toBits( substr, id );
	}

	if ( !iss.eof() || !validDay() )
		throw invalidDateExcpt();
}

BitcoinExchange::Date::bits_t BitcoinExchange::Date::toBits( const str_t& substr, int id ) const {
	isstream_t	iss( substr );
	bits_t		val;

	iss >> val;
	if ( !_success(iss) )
		throw invalidDateExcpt();

	return padBits( val, id );
}

BitcoinExchange::Date::bits_t BitcoinExchange::Date::padBits( bits_t val, int id ) const {
	switch ( id ) {
		case Y:
			throwInvalidValue( val, 1, 9999 );
			return val << PAD_Y;
		case M:
			throwInvalidValue( val, 1, 12 );
			return val << PAD_M;
		case D:
			throwInvalidValue( val, 1, 31 );
			return val << PAD_D;
	}
	return NONE;
}

bool BitcoinExchange::Date::validDay( void ) const {
	bits_t	val[3];

	val[Y] = date >> PAD_Y & HLD_Y;
	val[M] = date >> PAD_M & HLD_M;
	val[D] = date >> PAD_D & HLD_D;

	if ( val[D] > monthDays[val[M] - 1] )
		if ( !yearLeap(val[Y]) || val[D] > 29 )
			return FALSE;
	
	return TRUE;
}

bool BitcoinExchange::Date::yearLeap( bits_t year ) const {
	return year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 );
}

void BitcoinExchange::Date::print( void ) const {
	std::cout << std::setw( 4 ) << std::setfill( '0' ) << ( date >> PAD_Y & HLD_Y ) << '-';
	std::cout << std::setw( 2 ) << std::setfill( '0' ) << ( date >> PAD_M & HLD_M ) << '-';
	std::cout << std::setw( 2 ) << std::setfill( '0' ) << ( date >> PAD_D & HLD_D );
}

void BitcoinExchange::Date::throwInvalidForm( const str_t& substr, int id ) const {
	// May not use sign character at date
	if ( !std::isdigit( *substr.begin() ) )
		throw invalidDateExcpt();

	switch ( id ) {
		case Y: if ( substr.size() != 4 ) throw invalidDateExcpt(); break;
		case M: if ( substr.size() != 2 ) throw invalidDateExcpt(); break;
		case D: if ( substr.size() != 2 ) throw invalidDateExcpt(); break;
	}
}

void BitcoinExchange::Date::throwInvalidValue( bits_t val, unsigned int min, unsigned int max ) const {
	if ( val < min || val > max )
		throw invalidDateExcpt();
}

bool BitcoinExchange::Date::operator<( const Date& target ) const {
	return date > target.date;
}

/* STRUCT - Exceptions */
BitcoinExchange::invalidDateExcpt::invalidDateExcpt( void ): err_t( errPrfx + "fail to get a date" ) {}

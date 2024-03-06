#include "BitcoinExchange.hpp"

/* INSTANTIATE */
BitcoinExchange::BitcoinExchange( const str_t& nameData ) {
	getData( nameData );
	
	std::clog << "[CON-USR] BitcoinExchange has created" << std::endl;
}

BitcoinExchange::~BitcoinExchange( void ) {
	std::clog << "[DES] BitcoinExchange has destroyed" << std::endl;
}

/* METHOD */
void BitcoinExchange::getData( const str_t& nameData ) {
		file_s	fileData( nameData );
		str_t	line;

		if ( std::getline( fileData._in, line ) )
			while ( std::getline( fileData._in, line ) )
				insertData( isstream_t( line ) );
		else
			throw err_t( errPrfx + "fail to read data" );
}

void BitcoinExchange::insertData( isstream_t iss ) {
	_rate.insert( std::make_pair( getDate( iss, DATA ), getValue( iss, DATA ) ) );
}

void BitcoinExchange::outResult( const str_t& nameInput ) const {
		file_s	fileInput( nameInput );
		str_t	line;

		if ( std::getline( fileInput._in, line ) && line == headInput )
			while ( std::getline( fileInput._in, line ) )
				printResult( isstream_t( line ) );
		else
			throw err_t( errPrfx + "fail to read input" );
}

void BitcoinExchange::printResult( isstream_t iss ) const {
	try {
		date_s					key = getDate( iss, INPUT );
		float					value = getValue( iss, INPUT );
		data_t::const_iterator	rate = _rate.lower_bound( key );

		if ( rate == _rate.end() )
			throw err_t( errPrfx + "data has not found" );

		key.print();
		std::cout << " => " << value << " = " << value * rate->second << std::endl;

	} catch ( err_t& err ) { std::cerr << err.what() << std::endl; }
}

BitcoinExchange::date_s BitcoinExchange::getDate( isstream_t& iss, FileType type ) const {
	str_t	strDate;
	
	switch ( type ) {
		case DATA:
			if ( std::getline( iss, strDate, ',' ) )
				return date_s( strDate );
		case INPUT:
			if ( std::getline( iss, strDate, '|' ) )
				return date_s( strDate );
	}

	throw invalidDateExcpt();
}

float BitcoinExchange::getValue( isstream_t& iss, FileType type ) const {
	float	val;

	iss >> val;
	if ( !success( iss ) )
		throw err_t( errPrfx + "fail to get a value" );

	if ( type == INPUT )
		throwInvalidValue( val );

	return val;
}

void BitcoinExchange::throwInvalidValue( float rate ) const {
	if ( rate < 0 || rate > 1000 )
		throw err_t( errPrfx + "the value is out of range" );
}

bool BitcoinExchange::success( const isstream_t& iss ) {
	return iss.eof() && !iss.fail();
}

/* STRUCT - FileStream */
BitcoinExchange::FileStream::FileStream( const str_t& fileName ) {
	_in.open( fileName );

	if ( !_in.is_open() )
		throw std::ios_base::failure( errPrfx + "fail to open file " + fileName );
}

BitcoinExchange::FileStream::~FileStream( void ) {
	_in.close();
}

/* STRUCT - Date */
BitcoinExchange::Date::Date( const str_t& input ): _date( 0 ) {
	convert( input );
}

void BitcoinExchange::Date::convert( const str_t& input ) {
	isstream_t	iss( input );
	str_t		substr;

	for ( int id = 0; id < 3; ++id ) {
		if ( !std::getline( iss, substr, '-' ) && id < 2 )
			throw invalidDateExcpt();

		_date = _date | toBits( substr, id );
	}

	if ( !iss.eof() || !validDay() )
		throw invalidDateExcpt();
}

BitcoinExchange::Date::bits_t BitcoinExchange::Date::toBits( const str_t& input, int id ) const {
	isstream_t	iss ( input );
	bits_t		val = 0;

	// May not use sign character at date
	if ( !std::isdigit( *input.begin() ) )
		throw invalidDateExcpt();

	iss >> val;
	// Remove trail spaces
	if ( id == 2 && !iss.eof() )
		iss >> std::ws;

	if ( !success(iss) )
		throw invalidDateExcpt();

	return padBits( val, id );
}

BitcoinExchange::Date::bits_t BitcoinExchange::Date::padBits( bits_t val, int id ) const {
	switch ( id )
	{
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
	bits_t	date[3];

	date[Y] = _date >> PAD_Y & HLD_Y;
	date[M] = _date >> PAD_M & HLD_M;
	date[D] = _date >> PAD_D & HLD_D;

	if ( date[D] > monthDays[date[M] - 1] )
		if ( !yearLeap(date[Y]) || date[D] > 29 )
			return FALSE;
	
	return TRUE;
}

bool BitcoinExchange::Date::yearLeap( bits_t year ) const {
	return year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 );
}

void BitcoinExchange::Date::print( void ) const {
	std::cout << std::setw( 4 ) << std::setfill( '0' ) << ( _date >> PAD_Y & HLD_Y ) << '-';
	std::cout << std::setw( 2 ) << std::setfill( '0' ) << ( _date >> PAD_M & HLD_M ) << '-';
	std::cout << std::setw( 2 ) << std::setfill( '0' ) << ( _date >> PAD_D & HLD_D );
}

void BitcoinExchange::Date::throwInvalidValue( bits_t val, unsigned int min, unsigned int max ) const {
	if ( val < min || val > max )
		throw invalidDateExcpt();
}

bool BitcoinExchange::Date::operator<( const Date& target ) const {
	return _date > target._date;
}

/* STRUCT - Exceptions */
BitcoinExchange::invalidDateExcpt::invalidDateExcpt( void ): err_t( errPrfx + "fail to get a date" )
{}

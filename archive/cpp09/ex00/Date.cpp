#include "Date.hpp"

/* INSTANTIATE */
Date::Date( void ): _date( 0 ) {}
Date::Date( const Date& target ) { *this = target; }
Date::Date( const str_t& input ): _date( 0 ) { _convert( input ); }
Date::~Date( void ) {}

/* METHOD */
void Date::_convert( const str_t& input ) {
	isstream_t	iss( input );
	str_t		substr;

	for ( int id = 0; id < 3; ++id ) {
		if ( !std::getline( iss, substr, '-' ) && id < 2 )
			throw invalidDateExcpt();

		// Remove trailing spaces
		if ( id == D )
			while ( *substr.rbegin() == ' ' )
				substr.erase( substr.size() - 1 );

		_throwInvalidForm( substr, id );
		_date = _date | _toBits( substr, id );
	}

	if ( !iss.eof() || !_validDay() )
		throw invalidDateExcpt();
}

bits_t Date::_toBits( const str_t& substr, int id ) const {
	isstream_t	iss( substr );
	bits_t		val;

	iss >> val;
	if ( !_success( iss ) )
		throw invalidDateExcpt();

	return _padBits( val, id );
}

bits_t Date::_padBits( bits_t val, int id ) const {
	switch ( id ) {
		case Y:
			_throwInvalidValue( val, 1, 9999 );
			return val << PAD_Y;
		case M:
			_throwInvalidValue( val, 1, 12 );
			return val << PAD_M;
		case D:
			_throwInvalidValue( val, 1, 31 );
			return val << PAD_D;
	}
	return NONE;
}

bool Date::_validDay( void ) const {
	bits_t	val[3];

	val[Y] = _date >> PAD_Y & HLD_Y;
	val[M] = _date >> PAD_M & HLD_M;
	val[D] = _date >> PAD_D & HLD_D;

	if ( val[D] > monthDays[val[M] - 1] )
		if ( !_yearLeap(val[Y]) || val[D] > 29 )
			return FALSE;
	
	return TRUE;
}

bool Date::_yearLeap( bits_t year ) const {
	return year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 );
}

bool Date::_success( const isstream_t& iss ) const {
	return iss.eof() && !iss.fail();
}

void Date::_throwInvalidForm( const str_t& substr, int id ) const {
	// May not use sign character at date
	if ( !std::isdigit( *substr.begin() ) )
		throw invalidDateExcpt();

	switch ( id ) {
		case Y: if ( substr.size() != 4 ) throw invalidDateExcpt(); break;
		case M: if ( substr.size() != 2 ) throw invalidDateExcpt(); break;
		case D: if ( substr.size() != 2 ) throw invalidDateExcpt(); break;
	}
}

void Date::_throwInvalidValue( bits_t val, unsigned int min, unsigned int max ) const {
	if ( val < min || val > max )
		throw invalidDateExcpt();
}

/* INTERFACE */
bits_t Date::year( void ) const { return _date >> PAD_Y & HLD_Y; }
bits_t Date::month( void ) const { return _date >> PAD_M & HLD_M; }
bits_t Date::day( void ) const { return _date >> PAD_D & HLD_D; }

Date& Date::operator=( const Date& target ) {
	if ( this != &target )
		_date = target._date;
	
	return *this;
}

bool Date::operator<( const Date& target ) const {
	return _date > target._date;
}

ostream_t& operator<<( ostream_t& os, const Date& date ) {
	os << std::setw( 4 ) << std::setfill( '0' ) << date.year() << '-';
	os << std::setw( 2 ) << std::setfill( '0' ) << date.month() << '-';
	os << std::setw( 2 ) << std::setfill( '0' ) << date.day();
	return os;
}

/* STRUCT - EXCEPTION */
Date::invalidDateExcpt::invalidDateExcpt( void ): err_t( errPrfx + "fail to get a _date" ) {}
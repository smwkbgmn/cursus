#include "log.hpp"

const std::time_t	begin	= std::time( NULL );
File				logging( "log/" + logFname(), WRITE );

std::string
logFname( void ) {
	fstat_t	info;

	if ( stat( "log", &info ) == ERROR )
		mkdir( "log", 0755 );
		
	std::string	fname = strTime() + ".log";

	return fname;
}

std::string
strTime( void ) {
	std::time_t	now = std::time( NULL );

	char		buf[80];
	std::strftime( buf, sizeof( buf ), "%Y%m%d_%H%M%S", std::localtime( &now ) );
	
	return std::string( buf );
}

void
timestamp( void ) {
	std::time_t	now			= std::time( NULL );
	std::time_t	elapse		= now - begin;
	std::tm*	timeinfo	= std::localtime( &elapse );

	char buf[100];
	timeinfo->tm_hour -= 9;
	std::strftime( buf, 100, "[%H:%M:%S]", timeinfo );
	std::clog << buf << " ";
}

void
log( const str_t& msg ) {
	timestamp();
	std::clog << msg << std::endl;
}

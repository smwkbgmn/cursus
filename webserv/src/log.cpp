#include "log.hpp"
/* remotehost, timestamp, request-line, response-code, response-size */

File logfile( "log/" + logFname(), W );
// File logfile( logFname(), W );

std::string logFname( void ) {
	std::string	fname = strTime() + ".log";

	return fname;
}

std::string strTime( void ) {
	std::time_t	now = std::time( NULL );

	char		buf[80];
	std::strftime( buf, sizeof( buf ), "%Y%m%d_%H%M%S", std::localtime( &now ) );
	
	return std::string( buf );
}
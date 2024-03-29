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


//////////////// DEBUGGING ///////////////////

void
printVec( vec_str_t& target, const str_t title ) {
	 std::clog << title << std::endl;

	for ( vec_str_iter_t iter = target.begin(); iter != target.end(); ++iter )
		std::clog << *iter << std::endl;
}

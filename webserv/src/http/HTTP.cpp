#include "HTTP.hpp"

/*
	1. Client send request for connection by browser 
	2. Accept connection through socket(UNIX)
	3. Receve request
	4. Send response
*/

method_t	HTTP::method;
status_t	HTTP::status;

void init( const str_t& nameHeader, const str_t& nameStatus ) {
	File	header( nameHeader, R );
	File	status( nameStatus, R );

	
}

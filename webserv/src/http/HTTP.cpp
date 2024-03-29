#include "HTTP.hpp"

/*
	1. Client send request for connection by browser 
	2. Accept connection through socket(UNIX)
	3. Receve request
	4. Send response
*/

str_t		HTTP::http;
vec_str_t	HTTP::version;
vec_str_t	HTTP::method;
vec_str_t	HTTP::header_in;
vec_str_t	HTTP::header_out;
status_t	HTTP::status;
mime_t		HTTP::mime;

void
HTTP::init( void ) {
	http = "HTTP";
	_assignVec( version, strVersion, CNT_VERSION );
	_assignVec( method, strMethod, CNT_METHOD );
	_assignHeader();
	_assignStatus();
	_assignMime();

	printVec( header_in, "[header_in]" );
	std::clog << std::endl;

	printVec( header_out, "[header_out]" );
	std::clog << std::endl;

	std::clog << "[status]\n";
	for ( status_t::iterator iter = status.begin(); iter != status.end(); ++iter )
		std::clog << iter->first << ", " << iter->second << std::endl;
}

void
HTTP::_assignHeader( void ) {
	File	fileIn( nameHeaderIn, R );
	File	fileOut( nameHeaderOut, R );
	str_t	header;

	while ( std::getline( fileIn.fs, header ) )
		header_in.push_back( header );

	while ( std::getline( fileOut.fs, header ) )
		header_out.push_back( header );
}

void
HTTP::_assignStatus( void ) {
	File file( nameStatus, R );

	while ( !file.fs.eof() ) {
		uint_t	code;
		str_t	reason;

		file.fs >> code;
		file.fs.get();
		std::getline( file.fs, reason );

		status.insert( std::make_pair( code, reason ) );
	}
}

void
HTTP::_assignMime( void ) {
	File	file( nameMime, R );	
}

void
HTTP::_assignVec( vec_str_t& target, const str_t source[], size_t cnt ) {
	for ( size_t idx = 0; idx < cnt; ++idx )
		target.push_back( source[idx] );
}

void
HTTP::sending( const Client& client, const Request& rqst ) {
	Response	rspn( rqst );
	// const char*	response	= "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello, World!";
	// ssize_t		bytesSent	= send( sock, rspn, strlen( rspn ), 0 );
	ssize_t		bytesSent = send( client.sock, _toData( rspn ), rspn.header().content_length, 0 );

	if ( bytesSent == ERROR )
		throw err_t( "HTTP: send: " + errMsg[FAIL_SEND] );
}

const char*
HTTP::_toData( const Response& rspn ) {
	osstream_t	oss;

	oss << http << '/' << version.at( static_cast<size_t>( )
	oss << rspn.line().version


	return oss.str().c_str();
}

str_t
HTTP::GET( const str_t& uri ) {
	File	target( uri, R );
	str_t	data;

	target.fs >> data;
	return data;
}

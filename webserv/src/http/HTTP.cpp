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
HTTP::response( const Client& client, const Request& rqst ) {
	// const char*	response	= "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello, World!";
	// ssize_t		bytesSent	= send( sock, rspn, strlen( rspn ), 0 );
	Response	rspn( rqst );
	osstream_t	oss;
	_toData( rspn, oss );
	logfile.fs << oss.str() << std::endl;
	ssize_t		bytesSent = send( client.socket(), oss.str().c_str(), oss.str().size(), 0 );


	if ( bytesSent == ERROR )
		throw err_t( "http: send: " + errMsg[FAIL_SEND] );
}

void
HTTP::_toData( const Response& rspn, osstream_t& oss ) {
	oss << http << '/' << version.at( static_cast<size_t>( rspn.line().version ) ) << ' ';
	status_t::iterator iter = HTTP::status.find( rspn.line().status );
	oss << iter->first << " " << iter->second << CRLF;
	oss << "Content-Length: ";
	oss << rspn.header().content_length << CRLF;
	oss << CRLF;
	oss << rspn.body();
}

char*
HTTP::GET( const str_t& uri, size_t& size ) {
	File			target( dirRoot + uri, R );
	// Get pointer to associated buffer object
	std::filebuf*	pbuf = target.fs.rdbuf();
	// Get file size using buffer's member
	size = pbuf->pubseekoff( 0, target.fs.end, target.fs.in );
	pbuf->pubseekpos( 0, target.fs.in );

	// Allocate memory to contain file data
	char			*buf = new char[size];
	// Get file data
	pbuf->sgetn( buf, size );
	
	return buf;
}

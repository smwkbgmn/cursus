#include "HTTP.hpp"

str_t		HTTP::http;
vec_str_t	HTTP::version;
vec_str_t	HTTP::method;
vec_str_t	HTTP::header_in;
vec_str_t	HTTP::header_out;
status_t	HTTP::status;
mime_t		HTTP::mime;

/* METHOD - init*/

void
HTTP::init( void ) {
	http = "HTTP";
	_assignVec( version, strVersion, CNT_VERSION );
	_assignVec( method, strMethod, CNT_METHOD );
	_assignHeader();
	_assignStatus();
	_assignMime();
}

void
HTTP::_assignHeader( void ) {
	str_t	header;

	File fileIn( nameHeaderIn, R );
	while ( std::getline( fileIn.fs, header ) )
		header_in.push_back( header );

	File fileOut( nameHeaderOut, R );
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

/* METHOD - response */

void
HTTP::response( const Client& client, const Request& rqst ) {
	osstream_t oss;
	_message( Response( rqst ), oss );

	logfile.fs << oss.str() << std::endl;
	ssize_t bytesSent = send( client.socket(), oss.str().c_str(), oss.str().size(), 0 );

	if ( bytesSent == ERROR )
		throw err_t( "http: send: " + errMsg[FAIL_SEND] );
}

void
HTTP::_message( const Response& rspn, osstream_t& oss ) {
	_msgLine( rspn, oss );
	_msgHeader( rspn, oss );
	_msgBody( rspn, oss );
}

void
HTTP::_msgLine( const Response& rspn, osstream_t& oss ) {
	status_t::iterator iter = HTTP::status.find( rspn.line().status );

	oss <<
	http << '/' << version.at( static_cast<size_t>( rspn.line().version ) ) << ' ' <<
	iter->first << " " << iter->second <<
	CRLF;
}

void HTTP::_msgHeader( const Response& rspn, osstream_t& oss ) {
	oss << 
	"Content-Length: " << rspn.header().content_length << CRLF <<
	CRLF;
}

void HTTP::_msgBody( const Response& rspn, osstream_t& oss ) {
	oss << rspn.body();
}

/* METHOD - GET */

char*
HTTP::GET( const str_t& uri, size_t& size ) {
	File target( dirRoot + uri, R );

	std::filebuf* pbuf = target.fs.rdbuf();
	size = pbuf->pubseekoff( 0, target.fs.end, target.fs.in );
	pbuf->pubseekpos( 0, target.fs.in );

	char *buf = new char[size];
	pbuf->sgetn( buf, size );
	
	return buf;
}

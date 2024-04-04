#include "HTTP.hpp"
#include "Transaction.hpp"

/*
	HTTP MESSAGE FORMMAT

	HTTP-message   = start-line CRLF
                   *( field-line CRLF )
                   CRLF
                   [ message-body ]

	request-line = method SP request-target SP HTTP-version
	status-line = HTTP-version SP status-code SP [ reason-phrase ]

	field-line = field-name ":" OWS field-value OWS
*/


/* NGINX plain GET transaction
	[Request]
		GET / HTTP/1.1
		Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,**;q=0.8,application/signed-exchange;v=b3;q=0.7
		Accept-Encoding: gzip, deflate, br, zstd
		Accept-Language: ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7
		Cache-Control: max-age=0
		Connection: keep-alive
		Host: localhost
		If-Modified-Since: Sun, 24 Mar 2024 13:56:25 GMT
		If-None-Match: "66003109-267"
		Sec-Fetch-Dest: document
		Sec-Fetch-Mode: navigate
		Sec-Fetch-Site: none
		Sec-Fetch-User: ?1
		Upgrade-Insecure-Requests: 1
		User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36
		sec-ch-ua: "Google Chrome";v="123", "Not:A-Brand";v="8", "Chromium";v="123"
		sec-ch-ua-mobile: ?0
		sec-ch-ua-platform: "macOS"

	[Response]
		HTTP/1.1 304 Not Modified
		Server: nginx/1.24.0
		Date: Wed, 03 Apr 2024 04:13:00 GMT
		Last-Modified: Sun, 24 Mar 2024 13:56:25 GMT
		Connection: keep-alive
		ETag: "66003109-267"
*/

/* REQUEST */
// Request::Request( const str_t& msgRqst ): _body( NULL ) {
Request::Request( const char* buf ): _body( NULL ) {
	str_t	msgRqst( buf );
	size_t	posBegin = 0;
	size_t	posEnd = 0;

	// CRLF could be replaced with only LF (see RFC)
	
	posEnd = msgRqst.find( CRLF, posBegin );
	_getLine( msgRqst.substr( posBegin, posEnd ) );
	posBegin = posEnd + 2;

	while ( LOOP ) {
		posEnd = msgRqst.find( CRLF, posBegin );
		if ( posEnd == str_t::npos ) break;
		_getHeader( msgRqst.substr( posBegin, posEnd ) );
		posBegin = posEnd + 2;
	}
	
	if( posBegin != msgRqst.length() )
		_getBody( msgRqst.substr( posBegin ) );

	logfile.fs << msgRqst;
}

void
Request::_getLine( str_t line ) {
	isstream_t iss( line );

	_assignMethod( _token( iss, SP ) );
	_assignURI( _token( iss, SP ) );
	_assignVersion( _token( iss, NONE ) );
}

void
Request::_assignMethod( str_t token ) {
	vec_str_iter_t	iter = lookup( HTTP::method, token );

	if ( iter == HTTP::method.end() )
		throw err_t( "_assignMethod: " + errMsg[INVALID_REQUEST_LINE] );
	
	_line.method = static_cast<methodID>( std::distance( HTTP::method.begin(), iter ) );
}

void
Request::_assignURI( str_t token ) { _line.uri = token; }

void
Request::_assignVersion( str_t token ) {
	isstream_t iss( token );

	if ( _token( iss, '/' ) != HTTP::http )
		throw err_t( "_assignVersion: " + errMsg[INVALID_REQUEST_LINE] );
	
	vec_str_iter_t iter = lookup( HTTP::version, _token( iss, NONE ) );

	if ( iter == HTTP::version.end() )
		throw err_t( "_assignVersion: " + errMsg[INVALID_REQUEST_LINE] );

	_line.version = static_cast<versionID>( std::distance( HTTP::version.begin(), iter ) );
}

void
Request::_getHeader( str_t field ) {
	vec_str_iter_t iter = lookup( HTTP::header_in, field );

	// if ( iter == HTTP::header_in.end() )
	// 	throw err_t( "_getHeader: " + errMsg[INVALID_REQUEST_FIELD] + " " + field );

	switch ( std::distance( HTTP::header_in.begin(), iter ) ) {
		case 0: _header.host = field; break;
		case 1: _header.date = field; break;
		case 2: _header.connection = KEEP_ALIVE; break;
		// default: throw err_t( "_getHeader: " + errMsg[INVALID_REQUEST_FIELD] + " " + field );
	}
}

void
Request::_getBody( str_t body ) {
	_header.content_length = body.size();
	
	_body = new char[body.length()];
	body.copy( _body, body.length() );
	_body[body.length()] = '\0';
}

str_t
Request::_token( isstream_t& iss, char delim ) {
	str_t token;

	if ( ( delim && !std::getline( iss, token, delim ) ) ||
		( !delim && !std::getline( iss, token ) ) )
		throw err_t( "_token: " + errMsg[INVALID_REQUEST_LINE] );

	return token;
}

Request::~Request( void ) { if ( _body ) delete _body; }

 /* REQUEST - METHOD */
const request_line_t&
Request::line( void ) const { return _line; }

const request_header_t&
Request::header( void ) const { return _header; }

const char*
Request::body( void ) const { return _body; }





/* RESPONSE */
Response::Response( const Request& rqst ): _body( NULL ) {
	switch ( rqst.line().method ) {
		case GET:
			_body = HTTP::GET( rqst.line().uri, _header.content_length ); break;

		case POST:
			HTTP::POST( rqst ); break;

		case DELETE:
			HTTP::DELETE( rqst ); break;
	}

	_line.version = VERSION_11;
	_line.status = 200;
}

Response::~Response( void ) { if ( _body ) delete _body; }

const response_line_t&
Response::line( void ) const { return _line; }

const response_header_t&
Response::header( void ) const { return _header; }

const char*
Response::body( void ) const { return _body; }


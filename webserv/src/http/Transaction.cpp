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

/* REQUEST */
Request::Request( const str_t& msgRqst ) {
	size_t	pos = 0;
	str_t	substr;

	// CRLF could be replaced with only LF (see RFC)
	substr = msgRqst.substr( pos, pos = msgRqst.find( CRLF, pos ) );
	_getLine( substr );

	while ( !(substr = msgRqst.substr( pos + 2, pos = msgRqst.find( CRLF, pos ) ) ).empty() )
		_getHeader( substr );

	// _getBody(  );
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
	vec_str_iter_t	iter = lookupStr( HTTP::method, token );

	if ( iter == HTTP::method.end() )
		throw err_t( "_assignMethod: " + errMsg[INVALID_REQUEST_LINE] );
	
	_line.method = static_cast<methodID>( std::distance( HTTP::method.begin(), iter ) );
}

void
Request::_assignURI( str_t token ) { _line.target = token; }

void
Request::_assignVersion( str_t token ) {
	isstream_t iss( token );

	if ( _token( iss, '/' ) != HTTP::http )
		throw err_t( "_assignVersion: " + errMsg[INVALID_REQUEST_LINE] );
	
	vec_str_iter_t iter = lookupStr( HTTP::version, _token( iss, NONE ) );

	if ( iter == HTTP::version.end() )
		throw err_t( "_assignVersion: " + errMsg[INVALID_REQUEST_LINE] );

	_line.version = static_cast<versionID>( std::distance( HTTP::version.begin(), iter ) );
}

void
Request::_getHeader( str_t field ) {
	vec_str_iter_t iter = lookupStr( HTTP::header_in, field );

	// if ( iter == HTTP::header_in.end() )
	// 	throw err_t( "_getHeader: " + errMsg[INVALID_REQUEST_FIELD] + " " + field );

	switch ( std::distance( HTTP::header_in.begin(), iter ) ) {
		case 0: _header.host = field; break;
		case 1: _header.date = field; break;
		case 2: _header.connection = KEEP_ALIVE; break;
		// default: throw err_t( "_getHeader: " + errMsg[INVALID_REQUEST_FIELD] + " " + field );
	}
}

str_t
Request::_token( isstream_t& iss, char delim ) {
	str_t token;

	if ( ( delim && !std::getline( iss, token, delim ) ) ||
		( !delim && !std::getline( iss, token ) ) )
		throw err_t( "_token: " + errMsg[INVALID_REQUEST_LINE] );

	return token;
}



 /* REQUEST - METHOD */
const request_line_t& Request::line( void ) { return _line; }
const request_header_t& Request::header( void ) { return _header; }



/* RESPONSE */
Response::Response( const Request& rqst ) {
	_line.version = VERSION_11;
	_line.status = lookupUint( HTTP::status, 202);
	_body = HTTP::GET( rqst.line().target );
	_header.content_length = _body.size();
}

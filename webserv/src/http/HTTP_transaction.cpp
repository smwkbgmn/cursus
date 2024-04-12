#include "HTTP.hpp"

// http_t	HTTP::http;
// keys_t	HTTP::key;

/*	HTTP MESSAGE FORMMAT

	HTTP-message   = start-line CRLF
                   *( field-line CRLF )
                   CRLF
                   [ message-body ]

	request-line = method SP request-target SP HTTP-version
	status-line = HTTP-version SP status-code SP [ reason-phrase ]

	field-line = field-name ":" OWS field-value OWS
*/


/*	NGINX plain GET transaction

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

/* METHOD - transaction: send response message */
void
HTTP::transaction( const Client& client ) {
	osstream_t oss;

	try {
		Request rqst( client );
		_build( Response( rqst ), oss );
	} catch ( exception_t& exc ) { logfile.fs << exc.what(); _build( Response( client ), oss ); }

	// LOGGING Response Message
	logfile.fs << oss.str() << std::endl;

	ssize_t bytesSent = send( client.socket(), oss.str().c_str(), oss.str().size(), 0 );

	if ( bytesSent == ERROR )
		throw err_t( "http: send: " + errMsg[FAIL_SEND] );
}

void
HTTP::_build( const Response& rspn, osstream_t& oss ) {
	_buildLine( rspn, oss );
	_buildHeader( rspn, oss );
	if ( rspn.body() )
		_buildBody( rspn, oss );
}

void
HTTP::_buildLine( const Response& rspn, osstream_t& oss ) {
	map_uint_str_t::iterator iter = key.status.find( rspn.line().status );

	oss <<
	http.signature << '/' << http.version.at( static_cast<size_t>( rspn.line().version ) ) << ' ' <<
	iter->first << " " << iter->second << 
	CRLF;
}

void
HTTP::_buildHeader( const Response& rspn, osstream_t& oss ) {
	for ( vec_uint_t::const_iterator iter = rspn.header().list.begin(); iter != rspn.header().list.end(); ++iter ) {
		_buildHeaderName( *iter, oss );
		_buildHeaderValue( rspn.header(), *iter, oss );
	}
	oss << CRLF;
}

void
HTTP::_buildHeaderName( uint_t id, osstream_t& oss ) {
	oss << key.header_out.at( id ) << ": ";
}

void
HTTP::_buildHeaderValue( const response_header_t& header, uint_t id, osstream_t& oss ) {
	switch( id ) {
		case OUT_SERVER			: oss << header.server; break;
		case OUT_DATE			: break;
		case OUT_CONNECTION		: break;
		case OUT_CHUNK			: break;
		case OUT_CONTENT_LEN	: oss << header.content_length; break;
		case OUT_CONTENT_TYPE	: oss << header.content_type; break;
	}
	oss << CRLF;
}

void
HTTP::_buildBody( const Response& rspn, osstream_t& oss ) {
	for ( size_t idx = 0; idx < rspn.header().content_length; ++idx )
		oss << rspn.body()[idx];
}


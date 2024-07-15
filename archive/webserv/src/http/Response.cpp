#include "HTTP.hpp"
#include "Client.hpp"
#include "Request.hpp"

#include "Response.hpp"

/* ACCESS */
const response_line_t&		Response::line( void ) const { return _line; }
const response_header_t&	Response::header( void ) const { return _header; }
const sstream_t&			Response::body( void ) const { return _body; }

/* INSTANTIATE */
Response::Response( void ) {}

Response::Response( const uint_t& status, const config_t& conf ) {
	_errpage( status, conf );
	_addServerInfo( CN_CLOSE );
}

Response::~Response( void ) {}

/* METHOD - act: do request method after valid the request message */
void
Response::act( const Request& rqst ) {
	log( "HTTP\t: constructing response" );

	if ( rqst.location().rewrite.empty() ) {

		_doMethodValid( rqst );
		_doMethod( rqst );

		if ( rqst.header().connection == CN_KEEP_ALIVE ) _addServerInfo( CN_KEEP_ALIVE );
		else _addServerInfo( CN_CLOSE );
	}
	else _redirect( rqst.location().rewrite +
		rqst.line().uri.substr( rqst.location().root.length() ), 302 );
}

void
Response::_doMethod( const Request& rqst ) {
	switch ( rqst.line().method ) {
		case GET:
			if ( isDir( rqst.info ) ) _index( rqst );
			else {
				HTTP::GET( rqst.line().uri, _body, _header.content_length );

				_mime( rqst.line().uri );
				_header.list.push_back( OUT_CONTENT_LEN );
				_header.list.push_back( OUT_CONTENT_TYPE );
			} break;

		case POST		: HTTP::POST( rqst ); _line.status = 204; break;
		case DELETE		: HTTP::DELETE( rqst ); _line.status = 204; break;
		case NOT_ALLOWED: _errpage( 405, rqst.config() ); break;
		
		case UNKNOWN: {
			vec_uint_t::const_iterator iter = rqst.location().allow.begin();
			while ( iter != rqst.location().allow.end() )
				_header.allow.push_back( *iter++ );
			_header.list.push_back( OUT_ALLOW );

			_errpage( 501, rqst.config() );
			break;
		}
	}
}

void
Response::_doMethodValid( const Request& rqst ) {
	switch ( rqst.line().method ) {
		case GET:
			if ( rqst.header().content_length || !rqst.header().content_type.empty() ||
				!rqst.body().str().empty() )
					throw errstat_t( 400, err_msg[GET_WITH_BODY] );
			break;

		case POST:
			if ( lookup( rqst.header().list, IN_CONTENT_LEN ) == rqst.header().list.end() &&
				rqst.header().transfer_encoding != TE_CHUNKED )
				throw errstat_t( 411, err_msg[POST_EMPTY_CONTENT_LEN] );

			if ( rqst.header().content_length > rqst.config().client_max_body )
				throw errstat_t( 413, err_msg[POST_OVER_CONTENT_LEN] );
			break;

		case DELETE	: break;
		default		: break;
	}
}

void
Response::_addServerInfo( const connection_e& connection ) {	
	_header.server		= software;
	_header.date		= getNow();
	_header.connection	= connection;

	_header.list.push_back( OUT_SERVER );
	_header.list.push_back( OUT_DATE );
	_header.list.push_back( OUT_CONNECTION );
}

void
Response::_mime( const str_t& uri ) {
	size_t dot = uri.rfind( '.' );
	
	if ( found( dot ) ) {
		str_t ext = uri.substr( dot + 1 );

		try { _header.content_type = HTTP::key.mime.at( ext ); }
		catch ( exception_t &exc ) { _header.content_type = HTTP::http.type_unknown; }
	}
}

/* METHOD - index: proceed responsing with indexing */
void
Response::_index( const Request& rqst ) {
	if ( *rqst.line().uri.rbegin() != '/' ) _redirect( _indexURIConceal( rqst, "" ) + "/", 301 );
	else {
		path_t	index;
		fstat_t	info;

		if ( rqst.location().index.size() && !( index = _indexFileValid( rqst, info ) ).empty() )
			_indexFile( rqst, index, info );
		else
			_indexAuto( rqst );
	} 
}

void
Response::_indexFile( const Request& rqst, const path_t& index, const fstat_t& info ) {
	if ( isDir( info ) ) _redirect( _indexURIConceal( rqst, index ) + "/", 301 );
	else {
		HTTP::GET( rqst.location().root + '/' + index, _body, _header.content_length );

		_mime( rqst.location().root + '/' + index );
		_header.list.push_back( OUT_CONTENT_LEN );
		_header.list.push_back( OUT_CONTENT_TYPE );
	}
}

path_t
Response::_indexFileValid( const Request& rqst, fstat_t& info ) {
	for ( vec_str_t::const_iterator iter = rqst.location().index.begin();
		iter != rqst.location().index.end(); ++iter ) {
		if ( getInfo( rqst.line().uri + *iter, info ) ) 
			return *iter;
	}
	return "";
}

void
Response::_indexAuto( const Request& rqst ) {
	if ( rqst.location().index_auto ) _indexAutoBuild( rqst );
	else _errpage( 403, rqst.config() );
}
 
path_t
Response::_indexURIConceal( const Request& rqst, const path_t& index  ) {
	path_t	concealed = rqst.location().path + rqst.line().uri.substr( rqst.location().root.length() );

	if ( !index.empty() )
		concealed += "/" + index;

	return concealed;
}

void
Response::_indexAutoBuild( const Request& rqst ) {
	autoindexScript( rqst.line().uri, _body );
	_header.content_type	= HTTP::key.mime.at( "html" );
	_header.content_length	= streamsize( _body );
	_header.list.push_back( OUT_CONTENT_LEN );
	_header.list.push_back( OUT_CONTENT_TYPE );
}

/* METHOD - redirect: add location header and set the path value */
void
Response::_redirect( const path_t& dest, const uint_t& status ) {
	_line.status		= status;

	_header.location	= dest;
	_header.list.push_back( OUT_LOCATION );
}


/* METHOD - errpage: proceed responsing with error status */
void
Response::_errpage( const uint_t& status, const config_t& config ) {
	path_t	page;

	if ( status < 500 ) page = config.file_40x;
	else page = config.file_50x;

	if ( page.length() && isExist( page ) ) HTTP::GET( page, _body, _header.content_length );
	else _errpageBuild( status );

	_header.content_type = HTTP::key.mime.at( "html" );
	_header.list.push_back( OUT_CONTENT_LEN );
	_header.list.push_back( OUT_CONTENT_TYPE );
	_line.status = status;
}

void
Response::_errpageBuild( const uint_t& status ) {
	errpageScript( _body, status, HTTP::key.status.at( status ) );
	_header.content_length = streamsize( _body );
}

/* STRUCT */
response_line_s::response_line_s( void ) {
	version				= VERSION_11;
	status				= 200;
}

response_header_s::response_header_s( void ) {
	connection			= CN_KEEP_ALIVE;
	transfer_encoding	= TE_IDENTITY;
	content_length		= 0;
}

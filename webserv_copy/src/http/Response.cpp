#include "Response.hpp"

/* ACCESS */
const response_line_t&		Response::line( void ) const { return _line; }
const response_header_t&	Response::header( void ) const { return _header; }
const sstream_t&			Response::body( void ) const { return _body; }

/* CONSTRUCT */
Response::Response( const Request& rqst ) {
	log( "HTTP\t: constructing response" );

	try {
		_doMethodValid( rqst );
		_doMethod( rqst );
	}
	catch ( errstat_t& errstat ) { _errpage( errstat.code, rqst.config() ); }
	_addServerInfo( rqst );
}

void
Response::_doMethod( const Request& rqst ) {
	switch ( rqst.line().method ) {
		case GET:
			if ( rqst.line().uri.length() == 1 || isDir( rqst.info ) )
				_index( rqst );
			else {
				HTTP::GET( rqst.line().uri, _body, _header.content_length );

				_mime( rqst.line().uri );
				_header.list.push_back( OUT_CONTENT_LEN );
				_header.list.push_back( OUT_CONTENT_TYPE );
			}
			break;

		case POST:
			HTTP::POST( rqst );

			_line.status = 204;
			break;

		case DELETE:
			HTTP::DELETE( rqst );

			_line.status = 204;
			break;

		case NOT_ALLOWED:
			_errpage( 405, rqst.config() );
			break;
		
		case UNKNOWN:
			vec_uint_t::const_iterator iter = rqst.location().allow.begin();
			while ( iter != rqst.location().allow.end() )
				_header.allow.push_back( *iter );
			_header.list.push_back( OUT_ALLOW );

			_errpage( 501, rqst.config() );
			break;
	}
}

void
Response::_doMethodValid( const Request& rqst ) {
	switch ( rqst.line().method ) {
		case GET:
			if ( rqst.header().content_length || !rqst.header().content_type.empty() ||
				rqst.body().str().size() )
					throw errstat_t( 400, err_msg[GET_WITH_BODY] );
			break;

		case POST:
			if ( lookup( rqst.header().list, IN_CONTENT_LEN ) == rqst.header().list.end() )
				throw errstat_t( 411, err_msg[POST_EMPTY_CONTENT_LEN] );

			if ( rqst.header().content_length > rqst.config().client_max_body )
				throw errstat_t( 405, err_msg[POST_OVER_CONTENT_LEN] );
			break;

		case DELETE:
			break;

		default:
			break;
	}
}

void
Response::_addServerInfo( const Request& rqst ) {	
	_header.server		= rqst.config().name;
	_header.connection	= KEEP_ALIVE;

	_header.list.push_back( OUT_SERVER );
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

Response::Response( const Client& client, const uint_t& errstat ) { 
	log( "HTTP\t: constructing response_errorcase" );

	_errpage( errstat, client.server().config() );
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
	path_t	concealed;

	if ( rqst.location().alias.length() > 1 )
		concealed += rqst.location().alias;
	concealed += rqst.line().uri.substr( rqst.location().root.length() );

	if ( !index.empty() )
		concealed += "/" + index;

	// std::clog << "_uriConceal: " << concealed << std::endl;

	return concealed;
}

void
Response::_indexAutoBuild( const Request& rqst ) {
	autoindexScript( rqst.line().uri, _body );
	_header.content_type	= HTTP::key.mime.at( "html" );
	_header.content_length	= _body.str().size();
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

	if ( !page.empty() && isExist( page ) ) HTTP::GET( page, _body, _header.content_length );
	else _errpageBuild( status );

	_header.content_type = HTTP::key.mime.at( "html" );
	_header.list.push_back( OUT_CONTENT_LEN );
	_header.list.push_back( OUT_CONTENT_TYPE );
	_line.status = status;
}

void
Response::_errpageBuild( const uint_t& status ) {
	errpageScript( _body, status, HTTP::key.status.at( status ) );
	_header.content_length = _body.str().size();
}

Response::~Response( void ) {}

/* STRUCT */
response_line_s::response_line_s( void ) {
	version				= VERSION_11;
	status				= 200;
}

response_header_s::response_header_s( void ) {
	connection			= KEEP_ALIVE;
	transfer_encoding	= TE_IDENTITY;
	content_length		= 0;
}

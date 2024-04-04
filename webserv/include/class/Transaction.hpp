#ifndef TRANSACTION_HPP
# define TRANSACTION_HPP

# include <new>
# include <algorithm>

# include "structure.hpp"

/* For body contents, see RFC HTTP semantic 6.4 Content */

class Request {
	public:
		// Request( const str_t& );
		Request( const char* );
		~Request( void );

		const request_line_t&	line( void ) const;
		const request_header_t&	header( void ) const;
		const char*				body( void ) const;

	private:
		request_line_t			_line;
		request_header_t		_header;
		char*					_body;

		void					_getLine( str_t );
		void					_assignMethod( str_t );
		void					_assignURI( str_t );
		void					_assignVersion( str_t );

		void					_getHeader( str_t );
		void					_getBody( str_t );

		str_t					_token( isstream_t&, char );
};

class Response {
	public:
		Response( const Request& );
		~Response( void );

		const response_line_t&		line( void ) const;
		const response_header_t&	header( void ) const ;
		const char*					body( void ) const;

	private:
		response_line_t				_line;
		response_header_t			_header;
		char*						_body;
};

#endif
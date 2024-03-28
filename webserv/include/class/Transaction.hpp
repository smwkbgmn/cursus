#ifndef TRANSACTION_HPP
# define TRANSACTION_HPP

# include <algorithm>

# include "structure.hpp"

/* For body contents, see RFC HTTP semantic 6.4 Content */

class Request {
	public:
		Request( const str_t& msgRequest );
		~Request( void );

	private:
		request_line_t			_line;
		request_header_t		_header;
		// bits_t					_body; // Should be changed later to Transfer-encoding type > octet

		void					_getLine( str_t );
		void					_assignMethod( str_t );
		void					_assignURI( str_t );
		void					_assignVersion( str_t );

		void					_getHeader( str_t );
		void					_getBody( str_t );

		str_t					_token( isstream_t&, char );
		
		template<typename T>
		typename T::iterator	_find( T&, str_t );
		
};

class Response {
	public:
		Response( const Request& );
		~Response( void );

	private:
		response_line_t		_line;
		response_header_t	_header;
						_body;		
};

class Transaction: Request {
	public:
		Transaction( const str_t& );
		~Transaction( void );

	private:
		Transaction( void );
		Transaction( const Transaction& );
		
		Transaction&	operator=( const Transaction& );
};

#endif
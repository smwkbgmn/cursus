#ifndef REQUEST_HPP
# define REQUEST_HPP

# include "structure.hpp"
# include "Client.hpp"

class Request {
	public:
		Request( const Client& );
		~Request( void );

		const Client&				client( void ) const;
		const config_t&				config( void ) const;

		const request_line_t&		line( void ) const;
		const request_header_t&		header( void ) const;
		const char*					body( void ) const;

	private:
		const Client&				_client;
		size_t						_configIdx;

		request_line_t				_line;
		request_header_t			_header;
		char*						_body;

		void						_parse( const char* );
		
		void						_parseLine( str_t );
		void						_assignMethod( str_t );
		void						_assignURI( str_t );
		void						_assignVersion( str_t );

		void						_parseHeader( str_t );
		void						_add( vec_uint_t&, uint_t );

		void						_parseBody( str_t );

		str_t						_token( isstream_t&, char );
};

# include "HTTP.hpp"

#endif
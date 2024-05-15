#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "utill.hpp"

# include "Request.hpp"

class Response {
	public:
		Response( const Request& );
		Response( const Client&, const uint_t& ); // When fail to construct Request
		~Response( void );

		const response_line_t&		line( void ) const;
		const response_header_t&	header( void ) const ;
		const sstream_t&			body( void ) const;

	private:
		response_line_t				_line;
		response_header_t			_header;
		sstream_t					_body;

		void						_doMethod( const Request& );
		void						_doMethodValid( const Request& );
		void						_addServerInfo( const Request& );
		
		void 						_index( const Request& );
		void						_indexFile( const Request&, const path_t&, const fstat_t& );
		path_t						_indexFileValid( const Request&, fstat_t& );
		void						_indexAuto( const Request& );
		void						_indexAutoBuild( const Request& );
		path_t						_indexURIConceal( const Request&, const path_t& );

		void						_redirect( const path_t&, const uint_t& );

		void						_errpage( const uint_t&, const config_t& );
		void						_errpageBuild( const uint_t& );
		void						_mime( const str_t& );
};

# include "HTTP.hpp"

#endif
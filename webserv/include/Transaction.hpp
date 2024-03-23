#ifndef TRANSACTION_HPP
# define TRANSACTION_HPP

# include "structure.hpp"

/*
	[Message object for HTTP]
	accept LF and CRLF either

	GET: refuse body contents
*/

# define OPTIONS 3

enum methodID {
	GET,
	POST,
	DELETE
};

const str_t	methodName[OPTIONS] = {
	"GET",
	"POST",
	"DELETE"
};

class Request {
	public:
		methodID	method;
		str_t		url;
		str_t		version;
		str_t		body;
		
	private:
};

class Response {
	public:
		str_t		version;
		status_t	stat;
		str_t		msg;
		str_t		body;

	private:
		struct ResponseLine {
		};
};

class Transaction: Request, Response {
	public:
		Transaction( const str_t& );
		~Transaction( void );

		/* Resource Mapping(Docroot) */

	private:
};

#endif
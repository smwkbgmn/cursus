#ifndef TRANSACTION_HPP
# define TRANSACTION_HPP

# include "structure.hpp"

/*
	[Message object for HTTP]
	accept LF and CRLF either

	GET: refuse body contents
*/


class Request {
	public:
		
	private:
		enum ID {
			METHOD,
			URL,
			VERSION,
			HEADER,
			BODY
		};
};

class Response {
	// redirection
};

class Transaction {
	public:
		Transaction( const vec_str_t& );
		
		/* Methods for parsing request &
		writing response */

		/* Resource Mapping(Docroot) */

	private:
		Request		_msgIn;
		Response	_msgOut;
};

#endif
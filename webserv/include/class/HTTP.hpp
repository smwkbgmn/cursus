#ifndef HTTP_HPP
# define HTTP_HPP

# include "Transaction.hpp"
# include "Client.hpp"
# include "log.hpp"

# define CNT_METHOD 3
# define CNT_VERSION 4

const str_t dirRoot			= "./html";
const str_t	dirKeys			= "./src/http/";
const str_t	nameStatus		= dirKeys + "keyStatus.txt";
const str_t	nameMime		= dirKeys + "keyMime.txt";
const str_t	nameHeaderIn	= dirKeys + "keyHeaderIn.txt";
const str_t	nameHeaderOut	= dirKeys + "keyHeaderOut.txt";

// Shitty shit versin limit: initializer list
const str_t	strMethod[]		= {
	"GET",
	"POST",
	"DELETE"
};

const str_t	strVersion[]	= {
	"0.9",
	"1.0",
	"1.1",
	"2.0"
};

class HTTP {
	public:
		static str_t		http;
		static vec_str_t	version;
		static vec_str_t	method;
		static vec_str_t	header_in;
		static vec_str_t	header_out;
		static status_t		status;
		static mime_t		mime;

		static void			init( void );
		static void			response( const Client&, const Request& );
	
		static char*		GET( const str_t&, size_t& );
		// static void		POST( const str_t& );
		// static void		DELETE( const str_t& );

		// CGI
		// Redirect

	private:
		static void			_assignHeader( void );
		static void			_assignStatus( void );
		static void			_assignMime( void );
		static void			_assignVec( vec_str_t&, const str_t[], size_t );

		static void			_message( const Response&, osstream_t& );
		static void			_msgLine( const Response&, osstream_t& );
		static void			_msgHeader( const Response&, osstream_t& );
		static void			_msgBody( const Response&, osstream_t& );

};

template<typename Container, typename Target>
typename Container::iterator
lookup( Container& obj, Target token ) { return std::find( obj.begin(), obj.end(), token ); }

#endif

/*
9.3 GET
The GET method means retrieve whatever information (in the form of an entity) is identified by the Request-URI. If the Request-URI refers to a data-producing process, it is the produced data which shall be returned as the entity in the response and not the source text of the process, unless that text happens to be the output of the process.
The semantics of the GET method change to a “conditional GET” if the request message includes an If- Modified-Since, If-Unmodified-Since, If-Match, If-None-Match, or If-Range header field. A conditional GET method requests that the entity be transferred only under the circumstances described by the conditional header field(s). The conditional GET method is intended to reduce unnecessary network usage by allowing cached entities to be refreshed without requiring multiple requests or transferring data already held by the client.
The semantics of the GET method change to a “partial GET” if the request message includes a Range header field. A partial GET requests that only part of the entity be transferred, as described in section 14.35. The partial GET method is intended to reduce unnecessary network usage by allowing partially-retrieved entities to be completed without transferring data already held by the client.
The response to a GET request is cacheable if and only if it meets the requirements for HTTP caching described in section 13.
See section 15.1.3 for security considerations when used for forms.


9.5 POST
The POST method is used to request that the origin server accept the entity enclosed in the request as a new subordinate of the resource identified by the Request-URI in the Request-Line. POST is designed to allow a uniform method to cover the following functions:
• Annotation of existing resources;
• Posting a message to a bulletin board, newsgroup, mailing list, or similar group of articles;
• Providing a block of data, such as the result of submitting a form, to a data-handling process;
• Extending a database through an append operation.
The actual function performed by the POST method is determined by the server and is usually dependent on the
Request-URI.

The posted entity is subordinate to that URI in the same way that a file is subordinate to a directory containing it, a news article is subordinate to a newsgroup to which it is posted, or a record is subordinate to a database.
The action performed by the POST method might not result in a resource that can be identified by a URI. In this case, either 200 (OK) or 204 (No Content) is the appropriate response status, depending on whether or not the response includes an entity that describes the result.
If a resource has been created on the origin server, the response SHOULD be 201 (Created) and contain an entity which describes the status of the request and refers to the new resource, and a Location header (see section 14.30).
Responses to this method are not cacheable, unless the response includes appropriate Cache-Control or Expires header fields. However, the 303 (See Other) response can be used to direct the user agent to retrieve a cacheable resource.
POST requests MUST obey the message transmission requirements set out in section 8.2.
See section 15.1.3 for security considerations.


9.7 DELETE
The DELETE method requests that the origin server delete the resource identified by the Request-URI. This method MAY be overridden by human intervention (or other means) on the origin server. The client cannot be guaranteed that the operation has been carried out, even if the status code returned from the origin server indicates that the action has been completed successfully. However, the server SHOULD NOT indicate success unless, at the time the response is given, it intends to delete the resource or move it to an inaccessible location.
A successful response SHOULD be 200 (OK) if the response includes an entity describing the status, 202 (Accepted) if the action has not yet been enacted, or 204 (No Content) if the action has been enacted but the response does not include an entity.
If the request passes through a cache and the Request-URI identifies one or more currently cached entities, those entries SHOULD be treated as stale. Responses to this method are not cacheable.

The scheme and host are case-insensitive and normally provided in lowercase; all other components are compared in a case-sensitive manner.

For example, the following three URIs are equivalent:

   http://example.com:80/~smith/home.html
   http://EXAMPLE.com/%7Esmith/home.html
   http://EXAMPLE.com:/%7esmith/home.html


4.3.1. URI Origin
The origin for a given URI is the triple of scheme, host, and port after normalizing the scheme and host to lowercase and normalizing the port to remove any leading zeros. If port is elided from the URI, the default port for that scheme is used. For example, the URI

   https://Example.Com/happy.js
would have the origin

   { "https", "example.com", "443" }


5.2. Field Lines and Combined Field Value
Field sections are composed of any number of field lines, each with a field name (see Section 5.1) identifying the field, and a field line value that conveys data for that instance of the field.

When a field name is only present once in a section, the combined field value for that field consists of the corresponding field line value. When a field name is repeated within a section, its combined field value consists of the list of corresponding field line values within that section, concatenated in order, with each field line value separated by a comma.

For example, this section:

Example-Field: Foo, Bar
Example-Field: Baz
contains two field lines, both with the field name "Example-Field". The first field line has a field line value of "Foo, Bar", while the second field line value is "Baz". The field value for "Example-Field" is the list "Foo, Bar, Baz".

A server MUST NOT apply a request to the target resource until it receives the entire request header section, since later header field lines might include conditionals, authentication credentials, or deliberately misleading duplicate header fields that could impact request processing.


5.4. Field Limits
HTTP does not place a predefined limit on the length of each field line, field value, or on the length of a header or trailer section as a whole, as described in Section 2. Various ad hoc limitations on individual lengths are found in practice, often depending on the specific field's semantics.

A server that receives a request header field line, field value, or set of fields larger than it wishes to process MUST respond with an appropriate 4xx (Client Error) status code. Ignoring such header fields would increase the server's vulnerability to request smuggling attacks (Section 11.2 of [HTTP/1.1]).

A client MAY discard or truncate received field lines that are larger than the client wishes to process if the field semantics are such that the dropped value(s) can be safely ignored without changing the message framing or response semantics.
*/


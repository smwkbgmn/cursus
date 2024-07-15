#ifndef FILTER_HPP
# define FILTER_HPP

# include "structure.hpp"

/*
	token	= 1*tchar
	tchar	= "!" / "#" / "$" / "%" / "&" / "'" / "*"
					/ "+" / "-" / "." / "^" / "_" / "`" / "|" / "~"
					/ DIGIT / ALPHA; any VCHAR, except delimiters

	OWS		= *( SP / HTAB ); optional whitespace
	RWS		= 1*( SP / HTAB ); required whitespace
	BWS		= OWS; "bad" whitespace

	See iana.org for method, header and status list
	method: https://www.iana.org/assignments/http-methods/http-methods.xhtml
	header: https://www.iana.org/assignments/http-fields/http-fields.xhtml
			also https://en.wikipedia.org/wiki/List_of_HTTP_header_fields
	status:
	https://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
*/

# define NONE			0

# define CR				'\r'
# define LF				'\n'
# define SP				' '

# define CRLF			"\r\n"
# define SIZE_CRLF		2

# define MSG_END		"\r\n\r\n"
# define SIZE_MSG_END	4

# define DEFAULT		0

/* STRINGS - for assigning vector values (because of the version
limitation, not available to use the vector argument initialize list) */
const str_t str_method[] = {
	"GET",
	"POST",
	"DELETE"
};

const str_t str_version[] = {
	"0.9",
	"1.0",
	"1.1",
	"2.0"
};

const str_t str_connection[] = {
	"keep-alive",
	"close"
};

const str_t str_transfer_enc[] = {
	"identity",
	"chunked"
};

/* ENUM */
enum method_e {
	GET,
	POST,
	DELETE,
	NOT_ALLOWED,
	UNKNOWN
};

enum version_e {
	VERSION_9,
	VERSION_10,
	VERSION_11,
	VERSION_20,
	NOT_SUPPORTED
};

enum connection_e {
	CN_KEEP_ALIVE,
	CN_CLOSE,
	CN_UNKNOWN
};

enum transfer_enc_e {
	TE_IDENTITY,
	TE_CHUNKED,
	TE_UNKNOWN
};

enum header_in_e {
	IN_HOST,
	IN_CONNECTION,
	IN_TRANSFER_ENC,
	IN_CONTENT_LEN,
	IN_CONTENT_TYPE,
	IN_COOKIE
};

enum header_out_e {
	OUT_SERVER,
	OUT_DATE,
	OUT_CONNECTION,
	OUT_TRANSFER_ENC,
	OUT_CONTENT_LEN,
	OUT_CONTENT_TYPE,
	OUT_LOCATION,
	OUT_ALLOW,
	OUT_SET_COOKIE
};

enum cgi_env_e {
	SERVER_NAME,
	SERVER_PORT,
	SERVER_PROTOCOL,
	REMOTE_ADDR,
	REMOTE_HOST,
	GATEWAY_INTERFACE,
	REQUEST_METHOD,
	SCRIPT_NAME,
	CONTENT_LENGTH,
	CONTENT_TYPE,
	PATH_INFO,
	PATH_TRANSLATED,
	QUERY_STRING,
	UPLOAD_DIR,
	HTTP_COOKIE
};

/* STRUCT - Key, Http: core values for implementing HTTP */
typedef struct {
	vec_str_t			header_in;
	vec_str_t			header_out;
	map_uint_str_t		status;
	map_str_type_t		mime;
} 	keys_t;

typedef std::map<method_e, bool> map_method_bool_t;

typedef struct http_s {
	str_t				signature;
	vec_str_t			version;
	vec_str_t			method;

	type_t				type_unknown;
	vec_str_t			encoding;
	vec_str_t			connection;
}	http_t;

/* STRUCT - Configs (Server, Location) */
struct config_s;

typedef struct location_s {
	location_s( const config_s& );

	str_t				path;
	path_t				root;
	path_t				rewrite;

	vec_uint_t			allow;
	
	bool				cgi;
	path_t				upload;

	vec_name_t			index;
	bool 				index_auto;
}	location_t;

typedef std::vector<location_t>	vec_location_t;

typedef struct config_s {
	config_s( void );

	vec_str_t			names;
	port_t				listen;
	path_t				root;

	name_t				file_40x;
	name_t				file_50x;

	size_t				client_max_body;

	vec_location_t		locations;
}	config_t;

typedef std::vector<config_t> vec_config_t;

/* STRUCT - Buffer for messages (composed with two parts of msg and body part) */
typedef struct msg_buffer_s {
	msg_buffer_s( void );

	void				reset( void );
	
	sstream_t			msg;
	ssize_t				msg_read;
	bool				msg_done;

	sstream_t			body;
	ssize_t				body_read;
	ssize_t				body_size;

	bool				chunk;
	size_t				incomplete;

}	msg_buffer_t;

/* STRUCT - Request, Response */
typedef struct {
	version_e			version;
	method_e			method;
	path_t				uri;
	str_t				query;

}	request_line_t;

typedef struct request_header_s {
	request_header_s( void );

	str_t 				host;
	// date_t				date;
	connection_e 		connection; 
	transfer_enc_e 		transfer_encoding;
	size_t				content_length;
	type_t				content_type;

	str_t				cookie;

	vec_uint_t			list;

}	request_header_t;

typedef struct response_line_s {
	response_line_s( void );

	unsigned			version: 2;
	uint_t				status;

}	response_line_t;

typedef struct response_header_s {
	response_header_s( void );

	str_t				server;
	ctime_t				date;
	connection_e		connection;
	transfer_enc_e		transfer_encoding;
	size_t				content_length;
	type_t				content_type;
	str_t				location;
	vec_uint_t			allow;

	str_t				cookie;

	vec_uint_t			list;

}	response_header_t;

#endif

/*
5.1. Field Names
A field name labels the corresponding field value as having the semantics
defined by that name. For example, the Date header field is defined in
Section 6.6.1 as containing the origination timestamp for the message in which
it appears.

  field-name     = token
Field names are case-insensitive and ought to be registered within the
"Hypertext Transfer Protocol (HTTP) Field Name Registry"; see Section 16.3.1.

The interpretation of a field does not change between minor versions of the same
major HTTP version, though the default behavior of a recipient in the absence of
such a field can change. Unless specified otherwise, fields are defined for all
versions of HTTP. In particular, the Host and Connection fields ought to be
recognized by all HTTP implementations whether or not they advertise conformance
with HTTP/1.1.

New fields can be introduced without changing the protocol version if their
defined semantics allow them to be safely ignored by recipients that do not
recognize them; see Section 16.3.

A proxy MUST forward unrecognized header fields unless the field name is listed
in the Connection header field (Section 7.6.1) or the proxy is specifically
configured to block, or otherwise transform, such fields. Other recipients
SHOULD ignore unrecognized header and trailer fields. Adhering to these
requirements allows HTTP's functionality to be extended without updating or
removing deployed intermediaries.

5.2. Field Lines and Combined Field Value
Field sections are composed of any number of field lines, each with a field name
(see Section 5.1) identifying the field, and a field line value that conveys
data for that instance of the field.

When a field name is only present once in a section, the combined field value
for that field consists of the corresponding field line value. When a field name
is repeated within a section, its combined field value consists of the list of
corresponding field line values within that section, concatenated in order, with
each field line value separated by a comma.

For example, this section:

Example-Field: Foo, Bar
Example-Field: Baz
contains two field lines, both with the field name "Example-Field". The first
field line has a field line value of "Foo, Bar", while the second field line
value is "Baz". The field value for "Example-Field" is the list "Foo, Bar, Baz".

5.3. Field Order
A recipient MAY combine multiple field lines within a field section that have
the same field name into one field line, without changing the semantics of the
message, by appending each subsequent field line value to the initial field line
value in order, separated by a comma (",") and optional whitespace (OWS, defined
in Section 5.6.3). For consistency, use comma SP.

The order in which field lines with the same name are received is therefore
significant to the interpretation of the field value; a proxy MUST NOT change
the order of these field line values when forwarding a message.

This means that, aside from the well-known exception noted below, a sender MUST
NOT generate multiple field lines with the same name in a message (whether in
the headers or trailers) or append a field line when a field line of the same
name already exists in the message, unless that field's definition allows
multiple field line values to be recombined as a comma-separated list (i.e., at
least one alternative of the field's definition allows a comma-separated list,
such as an ABNF rule of #(values) defined in Section 5.6.1).

Note: In practice, the "Set-Cookie" header field ([COOKIE]) often appears in a
response message across multiple field lines and does not use the list syntax,
violating the above requirements on multiple field lines with the same field
name. Since it cannot be combined into a single field value, recipients ought to
handle "Set-Cookie" as a special case while processing fields. (See Appendix
A.2.3 of [Kri2001] for details.)

The order in which field lines with differing field names are received in a
section is not significant. However, it is good practice to send header fields
that contain additional control data first, such as Host on requests and Date on
responses, so that implementations can decide when not to handle a message as
early as possible.

A server MUST NOT apply a request to the target resource until it receives the
entire request header section, since later header field lines might include
conditionals, authentication credentials, or deliberately misleading duplicate
header fields that could impact request processing.

5.4. Field Limits
HTTP does not place a predefined limit on the length of each field line, field
value, or on the length of a header or trailer section as a whole, as described
in Section 2. Various ad hoc limitations on individual lengths are found in
practice, often depending on the specific field's semantics.

A server that receives a request header field line, field value, or set of
fields larger than it wishes to process MUST respond with an appropriate 4xx
(Client Error) status code. Ignoring such header fields would increase the
server's vulnerability to request smuggling attacks (Section 11.2 of
[HTTP/1.1]).

A client MAY discard or truncate received field lines that are larger than the
client wishes to process if the field semantics are such that the dropped
value(s) can be safely ignored without changing the message framing or response
semantics.

5.5. Field Values
HTTP field values consist of a sequence of characters in a format defined by the
field's grammar. Each field's grammar is usually defined using ABNF ([RFC5234]).

  field-value    = *field-content
  field-content  = field-vchar
                   [ 1*( SP / HTAB / field-vchar ) field-vchar ]
  field-vchar    = VCHAR / obs-text
  obs-text       = %x80-FF
A field value does not include leading or trailing whitespace. When a specific
version of HTTP allows such whitespace to appear in a message, a field parsing
implementation MUST exclude such whitespace prior to evaluating the field value.

Field values are usually constrained to the range of US-ASCII characters
[USASCII]. Fields needing a greater range of characters can use an encoding,
such as the one defined in [RFC8187]. Historically, HTTP allowed field content
with text in the ISO-8859-1 charset [ISO-8859-1], supporting other charsets only
through use of [RFC2047] encoding. Specifications for newly defined fields
SHOULD limit their values to visible US-ASCII octets (VCHAR), SP, and HTAB. A
recipient SHOULD treat other allowed octets in field content (i.e., obs-text) as
opaque data.

Field values containing CR, LF, or NUL characters are invalid and dangerous, due
to the varying ways that implementations might parse and interpret those
characters; a recipient of CR, LF, or NUL within a field value MUST either
reject the message or replace each of those characters with SP before further
processing or forwarding of that message. Field values containing other CTL
characters are also invalid; however, recipients MAY retain such characters for
the sake of robustness when they appear within a safe context (e.g., an
application-specific quoted string that will not be processed by any downstream
HTTP parser).

Fields that only anticipate a single member as the field value are referred to
as singleton fields.

Fields that allow multiple members as the field value are referred to as
list-based fields. The list operator extension of Section 5.6.1 is used as a
common notation for defining field values that can contain multiple members.

Because commas (",") are used as the delimiter between members, they need to be
treated with care if they are allowed as data within a member. This is true for
both list-based and singleton fields, since a singleton field might be
erroneously sent with multiple members and detecting such errors improves
interoperability. Fields that expect to contain a comma within a member, such as
within an HTTP-date or URI-reference element, ought to be defined with
delimiters around that element to distinguish any comma within that data from
potential list separators.

For example, a textual date and a URI (either of which might contain a comma)
could be safely carried in list-based field values like these:

Example-URIs: "http://example.com/a.html,foo",
              "http://without-a-comma.example.com/"
Example-Dates: "Sat, 04 May 1996", "Wed, 14 Sep 2005"
Note that double-quote delimiters are almost always used with the quoted-string
production (Section 5.6.4); using a different syntax inside double-quotes will
likely cause unnecessary confusion.

Many fields (such as Content-Type, defined in Section 8.3) use a common syntax
for parameters that allows both unquoted (token) and quoted (quoted-string)
syntax for a parameter value (Section 5.6.6). Use of common syntax allows
recipients to reuse existing parser components. When allowing both forms, the
meaning of a parameter value ought to be the same whether it was received as a
token or a quoted string.

Note: For defining field value syntax, this specification uses an ABNF rule
named after the field name to define the allowed grammar for that field's value
(after said value has been extracted from the underlying messaging syntax and
multiple instances combined into a list).
*/

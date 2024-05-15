#ifndef REQUEST_HPP
# define REQUEST_HPP

# include "Client.hpp"

class Request {
	public:
		Request( const Client& );
		~Request( void );

		const Client&				client( void ) const;
		const config_t&				config( void ) const;
		const location_t&			location( void ) const;

		const request_line_t&		line( void ) const;
		const request_header_t&		header( void ) const;
		const sstream_t&			body( void ) const;

		fstat_t						info;

	private:
		const Client&				_client; 
		size_t						_location;

		request_line_t				_line;
		request_header_t			_header;
		
		void						_parse( const sstream_t& );

		void						_parseLine( const str_t& );
		void						_assignMethod( str_t );
		void						_assignURI( str_t );
		void						_assignVersion( str_t );

		void						_parseHeader( const str_t& );
		ssize_t						_add( vec_uint_t&, ssize_t );

		void						_assignBody( const size_t&, const char* );

		str_t						_token( isstream_t&, char );
};

# include "HTTP.hpp"

#endif

/*
6. Message Body
The message body (if any) of an HTTP/1.1 message is used to carry
content (Section 6.4 of [HTTP]) for the request or response. The message
body is identical to the content unless a transfer coding has been applied,
as described in Section 6.1.

  message-body = *OCTET
The rules for determining when a message body is present in an HTTP/1.1
message differ for requests and responses.

The presence of a message body in a request is signaled by a Content-Length
or Transfer-Encoding header field. Request message framing is independent of method semantics.

The presence of a message body in a response, as detailed in Section 6.3, depends
on both the request method to which it is responding and the response status code.
This corresponds to when response content is allowed by HTTP semantics (Section 6.4.1 of [HTTP]).

6.1. Transfer-Encoding
The Transfer-Encoding header field lists the transfer coding names corresponding
to the sequence of transfer codings that have been (or will be) applied to the
content in order to form the message body. Transfer codings are defined in Section 7.

  Transfer-Encoding = #transfer-coding
                       ; defined in [HTTP], Section 10.1.4
Transfer-Encoding is analogous to the Content-Transfer-Encoding field of MIME, which
was designed to enable safe transport of binary data over a 7-bit transport service
([RFC2045], Section 6). However, safe transport has a different focus for an 8bit-clean transfer protocol.
In HTTP's case, Transfer-Encoding is primarily intended to accurately delimit dynamically generated content.
It also serves to distinguish encodings that are only applied in transit from the encodings that are
a characteristic of the selected representation.

A recipient MUST be able to parse the chunked transfer coding (Section 7.1) because
it plays a crucial role in framing messages when the content size is not known in advance.
A sender MUST NOT apply the chunked transfer coding more than once to a message body
(i.e., chunking an already chunked message is not allowed). If any transfer coding other
than chunked is applied to a request's content, the sender MUST apply chunked as the final
transfer coding to ensure that the message is properly framed. If any transfer coding other
than chunked is applied to a response's content, the sender MUST either apply chunked as the
final transfer coding or terminate the message by closing the connection.

For example,

Transfer-Encoding: gzip, chunked
indicates that the content has been compressed using the gzip coding and then
chunked using the chunked coding while forming the message body.

Unlike Content-Encoding (Section 8.4.1 of [HTTP]), Transfer-Encoding is a property of the message,
not of the representation. Any recipient along the request/response chain MAY decode the received
transfer coding(s) or apply additional transfer coding(s) to the message body, assuming that corresponding
changes are made to the Transfer-Encoding field value. Additional information about the encoding
parameters can be provided by other header fields not defined by this specification.

Transfer-Encoding MAY be sent in a response to a HEAD request or in a 304 (Not Modified) response
(Section 15.4.5 of [HTTP]) to a GET request, neither of which includes a message body, to indicate
that the origin server would have applied a transfer coding to the message body if the request had been an
unconditional GET. This indication is not required, however, because any recipient on the response chain
(including the origin server) can remove transfer codings when they are not needed.

A server MUST NOT send a Transfer-Encoding header field in any response with a status code of 1xx (Informational)
or 204 (No Content). A server MUST NOT send a Transfer-Encoding header field in any 2xx (Successful)
response to a CONNECT request (Section 9.3.6 of [HTTP]).

A server that receives a request message with a transfer coding it does not understand SHOULD
respond with 501 (Not Implemented).

Transfer-Encoding was added in HTTP/1.1. It is generally assumed that implementations advertising
only HTTP/1.0 support will not understand how to process transfer-encoded content, and that an HTTP/1.0
message received with a Transfer-Encoding is likely to have been forwarded without proper handling of
the chunked transfer coding in transit.

A client MUST NOT send a request containing Transfer-Encoding unless it knows the server will handle
HTTP/1.1 requests (or later minor revisions); such knowledge might be in the form of specific user
configuration or by remembering the version of a prior received response. A server MUST NOT send a
response containing Transfer-Encoding unless the corresponding request indicates HTTP/1.1 (or later minor revisions).

Early implementations of Transfer-Encoding would occasionally send both a chunked transfer coding for
message framing and an estimated Content-Length header field for use by progress bars. This is why
Transfer-Encoding is defined as overriding Content-Length, as opposed to them being mutually incompatible.
Unfortunately, forwarding such a message can lead to vulnerabilities regarding request smuggling (Section 11.2)
or response splitting (Section 11.1) attacks if any downstream recipient fails to parse the message
according to this specification, particularly when a downstream recipient only implements HTTP/1.0.

A server MAY reject a request that contains both Content-Length and Transfer-Encoding or process
such a request in accordance with the Transfer-Encoding alone. Regardless, the server MUST close
the connection after responding to such a request to avoid the potential attacks.

A server or client that receives an HTTP/1.0 message containing a Transfer-Encoding header field
MUST treat the message as if the framing is faulty, even if a Content-Length is present, and close
the connection after processing the message. The message sender might have retained a portion of
the message, in buffer, that could be misinterpreted by further use of the connection.

6.2. Content-Length
When a message does not have a Transfer-Encoding header field, a Content-Length header field
(Section 8.6 of [HTTP]) can provide the anticipated size, as a decimal number of octets, for
potential content. For messages that do include content, the Content-Length field value provides
the framing information necessary for determining where the data (and message) ends. For messages
that do not include content, the Content-Length indicates the size of the selected representation 
(Section 8.6 of [HTTP]).

A sender MUST NOT send a Content-Length header field in any message that contains a Transfer-Encoding header field.

Note: HTTP's use of Content-Length for message framing differs significantly from the same field's
use in MIME, where it is an optional field used only within the "message/external-body" media-type.

6.3. Message Body Length
The length of a message body is determined by one of the following (in order of precedence):

Any response to a HEAD request and any response with a 1xx (Informational), 204 (No Content), or
304 (Not Modified) status code is always terminated by the first empty line after the header fields,
regardless of the header fields present in the message, and thus cannot contain a message body or trailer section.

Any 2xx (Successful) response to a CONNECT request implies that the connection will become a tunnel
immediately after the empty line that concludes the header fields. A client MUST ignore any Content-Length
or Transfer-Encoding header fields received in such a message.

If a message is received with both a Transfer-Encoding and a Content-Length header field,
the Transfer-Encoding overrides the Content-Length. Such a message might indicate an attempt to
perform request smuggling (Section 11.2) or response splitting (Section 11.1) and ought to be handled as an error.
An intermediary that chooses to forward the message MUST first remove the received Content-Length field and process
the Transfer-Encoding (as described below) prior to forwarding the message downstream.

If a Transfer-Encoding header field is present and the chunked transfer coding (Section 7.1) is the final encoding,
the message body length is determined by reading and decoding the chunked data until the transfer coding indicates
the data is complete.

If a Transfer-Encoding header field is present in a response and the chunked transfer coding is not the final encoding,
the message body length is determined by reading the connection until it is closed by the server.

If a Transfer-Encoding header field is present in a request and the chunked transfer coding is not the final encoding,
the message body length cannot be determined reliably; the server MUST respond with the 400 (Bad Request) status code and then close the connection.

If a message is received without Transfer-Encoding and with an invalid Content-Length header field, then the message
framing is invalid and the recipient MUST treat it as an unrecoverable error, unless the field value can be successfully
parsed as a comma-separated list (Section 5.6.1 of [HTTP]), all values in the list are valid, and all values in the list
are the same (in which case, the message is processed with that single value used as the Content-Length field value).
If the unrecoverable error is in a request message, the server MUST respond with a 400 (Bad Request) status code and
then close the connection. If it is in a response message received by a proxy, the proxy MUST close the connection to the server,
discard the received response, and send a 502 (Bad Gateway) response to the client. If it is in a response message received by
a user agent, the user agent MUST close the connection to the server and discard the received response.

If a valid Content-Length header field is present without Transfer-Encoding, its decimal value defines the expected
message body length in octets. If the sender closes the connection or the recipient times out before the indicated
number of octets are received, the recipient MUST consider the message to be incomplete and close the connection.

If this is a request message and none of the above are true, then the message body length is zero (no message body is present).
Otherwise, this is a response message without a declared message body length, so the message body length
is determined by the number of octets received prior to the server closing the connection.
Since there is no way to distinguish a successfully completed, close-delimited response message from a partially
received message interrupted by network failure, a server SHOULD generate encoding or length-delimited messages
whenever possible. The close-delimiting feature exists primarily for backwards compatibility with HTTP/1.0.

Note: Request messages are never close-delimited because they are always explicitly framed by
length or transfer coding, with the absence of both implying the request ends immediately after the header section.

A server MAY reject a request that contains a message body but not a Content-Length by responding with 411 (Length Required).

Unless a transfer coding other than chunked has been applied, a client that sends a request
containing a message body SHOULD use a valid Content-Length header field if the message body
length is known in advance, rather than the chunked transfer coding, since some existing services
respond to chunked with a 411 (Length Required) status code even though they understand the
chunked transfer coding. This is typically because such services are implemented via a gateway
that requires a content length in advance of being called, and the server is unable or unwilling
to buffer the entire request before processing.

A user agent that sends a request that contains a message body MUST send either a valid Content-Length
header field or use the chunked transfer coding. A client MUST NOT use the chunked transfer coding unless
it knows the server will handle HTTP/1.1 (or later) requests; such knowledge can be in the form of
specific user configuration or by remembering the version of a prior received response.

If the final response to the last request on a connection has been completely received and there
remains additional data to read, a user agent MAY discard the remaining data or attempt to determine
if that data belongs as part of the prior message body, which might be the case if the prior
message's Content-Length value is incorrect. A client MUST NOT process, cache, or forward such extra
data as a separate response, since such behavior would be vulnerable to cache poisoning.

7. Transfer Codings
Transfer coding names are used to indicate an encoding transformation that has been, can be, or might
need to be applied to a message's content in order to ensure "safe transport" through the network.
This differs from a content coding in that the transfer coding is a property of the message rather
than a property of the representation that is being transferred.

All transfer-coding names are case-insensitive and ought to be registered within the HTTP Transfer
Coding registry, as defined in Section 7.3. They are used in the Transfer-Encoding (Section 6.1)
and TE (Section 10.1.4 of [HTTP]) header fields (the latter also defining the "transfer-coding" grammar).

7.1. Chunked Transfer Coding
The chunked transfer coding wraps content in order to transfer it as a series of chunks,
each with its own size indicator, followed by an OPTIONAL trailer section containing trailer fields.
Chunked enables content streams of unknown size to be transferred as a sequence of length-delimited buffers,
which enables the sender to retain connection persistence and the recipient to know when
it has received the entire message.

  chunked-body   = *chunk
                   last-chunk
                   trailer-section
                   CRLF

  chunk          = chunk-size [ chunk-ext ] CRLF
                   chunk-data CRLF
  chunk-size     = 1*HEXDIG
  last-chunk     = 1*("0") [ chunk-ext ] CRLF

  chunk-data     = 1*OCTET ; a sequence of chunk-size octets

The chunk-size field is a string of hex digits indicating the size of the chunk-data in octets.
The chunked transfer coding is complete when a chunk with a chunk-size of zero is received,
possibly followed by a trailer section, and finally terminated by an empty line.

A recipient MUST be able to parse and decode the chunked transfer coding.

HTTP/1.1 does not define any means to limit the size of a chunked response such that an intermediary
can be assured of buffering the entire response. Additionally, very large chunk sizes may cause
overflows or loss of precision if their values are not represented accurately in a receiving implementation.
Therefore, recipients MUST anticipate potentially large hexadecimal numerals and prevent parsing
errors due to integer conversion overflows or precision loss due to integer representation.

The chunked coding does not define any parameters. Their presence SHOULD be treated as an error.

7.1.1. Chunk Extensions
The chunked coding allows each chunk to include zero or more chunk extensions, immediately
following the chunk-size, for the sake of supplying per-chunk metadata (such as a signature or hash),
mid-message control information, or randomization of message body size.

  chunk-ext      = *( BWS ";" BWS chunk-ext-name
                      [ BWS "=" BWS chunk-ext-val ] )

  chunk-ext-name = token
  chunk-ext-val  = token / quoted-string
The chunked coding is specific to each connection and is likely to be removed or recoded by
each recipient (including intermediaries) before any higher-level application would have a
chance to inspect the extensions. Hence, the use of chunk extensions is generally limited to
specialized HTTP services such as "long polling" (where client and server can have shared
expectations regarding the use of chunk extensions) or for padding within an end-to-end
secured connection.

A recipient MUST ignore unrecognized chunk extensions. A server ought to limit the total
length of chunk extensions received in a request to an amount reasonable for the services provided,
in the same way that it applies length limitations and timeouts for other parts of a message,
and generate an appropriate 4xx (Client Error) response if that amount is exceeded.

7.1.2. Chunked Trailer Section
A trailer section allows the sender to include additional fields at the end of a chunked
message in order to supply metadata that might be dynamically generated while the content is
sent, such as a message integrity check, digital signature, or post-processing status.
The proper use and limitations of trailer fields are defined in Section 6.5 of [HTTP].

  trailer-section   = *( field-line CRLF )
A recipient that removes the chunked coding from a message MAY selectively retain or
discard the received trailer fields. A recipient that retains a received trailer field
MUST either store/forward the trailer field separately from the received header fields
or merge the received trailer field into the header section. A recipient MUST NOT merge
a received trailer field into the header section unless its corresponding header field
definition explicitly permits and instructs how the trailer field value can be safely merged.

7.1.3. Decoding Chunked
A process for decoding the chunked transfer coding can be represented in pseudo-code as:

  length := 0
  read chunk-size, chunk-ext (if any), and CRLF
  while (chunk-size > 0) {
     read chunk-data and CRLF
     append chunk-data to content
     length := length + chunk-size
     read chunk-size, chunk-ext (if any), and CRLF
  }
  read trailer field
  while (trailer field is not empty) {
     if (trailer fields are stored/forwarded separately) {
         append trailer field to existing trailer fields
     }
     else if (trailer field is understood and defined as mergeable) {
         merge trailer field with existing header fields
     }
     else {
         discard trailer field
     }
     read trailer field
  }
  Content-Length := length
  Remove "chunked" from Transfer-Encoding
7.2. Transfer Codings for Compression
The following transfer coding names for compression are defined by the same
algorithm as their corresponding content coding:

compress (and x-compress)
See Section 8.4.1.1 of [HTTP].
deflate
See Section 8.4.1.2 of [HTTP].
gzip (and x-gzip)
See Section 8.4.1.3 of [HTTP].
The compression codings do not define any parameters. The presence of parameters with
any of these compression codings SHOULD be treated as an error.

7.3. Transfer Coding Registry
The "HTTP Transfer Coding Registry" defines the namespace for transfer coding names.
It is maintained at <https://www.iana.org/assignments/http-parameters>.

Registrations MUST include the following fields:

Name
Description
Pointer to specification text
Names of transfer codings MUST NOT overlap with names of content codings
(Section 8.4.1 of [HTTP]) unless the encoding transformation is identical,
as is the case for the compression codings defined in Section 7.2.

The TE header field (Section 10.1.4 of [HTTP]) uses a pseudo-parameter named "q"
as the rank value when multiple transfer codings are acceptable. Future registrations
of transfer codings SHOULD NOT define parameters called "q" (case-insensitively)
in order to avoid ambiguities.

Values to be added to this namespace require IETF Review (see Section 4.8 of [RFC8126])
and MUST conform to the purpose of transfer coding defined in this specification.

Use of program names for the identification of encoding formats is not desirable
and is discouraged for future encodings.

7.4. Negotiating Transfer Codings
The TE field (Section 10.1.4 of [HTTP]) is used in HTTP/1.1 to indicate what
transfer codings, besides chunked, the client is willing to accept in the response
and whether the client is willing to preserve trailer fields in a chunked transfer coding.

A client MUST NOT send the chunked transfer coding name in TE; chunked is always
acceptable for HTTP/1.1 recipients.

Three examples of TE use are below.

TE: deflate
TE:
TE: trailers, deflate;q=0.5
When multiple transfer codings are acceptable, the client MAY rank the codings by
preference using a case-insensitive "q" parameter (similar to the qvalues used in
content negotiation fields; see Section 12.4.2 of [HTTP]). The rank value is a real
number in the range 0 through 1, where 0.001 is the least preferred and 1 is the
most preferred; a value of 0 means "not acceptable".

If the TE field value is empty or if no TE field is present, the only acceptable
transfer coding is chunked. A message with no transfer coding is always acceptable.

The keyword "trailers" indicates that the sender will not discard trailer fields,
as described in Section 6.5 of [HTTP].

Since the TE header field only applies to the immediate connection, a sender of TE
MUST also send a "TE" connection option within the Connection header field (Section 7.6.1 of [HTTP])
in order to prevent the TE header field from being forwarded by
intermediaries that do not support its semantics.

8. Handling Incomplete Messages
A server that receives an incomplete request message, usually due to a canceled
request or a triggered timeout exception, MAY send an error response prior to
closing the connection.

A client that receives an incomplete response message, which can occur when a
connection is closed prematurely or when decoding a supposedly chunked transfer
coding fails, MUST record the message as incomplete. Cache requirements for
incomplete responses are defined in Section 3.3 of [CACHING].

If a response terminates in the middle of the header section (before the empty
line is received) and the status code might rely on header fields to convey the
full meaning of the response, then the client cannot assume that meaning has been
conveyed; the client might need to repeat the request in order to determine what action to take next.

A message body that uses the chunked transfer coding is incomplete if the zero-sized
chunk that terminates the encoding has not been received. A message that uses a valid
Content-Length is incomplete if the size of the message body received (in octets) is
less than the value given by Content-Length. A response that has neither chunked transfer
coding nor Content-Length is terminated by closure of the connection and, if the header
section was received intact, is considered complete unless an error was indicated
by the underlying connection (e.g., an "incomplete close" in TLS would leave
the response incomplete, as described in Section 9.8).
*/
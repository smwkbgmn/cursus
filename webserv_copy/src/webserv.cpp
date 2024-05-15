#include "webserv.hpp"

/*
	To do
	- CGI 
		Replace _wait NONE mode with WNOHANG
		> move the _read and _build to Client implementation 
		Correct Content_length when it found the CRLF

		Define a directory or a file from where the file should be searched (for example, if url /kapouet is rooted to /tmp/www, url /kapouet/pouic/toto/pouet is /tmp/www/pouic/toto/pouet)
		Execute CGI based on certain file extension (for example .php)
		Make the route able to accept uploaded files and configure where they should be saved
		ust remember that, for chunked request, your server needs to unchunk it, the CGI will expect EOF as end of the body
		Same things for the output of the CGI. If no content_length is returned from the CGI, EOF will mark the end of the returned data

    - Handle chunked request/response
	- Rewrite redirection
	- Implement cookies
		> RFC 6265

	Done
	- CGI
		Add building of argument and envs for CGI
		> retrieve the PATH_INFO and QUERY_STRING from the URI
		CGI header build
	- Make GET method to check all index files in case of target not found 
	- Replace buffers
	- Apply the client_max_body config
	- Apply corrected config structures
	- Add seeing how the file stat() is before proceeding HTTP methods
	- File upload
	- Add retrived location to Request obj after replace uri with real path
	- Redirect to error page in case of error in URI 

	Considertion
	- Would it fit well making header as map of enum header key and header value?
	it change the working of header list and values as combined one
	- Split buffer as in two of Request Line + Header Field and Body part
	- Take some time to think of what would happen when the request msg is splited
	by buffer size and it cause the fractured part at the end of request taht is
	resulting unavailable to find the "\r\n\r\n" while taking request
	- Add program option for toggle of logging
	- See if other connection headers should be handled 
	- When send response, intead of copying the body at the building message, 
	just build the msg and use body directly from the response object
*/

int main( void ) {
	try {
		HTTP::init();
		CGI::init();
		
		Server server;

		server.connectsever();
	} catch ( err_t &err ) { log( str_t( err.what() ) ); return EXIT_FAILURE; }

  return 0;
}
#include "utill.hpp"

/* UTILL */
bool found( const size_t& pos ) { return pos != str_t::npos; }

/* FILE INFO */
bool
getInfo( const str_t& target, fstat_t& info ) {
	if ( *target.rbegin() == '/' )
		return stat( target.substr( 0, target.length() - 1 ).c_str(), &info ) != ERROR;
		
	return stat( target.c_str(), &info ) != ERROR;
}

bool
isExist( const str_t& target ) {
	fstat_t	info;

	return stat( target.c_str(), &info ) != ERROR && !isDir( info );
}

bool isDir( const fstat_t& info ) { return S_ISDIR( info.st_mode ); }

/* BUILT-IN SCRIPT */
void
errpageScript( sstream_t& page, const uint_t& status, const str_t& explanation ) {
	page <<
	"<!DOCTYPE html>\n"
	"<html lang=\"en\">\n"
	"<head>\n"
	"<meta charset=\"UTF-8\">\n"
	"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
	"<title>HTTP Response</title>\n"
	"<style>\n"
	"body {\n"
	"font-family: Arial, sans-serif;\n"
	"margin: 0;\n"
	"padding: 20px;\n"
	"}\n"
	".container {\n"
	"max-width: 800px;\n"
	"margin: 50px auto;\n"
	"background-color: #f4f4f4;\n"
	"padding: 20px;\n"
	"border-radius: 5px;\n"
	"box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);\n"
	"overflow: auto;\n"
	"positon: relative;\n"
	"}\n"
	"h1 {\n"
	"color: #007bff;\n"
	"}\n"
	"p {\n"
	"margin-bottom: 20px;\n"
	"}\n"
	".image-container {\n"
	"position: absolute;\n"
	"bottom: 20px;\n"
	"right: 25px;\n"
	"}\n"
	"img {\n"
	"width: 100px;\n"
	"height: auto;\n"
	"}\n"
	"</style>\n"
	"</head>\n"
	"<body>\n"
	"<div class=\"container\">\n"
	"<h1>HTTP responsing with error state</h1>\n"
	"<div class=\"image-container\">"
    "<img src=\"favicon.ico\" alt=\"Image\">"
	"</div>"
	"<p><strong>Status Code:</strong> " << status << "</p>\n" <<
	"<p><strong>Explanation:</strong> " << explanation << "</p>\n" <<
	"</div>\n"
	"</body>\n"
	"</html>";
}

#include <sys/types.h>
#include <dirent.h>

void
autoindexScript(const path_t& dir_path, sstream_t& body ) {
    DIR* dir = opendir( dir_path.c_str() );
    if ( !dir )
        throwSysErr( "opendir", 500 );

	body <<
	"<!DOCTYPE html>\n"
	"<html lang=\"en\">\n"
	"<head>\n"
	"<meta charset=\"UTF-8\">\n"
	"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
	"<title>Directory Listing</title>\n"
	"<style>\n"
	"body {\n"
	"font-family: Arial, sans-serif;\n"
	"margin: 20px;\n"
	"}\n"
	"h1 {\n"
	"margin-bottom: 20px;\n"
	"}\n"
	"ul {\n"
	"list-style-type: none;\n"
	"padding: 0;\n"
	"}\n"
	"li {\n"
	"margin-bottom: 5px;\n"
	"}\n"
	"a {\n"
	"color: #007bff;\n"
	"text-decoration: none;\n"
	"}\n"
	"a:hover {\n"
	"text-decoration: underline;\n"
	"}\n"
	"</style>\n"
	"</head>\n"
	"<body>\n"
	"<h1>Directory Listing</h1>\n"
	"<ul>\n";

    struct dirent* entry;
    while ( ( entry = readdir( dir ) ) != NULL ) {
        str_t file_name = entry->d_name;

        if (file_name != "." && file_name != ".." ) {
            str_t file_path = dir_path + "/" + file_name;

            if ( entry->d_type == DT_DIR )
                body << "<li><strong>[DIR] </strong><a href=\"" << file_name << "/\">" << file_name << "</a></li>\n";
            else
                body << "<li><a href=\"" << file_name << "\">" << file_name << "</a></li>\n";
        }
    }

    body <<
	"</ul>\n"
	"</body>\n"
	"</html>\n";

    closedir( dir );
}

#include "HTTP.hpp"
#include "CGI.hpp"

/*
	#define __DARWIN_STRUCT_STAT64 { \
		dev_t		st_dev;                 [XSI] ID of device containing file
		mode_t		st_mode;                [XSI] Mode of file (see below)
		nlink_t		st_nlink;               [XSI] Number of hard links
		__darwin_ino64_t st_ino;            [XSI] File serial number
		uid_t		st_uid;                 [XSI] User ID of the file
		gid_t		st_gid;                 [XSI] Group ID of the file
		dev_t		st_rdev;                [XSI] Device ID
		__DARWIN_STRUCT_STAT64_TIMES \
		off_t		st_size;                [XSI] file size, in bytes
		blkcnt_t	st_blocks;              [XSI] blocks allocated for file
		blksize_t	st_blksize;             [XSI] optimal blocksize for I/O
		__uint32_t	st_flags;               user defined flags for file
		__uint32_t	st_gen;                 file generation number
		__int32_t	st_lspare;              RESERVED: DO NOT USE!
		__int64_t	st_qspare[2];           RESERVED: DO NOT USE!
	}
*/

// When fail to get all of default index files, set status as 403 forbidden
void
HTTP::GET( const Request& rqst, char** bufptr, size_t& size ) {
 	if ( _cgiGet( rqst ) )
		CGI::GET( rqst, bufptr, size );

	else {
		try {
			File target( rqst.config().root + rqst.line().uri, R_BINARY );

			// std::filebuf* pbuf = target.fs.rdbuf();
			// size = pbuf->pubseekoff( 0, target.fs.end, target.fs.in );
			// pbuf->pubseekpos( 0, target.fs.in );

			// char *buf = new char[size];
			// pbuf->sgetn( buf, size );
			
			// *bufptr = buf;
			*bufptr = dupIOBuf( target.fs, size );
		} catch ( exception_t& exc ) { logfile.fs << exc.what() << '\n'; throw errstat_t( 404 ); }
	}
}

void
HTTP::GET( const str_t& uri, char** bufptr, size_t& size ) {
	try {
		File target( uri, R_BINARY );

		std::filebuf* pbuf = target.fs.rdbuf();
		size = pbuf->pubseekoff( 0, target.fs.end, target.fs.in );
		pbuf->pubseekpos( 0, target.fs.in );

		char *buf = new char[size];
		pbuf->sgetn( buf, size );
		
		*bufptr = buf;
	} catch ( exception_t& exc ) { logfile.fs << exc.what() << '\n'; throw errstat_t( 204 ); }
}
 
void
HTTP::POST( const Request& rqst, char** bufptr, size_t& size ) {
	if ( _cgiGet( rqst ) )
		CGI::POST( rqst, bufptr, size );

	else {
		try {
			File target( rqst.config().root + rqst.line().uri, W );

			target.fs << rqst.body();
		} catch ( exception_t& exc ) { logfile.fs << exc.what() << '\n'; throw errstat_t( 400 ); }
	}
}

void
HTTP::DELETE( const Request& rqst ) {
	// stat_t	statbuf;

	// if ( stat( rqst.line().uri.c_str(), &statbuf ) != ERROR )
	if ( std::remove( ( rqst.config().root + rqst.line().uri ).c_str() ) == ERROR )
		throw errstat_t( 404 );

	// return FALSE;
}

bool
HTTP::_cgiGet( const Request& rqst ) {
	return rqst.config().location == HTTP::http.locationCGI ||
		*rqst.line().uri.rbegin() == '/';
}

bool
HTTP::_cgiPost( const Request& rqst ) {
	size_t posDot = rqst.line().uri.rfind( '.' );
	return rqst.line().uri.substr( posDot ) == ".exe";
}

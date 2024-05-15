#include "File.hpp"

File::File( const std::string& fileName, int mode ) {
	switch ( mode ) {
		case READ			: fs.open( fileName.c_str(), std::ios::in ); break;
		case READ_BINARY	: fs.open( fileName.c_str(), std::ios::in | std::ios::binary ); break;
		case WRITE			: fs.open( fileName.c_str(), std::ios::out ); break;
		case WRITE_APP		: fs.open( fileName.c_str(), std::ios::out | std::ios::app ); break;
		default: throw std::runtime_error( "unknown mode" );
	}

	if ( !fs.is_open() )
		throw std::ios_base::failure( "open: fail to open " + fileName );
}

File::~File( void ) { fs.close(); }

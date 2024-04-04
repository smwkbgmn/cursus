#include "File.hpp"

File::File( const std::string& fileName, int mode ) {
	switch ( mode ) {
		case R: fs.open( fileName.c_str(), std::fstream::in ); break;
		case R_BINARY: fs.open( fileName.c_str(), std::ios::in | std::ios::binary ); break;
		case W: fs.open( fileName.c_str(), std::fstream::out ); break;
		default: throw std::runtime_error( "unknown mode" );
	}

	if ( !fs.is_open() )
		throw std::ios_base::failure( "open: fail to open " + fileName );
}

File::~File( void ) { fs.close(); }

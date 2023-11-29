#include <iostream>

#include "FileStream.hpp"

FileStream::FileStream( const str_t &fname ) 
{
	is.open( fname );
	if (is.fail())
		std::cerr << "error: fail to open file " << fname << std::endl;
	else
	{
		os.open( fname + ".replace" );
		if (os.fail())
		{
			std::cerr << "error: fail to create outfile for " << fname << std::endl;
			is.close();
		}
	}
}

FileStream::~FileStream( void )
{
	if (is && os)
	{
		is.close();
		os.close();
	}
}

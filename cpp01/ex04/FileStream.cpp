#include <iostream>

#include "FileStream.hpp"

static str_t	&change( str_t &, const str_t &, const str_t & );

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
	is.close();
	os.close();
}

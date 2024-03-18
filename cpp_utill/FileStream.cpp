#include <iostream>

#include "FileStream.hpp"

FileStream::FileStream( const str_t &fname ) 
{
	in.open( fname.c_str() );
	if (in.fail())
		std::cerr << "error: fail to open file " << fname << std::endl;
	else
	{
		out.open( (fname + ".replace").c_str() );
		if (out.fail())
		{
			std::cerr << "error: fail to create outfile for " << fname << std::endl;
			in.close();
		}
	}
}

FileStream::~FileStream( void )
{
	if (in && out)
	{
		in.close();
		out.close();
	}
}

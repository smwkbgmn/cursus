#include <iostream>

#include "FileStream.hpp"

static str_t	&change( str_t &, const str_t &, const str_t & );

FileStream::FileStream( const str_t &fname ) 
{
	_ifs.open(fname);
	if (_ifs.fail())
		std::cerr << "error: fail to open file " << fname << std::endl;
	else
	{
		_ofs.open(fname + ".replace");
		if (_ofs.fail())
		{
			std::cerr << "error: fail to create outfile for " << fname << std::endl;
			_ifs.close();
		}
	}
}

FileStream::~FileStream( void )
{
	_ifs.close();
	_ofs.close();
}

std::ifstream &FileStream::getIn( void )
{
	return _ifs;
}

std::ofstream &FileStream::getOut( void )
{
	return _ofs;
}


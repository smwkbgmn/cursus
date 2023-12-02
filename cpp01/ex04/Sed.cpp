#include <iostream>

#include "Sed.hpp"

bool Sed::valid( int argc, char *argv[] )
{
	str_t	str;

	if (argc == 4)
	{
		if (!str.assign( argv[1] ).empty()
			&& !str.assign( argv[2] ).empty())
			return TRUE;
		std::cout << "you may not enter empty string to fname and target" << std::endl;
	}
	else
		std::cout << "please enter 3 argument (fname, target, replacement)" << std::endl;
	return FALSE;
}

void Sed::proceed( char *argv[] )
{
	FileStream	fs( argv[1] );
	str_t		line;

	if (fs.in && fs.out)
	{
		while (std::getline( fs.in, line ))
		{
			fs.out << change( line, argv[2], argv[3] );
			if (!fs.in.eof())
				fs.out << '\n';
		}
		if (!fs.in.eof())
			std::cerr << "error: fail to read from a file" << std::endl;
	}
}

str_t &Sed::change( str_t &line, const str_t &target, const str_t &replace )
{
	size_t	len_target = target.length();
	size_t	pos = 0;

	if (target != replace)
	{
		while ((pos = line.find( target, pos )) != str_t::npos)
		{
			line.erase( pos, len_target );
			line.insert( pos, replace );
		}
	}
	return line;
}

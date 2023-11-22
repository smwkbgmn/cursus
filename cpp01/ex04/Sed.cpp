#include <iostream>

#include "Sed.hpp"

static str_t &change( str_t &, const str_t &, const str_t & );

Sed::Sed( const str_t &fname, const str_t &target, const str_t &replace )
: _fs(fname), _target(target), _replace(replace)
{
}

void Sed::proceed( void )
{
	std::ifstream	&ifs = _fs.getIn();
	std::ofstream	&ofs = _fs.getOut();
	str_t			line;

	if (ifs && ofs)
	{
		while (std::getline(ifs, line))
		{
			ofs << change(line, _target, _replace);
			if (!ifs.eof())
				ofs << '\n';
		}
		if (!ifs.eof())
			std::cerr << "error: fail to read from a file" << std::endl;
	}
}

static str_t &change( str_t &line, const str_t &target, const str_t &replace )
{
	size_t	len_target = target.length();
	size_t	pos = 0;

	if (target != replace)
	{
		while ((pos = line.find(target, pos)) != str_t::npos)
		{
			line.erase(pos, len_target);
			line.insert(pos, replace);
		}
	}
	return line;
}

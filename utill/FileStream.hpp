#ifndef FILESTREAM_HPP
# define FILESTREAM_HPP

# include <string>
# include <fstream>

typedef std::string	str_t;

struct FileStream
{
	std::ifstream	in;
	std::ofstream	out;

	FileStream( const str_t & );
	~FileStream( void );
};

#endif
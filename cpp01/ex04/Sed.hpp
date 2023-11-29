#ifndef SED_HPP
# define SED_HPP

# include "FileStream.hpp"

# define FALSE 0
# define TRUE 1

class Sed
{
	public:
		static bool	valid( int argc, char *argv[] );
		static void	proceed( char *argv[] );

	private:
		static str_t	&change( str_t &line, const str_t &target, const str_t &replace );
};

#endif
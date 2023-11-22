#include <iostream>

#include "Sed.hpp"

#define FALSE 0
#define TRUE 1

static bool	valid( int, char *[] );
static void	sed( char *[] );

int main( int argc, char *argv[] )
{
	if (valid(argc, argv))
		sed(argv);

	return 0;
}

static bool valid( int argc, char *argv[] )
{
	str_t	str;

	if (argc == 4)
	{
		if (!str.assign(argv[1]).empty()
			&& !str.assign(argv[2]).empty())
			return TRUE;
		std::cout << "you may not enter empty string to fname and target" << std::endl;
	}
	std::cout << "please enter 3 argument (fname, target, replacement)" << std::endl;
	return FALSE;
}

static void sed( char *argv[] )
{
	Sed		data(argv[1], argv[2], argv[3]);

	data.proceed();
}

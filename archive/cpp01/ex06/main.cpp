#include "Harl.hpp"

int main( int argc, char *argv[] )
{
	Harl		harl;
	std::string	level;

	if (argc == 2)
		harl.complain( level.assign( argv[1] ) );

	return 0;
}
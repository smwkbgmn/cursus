#include "ScalarConverter.hpp"

/*
	- Common
	Overflow
	impossible

	- Specific
	char: Non displayable
	float: +-inff, nanf
	double: +-inf, nan
*/

int main( int argc, char *argv[] )
{
	if (argc == 2)
		ScalarConverter::convert( *(argv + 1) );

	return 0;
}
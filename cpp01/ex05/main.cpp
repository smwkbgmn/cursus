#include <iostream>

#include "Harl.hpp"

int main( void )
{
	Harl	harl;

	harl.complain("DEBUG");
	std::cout << '\n';
	harl.complain("INFO");
	std::cout << '\n';
	harl.complain("WARNING");
	std::cout << '\n';
	harl.complain("ERROR");

	harl.complain("NOT EXIST");
}
#include <iostream>

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	clap1;
	ClapTrap	clap2 = clap1;

	std::cout << std::endl;

	ClapTrap	clap3("Pete");
	ClapTrap	clap4(clap3);

	std::cout << std::endl;

	ClapTrap	pete("pete");
	ClapTrap	harry("harry");

	std::cout << std::endl;

	pete.attack(harry.getName());
	harry.takeDamage(pete.getDamage());

	std::cout << std::endl;
	
	pete.takeDamage(100);
	pete.beRepaired(100);

	std::cout << std::endl;

	harry.beRepaired(351);

	std::cout << std::endl;

	return 0;
}

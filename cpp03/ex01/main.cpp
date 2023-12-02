#include <iostream>

#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap	pete("pete");
	ScavTrap	harry("harry");

	std::cout << std::endl;
	
	pete.attack(harry.getName());
	harry.takeDamage(pete.getDamage());

	std::cout << std::endl;

	harry.attack(pete.getName());
	pete.takeDamage(harry.getDamage());
	
	std::cout << std::endl;

	harry.guardGate();

	std::cout << std::endl;

	return 0;
}

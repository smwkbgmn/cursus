#include <iostream>

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	pete("pete");
	ClapTrap	harry("harry");
	ClapTrap	pete_clone(pete);

	pete.attack("harry");
	harry.takeDamage(pete.getDamage());
	
	harry.beRepaired(351);

	harry.takeDamage(1200);
	harry.beRepaired(100);

	return 0;
}

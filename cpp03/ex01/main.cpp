#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	// ScavTrap	scav1;
	// ScavTrap	scav2 = scav1;
	// ScavTrap	scav3("Pete");

	ScavTrap	*scav = new ScavTrap;
	ClapTrap	*clap = scav;

	delete clap;

	return 0;
}

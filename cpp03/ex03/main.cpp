#include <iostream>

#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap	dia;

	dia.whoAmI();
	dia.guardGate();
	dia.highFivesGuys();

	dia.attack( "hello" );
	dia.takeDamage(125);
	dia.beRepaired(50);

	dia = DiamondTrap("pete");

	return 0;
}

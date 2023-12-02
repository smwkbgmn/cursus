#include <iostream>

#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap	dia1("pete");
	DiamondTrap dia2;

	std::cout << std::endl;

	dia1.whoAmI();
	dia2.whoAmI();

	std::cout << std::endl;

	dia1.guardGate();
	dia2.highFivesGuys();

	std::cout << std::endl;

	for (int cnt = 0; cnt < 4; ++cnt)
	{
		dia1.attack(dia2.getName());
		dia2.takeDamage(dia1.getDamage());
	}

	std::cout << std::endl;

	dia1.beRepaired(1000);
	dia2.beRepaired(1000);

	std::cout << std::endl;

	return 0;
}

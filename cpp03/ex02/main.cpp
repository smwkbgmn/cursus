#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap	frag("pete");
	ScavTrap	scav("harry");

	std::cout << std::endl;

	frag.attack(scav.getName());
	scav.takeDamage(frag.getDamage());

	std::cout << std::endl;

	scav.attack(frag.getName());
	frag.takeDamage(scav.getDamage());

	std::cout << std::endl;

	frag.beRepaired(100);
	scav.beRepaired(100);

	std::cout << std::endl;

	scav.guardGate();
	frag.highFivesGuys();

	std::cout << std::endl;

	return 0;
}

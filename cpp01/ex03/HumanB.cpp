#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
: _name(name), _weapon(NULL)
{
}

void HumanB::setWeapon( Weapon &weapon )
{
	_weapon = &weapon;
	std::cout << _name << " armed a " << _weapon->getType() << std::endl;
}

void HumanB::attack( void )
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " doesn't have any weapon" << std::endl;
}
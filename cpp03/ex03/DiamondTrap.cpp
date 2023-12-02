#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	initAttr();

	std::cout << "[CON-DEF] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap( const str_t &name )
: ClapTrap(name + "_clap_name"), _name(name)
{
	initAttr();

	std::cout << "[CON-NME] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &target )
: ClapTrap(), FragTrap(), ScavTrap()
{
	*this = target;

	std::cout << "[CON-CPY] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}
DiamondTrap::~DiamondTrap( void )
{
	std::cout << "[DES] ";	
	printName();
	std::cout << "has destroyed ";
	printAttr();
	std::cout << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap &target )
{
	std::cout << "[DiamondTrap's Copy assignment called]" << std::endl;

	if (this != &target)
	{
		_name = target.getDiaName();
		ClapTrap::_name = target.getName();
		ClapTrap::_hit = target.getHit();
		ClapTrap::_energy = target.getEnergy();
		ClapTrap::_damage =target.getDamage();
	}
	return *this;
}

str_t DiamondTrap::getDiaName( void ) const
{
	return _name;
}

void DiamondTrap::whoAmI( void )
{
	printName();
	if (_hit)
		std::cout << "has second name \"" << ClapTrap::_name << '"' << std::endl;
	else
		std::cout << "is already dead" << std::endl;
}

void DiamondTrap::initAttr( void )
{
	_damage = 30;
}

void DiamondTrap::printName( void )
{
	std::cout << "DiamondTrap \"" << _name << "\" ";
}

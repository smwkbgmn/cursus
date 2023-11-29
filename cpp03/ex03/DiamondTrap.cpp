#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
// : ClapTrap("_unnamed__clap_name"), _name("_unnamed_")
{
	_name = "_unnamed_";
	ClapTrap::_name = _name + "_clap_name";
	initAttr();

	std::cout << "[CON-DEF] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap( const str_t &name )
// : ClapTrap(name + "_clap_name"), _name(name)
{
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	initAttr();

	std::cout << "[CON-NME] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &target )
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

void DiamondTrap::attack( const str_t &target )
{
	ScavTrap::attack( target );
}

void DiamondTrap::initAttr( void )
{
	_damage = 30;
}

void DiamondTrap::printName( void )
{
	std::cout << "DiamondTrap " << _name << " ";
}

void DiamondTrap::whoAmI( void )
{
	if (available())
	{
		std::cout << "DiamondTrap " << _name
			<< "has second name " << ClapTrap::_name << std::endl;
	}
}
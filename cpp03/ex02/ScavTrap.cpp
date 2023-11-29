#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
: ClapTrap(100, 50, 20)
{
	std::cout << "[CON-DEF] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

ScavTrap::ScavTrap( const str_t &name )
: ClapTrap(name, 100, 50, 20)
{
	std::cout << "[CON-NME] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &target )
{
	*this = target;

	std::cout << "[CON-CPY] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "[DES] ";	
	printName();
	std::cout << "has destroyed ";
	printAttr();
	std::cout << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &target )
{
	std::cout << "[Copy assignment called]" << std::endl;
	
	if (this != &target)
	{
		_name = target.getName();
		_hit = target.getHit();
		_energy = target.getEnergy();
		_damage = target.getDamage();
	}

	return *this;
}

void ScavTrap::attack( const str_t &name )
{
	if (available())
	{
		_energy--;

		printName();
		std::cout << "attacks " << name << ", ";
		std::cout << "causing " << _damage << " points of damage!";
		std::cout << std::endl;
	}
}

void ScavTrap::guardGate( void )
{
	if (available())
	{
		printName();
		std::cout << " is now in Gatekepper mode";
		std::cout << std::endl; 
	}
}

void ScavTrap::printName( void )
{
	std::cout << "ScavTrap " << _name << " ";
}
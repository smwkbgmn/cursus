#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	initAttr();

	std::cout << "[CON-DEF] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

ScavTrap::ScavTrap( const str_t &name )
: ClapTrap(name)
{
	initAttr();

	std::cout << "[CON-NME] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &target )
: ClapTrap(target)
{
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
	std::cout << "[ScavTrap's Copy assignment called]" << std::endl;
	
	if (this != &target)
		ClapTrap::operator=(target);

	return *this;
}

void ScavTrap::attack( const str_t &name )
{
	if (available())
	{
		_energy--;

		printName();
		std::cout << "attacks \"" << name << "\", ";
		std::cout << "causing " << _damage << " points of damage!";
		std::cout << std::endl;
	}
}

void ScavTrap::guardGate( void )
{
	printName();
	if (_hit)
		std::cout << "is now in Gatekepper mode" << std::endl; 
	else
		std::cout << "is already dead" << std::endl;
}

void ScavTrap::initAttr( void )
{
	_hit = 100;
	_energy = 50;
	_damage = 20;
}

void ScavTrap::printName( void )
{
	std::cout << "ScavTrap \"" << _name << "\" ";
}

bool ScavTrap::available( void )
{
	if (_hit && _energy)
		return TRUE;
	else
	{
		printName();
		if (!_hit)
			std::cout << "is already dead" << std::endl;
		else
			std::cout << "has no energy" << std::endl;
		return FALSE;
	}
}
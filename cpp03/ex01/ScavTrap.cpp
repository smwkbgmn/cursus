#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	_hit = 100;
	_energy = 50;
	_damage = 20;

	std::cout << "[CON-DEF] ";
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

ScavTrap::ScavTrap( const str_t &name )
{
	_name = name;
	_hit = 100;
	_energy = 50;
	_damage = 20;

	std::cout << "[CON-NME] ";
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
	std::cout << "Copy assignment called" << std::endl;
	
	if (this != &target)
	{
		_name = target.getName();
		_hit = target.getHit();
		_energy = target.getEnergy();
		_damage = target.getDamage();
	}

	return *this;
}

void ScavTrap::guardGate( void )
{
	printName();
	std::cout << " is now in Gatekepper mode";
	std::cout << std::endl; 
}

void ScavTrap::printName( void )
{
	std::cout << "ScavTrap ";
	if (!_name.empty())
		std::cout << _name;
	else
		std::cout << "_unnamed_";
	 std::cout << " ";
}
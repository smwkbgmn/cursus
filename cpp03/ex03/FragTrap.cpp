#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	initAttr();	

	std::cout << "[CON-DEF] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

FragTrap::FragTrap( const str_t &name )
: ClapTrap(name)
{
	initAttr();

	std::cout << "[CON-NME] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

FragTrap::FragTrap( const FragTrap &target )
{
	*this = target;

	std::cout << "[CON-CPY] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "[DES] ";	
	printName();
	std::cout << "has destroyed ";
	printAttr();
	std::cout << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &target )
{
	std::cout << "[FragTrap's Copy assignment called]" << std::endl;

	if (this != &target)
	{
		_name = target.getName();
		_hit = target.getHit();
		_energy = target.getEnergy();
		_damage = target.getDamage();
	}

	return *this;
}

void FragTrap::attack( const str_t &name )
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

void FragTrap::highFivesGuys( void )
{
	if (available())
	{
		printName();
		std::cout << "raised hands up for HighFives!!";
		std::cout << std::endl; 
	}
}

void FragTrap::initAttr( void )
{
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

void FragTrap::printName( void )
{
	std::cout << "FragTrap " << _name << ' ';
}
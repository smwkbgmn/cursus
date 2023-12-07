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
: ClapTrap(target)
{
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
		ClapTrap::operator=(target);

	return *this;
}

void FragTrap::highFivesGuys( void )
{
	printName();
	if (_hit)
		std::cout << "positively raised hands up for HighFives!!" << std::endl; 
	else
		std::cout << "is already dead" << std::endl;
}

void FragTrap::initAttr( void )
{
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

void FragTrap::printName( void )
{
	std::cout << "FragTrap \"" << _name << "\" ";
}

#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
: _hit(10), _energy(10), _damage(0)
{
	std::cout << "[CON-DEF] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

ClapTrap::ClapTrap( const str_t &name )
: _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << "[CON-NME] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &target )
{
	*this = target;

	std::cout << "[CON-CPY] ";
	printName();
	std::cout << "has created ";
	printAttr();
	std::cout << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "[DES] ";
	printName();
	std::cout << "has destroyed ";
	printAttr();
	std::cout << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &target )
{
	std::cout << "[ClapTrap's Copy assignment called]" << std::endl;

	if (this != &target)
	{
		_name = target.getName();
		_hit = target.getHit();
		_energy = target.getEnergy();
		_damage = target.getDamage();
	}

	return *this;
}

str_t ClapTrap::getName( void ) const
{
	return _name;
}
point_t ClapTrap::getHit( void ) const
{
	return _hit;
}
point_t ClapTrap::getEnergy( void ) const
{
	return _energy;
}
point_t ClapTrap::getDamage( void ) const
{
	return _damage;
}

void ClapTrap::attack( const str_t &name )
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

void ClapTrap::takeDamage( point_t amount )
{
	if (available())
	{
		_hit = _hit > amount? _hit - amount : 0;
		
		printName();
		std::cout << "has taked " << amount << " damage!";
		std::cout << " (healthPoint changed to " << _hit << ")";
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired( point_t amount )
{
	if (available())
	{
		_hit += amount;
		_energy--;

		printName();
		std::cout << "repaired " << amount << " health point!";
		std::cout << std::endl;
	}
}

void ClapTrap::printName( void )
{
	std::cout << "ClapTrap \"" << _name << "\" ";
}

void ClapTrap::printAttr( void )
{
	std::cout << "(" << _hit << ", ";
	std::cout << _energy << ", ";
	std::cout << _damage << ")";
}

bool ClapTrap::available( void )
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
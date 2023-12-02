#include <new>
#include <iostream>

#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << "[CON_DEF] Dog created" << std::endl;

	_type = "Dog";
	_brain = new (std::nothrow) Brain;
}

Dog::Dog( const Dog &target )
{
	std::cout << "[CON_CPY] Dog created" << std::endl;

	_brain = new (std::nothrow) Brain;
	*this = target;
}

Dog::~Dog( void )
{
	if (_brain)
		delete _brain;

	std::cout << "[DES] Dog destroyed" << std::endl;
}

Dog &Dog::operator=( const Dog &target )
{
	std::cout << "[Dog's copy assignment called]" << std::endl;

	if (this != &target )
	{
		_type = target._type;
		if (_brain && target._brain)
			*_brain = *target._brain;
	}
	
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Wearl Wearl!" << std::endl;
}

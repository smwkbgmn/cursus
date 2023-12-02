#include <iostream>

#include "Dog.hpp"

Dog::Dog( void )
{
	_type = "Dog";

	std::cout << "[CON_DEF] Dog created" << std::endl;
}

Dog::Dog( const Dog &target )
{
	*this = target;

	std::cout << "[CON_CPY] Dog created" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "[DES] Dog destroyed" << std::endl;
}

Dog &Dog::operator=( const Dog &target )
{
	std::cout << "[Dog's copy assignment called]" << std::endl;

	if (this != &target )
		_type = target._type;
	
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Wearl Wearl!" << std::endl;
}

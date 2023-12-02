#include <iostream>

#include "Cat.hpp"

Cat::Cat( void )
{
	_type = "Cat";
	_brain = new (std::nothrow) Brain;

	std::cout << "[CON_DEF] Cat created" << std::endl;
}

Cat::Cat( const Cat &target )
{
	*this = target;

	std::cout << "[CON_CPY] Cat created" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "[DES] Cat destroyed" << std::endl;
}

Cat &Cat::operator=( const Cat &target )
{
	std::cout << "[Cat's copy assignment called]" << std::endl;

	if (this != &target )
	{
		_type = target._type;
		_brain = target._brain;
	}
	
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Nyaong............." << std::endl;
}

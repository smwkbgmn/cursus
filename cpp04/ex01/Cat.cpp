#include <new>
#include <iostream>

#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << "[CON_DEF] Cat created" << std::endl;

	_type = "Cat";
	_brain = new (std::nothrow) Brain;
}

Cat::Cat( const Cat &target )
{
	std::cout << "[CON_CPY] Cat created" << std::endl;

	_brain = new (std::nothrow) Brain;
	*this = target;
}

Cat::~Cat( void )
{
	if (_brain)
		delete _brain;

	std::cout << "[DES] Cat destroyed" << std::endl;
}

Cat &Cat::operator=( const Cat &target )
{
	std::cout << "[Cat's copy assignment called]" << std::endl;

	if (this != &target )
	{
		_type = target._type;
		if (_brain && target._brain)
			*_brain = *target._brain;
	}
	
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Nyaong............." << std::endl;
}

#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "[CON_DEF] WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &target )
{
	*this = target;

	std::cout << "[CON_CPY] WrongAnimal created" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "[DES] WrongAnimal destroyed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &target )
{
	_type = target._type;

	std::cout << "[WrongAnimal's copy assignment called]" << std::endl;
	
	return *this;
}

const std::string	&WrongAnimal::getType( void ) const
{
	return _type;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "What WrongAnimal do you prefer?" << std::endl;
}

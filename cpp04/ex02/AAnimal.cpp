#include <iostream>

#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
	std::cout << "[CON_DEF] AAnimal created" << std::endl;
}

AAnimal::AAnimal( const AAnimal &target )
{
	*this = target;

	std::cout << "[CON_CPY] AAnimal created" << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "[DES] AAnimal destroyed" << std::endl;
}

AAnimal &AAnimal::operator=( const AAnimal &target )
{
	_type = target._type;

	std::cout << "[AAnimal's copy assignment called]" << std::endl;
	
	return *this;
}

const std::string	&AAnimal::getType( void ) const
{
	return _type;
}

#include <iostream>

#include "Animal.hpp"

Animal::Animal( void )
{
	std::cout << "[CON_DEF] Animal created" << std::endl;
}

Animal::Animal( const Animal &target )
{
	std::cout << "[CON_CPY] Animal created" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "[DES] Animal destroyed" << std::endl;
}

Animal &Animal::operator=( const Animal &target )
{
	std::cout << "[Animal's copy assignment called]" << std::endl;
	
	return *this;
}

const std::string	&Animal::getType( void ) const
{
	return _type;
}

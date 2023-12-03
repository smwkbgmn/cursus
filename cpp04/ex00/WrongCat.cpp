#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	_type = "WrongCat";

	std::cout << "[CON_DEF] WrongCat created" << std::endl;
}

WrongCat::WrongCat( const WrongCat &target )
: WrongAnimal()
{
	*this = target;

	std::cout << "[CON_CPY] WrongCat created" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "[DES] WrongCat destroyed" << std::endl;
}

WrongCat &WrongCat::operator=( const WrongCat &target )
{
	std::cout << "[WrongCat's copy assignment called]" << std::endl;

	if (this != &target )
		_type = target.getType();
	
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Nyaong............." << std::endl;
}

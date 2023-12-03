#include "Ice.hpp"

Ice::Ice( void )
{
	_type = "ice";

	std::cout << "[CON-DEF] Ice has created" << std::endl;
}

Ice::Ice( const Ice &target )
{
	*this = target;

	std::cout << "[CON-CPY] Ice has created" << std::endl;
}

Ice::~Ice( void )
{
	std::cout << "[DES] Ice has destroyed" << std::endl;
}

Ice &Ice::operator=( const Ice &target )
{
	std::cout << "[Ice's copy assignment called]" << std::endl;

	if (this != &target )
		_type = target.getType();

	return *this;
}

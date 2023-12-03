#include "Cure.hpp"

Cure::Cure( void )
{
	_type = "Cure";

	std::cout << "[CON-DEF] Cure has created" << std::endl;
}

Cure::Cure( const Cure &target )
{
	*this = target;

	std::cout << "[CON-CPY] Cure has created" << std::endl;
}

Cure::~Cure( void )
{
	std::cout << "[DES] Cure has destroyed" << std::endl;
}

Cure &Cure::operator=( const Cure &target )
{
	std::cout << "[Cure's copy assignment called]" << std::endl;

	if (this != &target)
		_type = target.getType();
}

#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria( void )
{
	std::cout << "[CON-DEF] AMateria has created" << std::endl;
}

AMateria::AMateria( str_t const &type )
: _type(type)
{
	std::cout << "[CON-CPY] AMateria has created" << std::endl;
}

AMateria::AMateria( const AMateria &target )
{
	*this = target;

	std::cout << "[CON-CPY] AMateria has created" << std::endl;
}

AMateria::~AMateria( void )
{
	std::cout << "[DES] AMateria has destroyed" << std::endl;
}

const AMateria	&AMateria::operator=( const AMateria &target )
{
	std::cout << "[AMateria's copy assignment called]" << std::endl;
	
	if (this != &target)
		_type = target.getType();

	return *this;
}

str_t const	&AMateria::getType( void ) const
{
	return _type;
}

void AMateria::use( ICharacter &character )
{
	std::cout << "AMateria has no type. Nothings' happened to " << character.getName() << std::endl; 
}

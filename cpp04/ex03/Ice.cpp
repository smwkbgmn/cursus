// #include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice( void )
: AMateria( "ice" )
{
	std::cout << "[CON-DEF] Ice has created" << std::endl;
}

Ice::Ice( const Ice &target )
: AMateria( target )
{
	std::cout << "[CON-CPY] Ice has created" << std::endl;
}

Ice::~Ice( void )
{
	std::cout << "[DES] Ice has destroyed" << std::endl;
}

Ice &Ice::operator=( const Ice &target )
{
	std::cout << "[Ice's copy assignment called]" << std::endl;

	if ( this != &target )
		AMateria::operator=( target );

	return *this;
}

AMateria *Ice::clone( void ) const
{
	return new Ice( *this );
}

void Ice::use( ICharacter &character )
{
	std::cout << "* shoots an ice bolt at " << character.getName() << " *" << std::endl;
}

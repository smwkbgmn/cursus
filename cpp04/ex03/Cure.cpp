// #include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure( void )
: AMateria("cure")
{
	std::cout << "[CON-DEF] Cure has created" << std::endl;
}

Cure::Cure( const Cure &target )
: AMateria( target )
{
	std::cout << "[CON-CPY] Cure has created" << std::endl;
}

Cure::~Cure( void )
{
	std::cout << "[DES] Cure has destroyed" << std::endl;
}

Cure &Cure::operator=( const Cure &target )
{
	std::cout << "[Cure's copy assignment called]" << std::endl;

	if ( this != &target )
		AMateria::operator=( target );
	
	return *this;
}

AMateria *Cure::clone( void ) const
{
	return new Cure( *this );
}

void Cure::use( ICharacter &character )
{
	std::cout << "* heals " << character.getName() << "'s wounds *" << std::endl;
}


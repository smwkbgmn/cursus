#include <iostream>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	std::cout << "[CON-DEF] MateriaSource has created" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &target )
{
	*this = target;
	
	std::cout << "[CON-CPY] MateriaSource has created" << std::endl;
}

MateriaSource::~MateriaSource( void )
{
	std::cout << "[DES] MateriaSource has destroyed" << std::endl;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &target )
{
	std::cout << "[MateriaSource's copy assignment called]" << std::endl;

	// if (this != &target)
}

void MateriaSource::learnMateria( AMateria * )
{

}

AMateria* MateriaSource::createMateria( str_t const &type )
{

}


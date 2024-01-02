#include <new>
#include <iostream>

// #include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	iter( &MateriaSource::initMtra, NULL );

	std::cout << "[CON-DEF] MateriaSource has created" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &target )
{
	*this = target;
	
	std::cout << "[CON-CPY] MateriaSource has created" << std::endl;
}

MateriaSource::~MateriaSource( void )
{
	iter(&MateriaSource::freeMtra, NULL);

	std::cout << "[DES] MateriaSource has destroyed" << std::endl;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &target )
{
	std::cout << "[MateriaSource's copy assignment called]" << std::endl;

	if ( this != &target )
		copyMtra( target );

	return *this;
}

void MateriaSource::learnMateria( AMateria *materia )
{
	if ( iter( &MateriaSource::assignMtra, materia ) )
		std::cout << "A materia \"" << materia->getType() << "\" is saved to source" << std::endl;
	else
		delete materia;

}

AMateria* MateriaSource::createMateria( str_t const &type )
{
	void	*buf = (void *)type.c_str();

	if ( iter( &MateriaSource::getMtra, &buf ) )
		return ((AMateria *)buf)->clone();

	std::cout << "Couldn't find any type matching with " << type << std::endl;
	return NULL;
}

bool MateriaSource::iter( fp func, void *data )
{
	for ( int cnt = 0; cnt < SIZE_STORE; ++cnt )
	{
		if ( (this->*func)( cnt, data ) )
			return TRUE;
	}
	return FALSE;
}

bool MateriaSource::initMtra( int idx, void *null )
{
	_materia[idx] = (AMateria *)null;

	return FALSE;
}

bool MateriaSource::freeMtra( int idx, void *null )
{
	if ( _materia[idx] != null )
		delete _materia[idx];

	return FALSE;
}

bool MateriaSource::assignMtra( int idx, void *data )
{
	if ( !_materia[idx] )
	{
		_materia[idx] = (AMateria *)data;
		return TRUE;
	}
	return FALSE;
}

bool MateriaSource::getMtra( int idx, void *buf )
{
	str_t	type = *((char **)buf);

	if ( _materia[idx] )
	{
		if ( _materia[idx]->getType() == type )
		{
			*((AMateria **)buf) = _materia[idx];
			return TRUE;
		}
	}
	return FALSE;
}

void MateriaSource::copyMtra( const MateriaSource &target )
{
	for ( int cnt = 0; cnt < SIZE_STORE; ++cnt )
	{
		if ( _materia[cnt] )
			delete _materia[cnt];

		if ( target._materia[cnt] )
			_materia[cnt] = target._materia[cnt]->clone();
		else
			_materia[cnt] = NULL;
	}
}
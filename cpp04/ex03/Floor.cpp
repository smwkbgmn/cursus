#include <new>

#include "AMateria.hpp"
#include "Floor.hpp"

Floor::Floor( void )
{
	initSpace();

	std::cout << "[CON-DEF] Floor has created" << std::endl;
}

Floor::~Floor( void )
{
	freeSpace();
	
	std::cout << "[DES] Floor has destroyed" << std::endl;
}

void Floor::initSpace( void )
{
	for ( int idx = 0; idx < SIZE_FLOOR; ++idx )
		_space[idx] = NULL;
}

void Floor::freeSpace( void )
{
	for ( int idx = 0; idx < SIZE_FLOOR; ++idx )
		if ( _space[idx] )
			delete _space[idx];
}

bool Floor::drop( AMateria *materia )
{
	for ( int idx = 0; idx < SIZE_FLOOR; ++idx )
	{
		if ( !_space[idx] )
		{
			_space[idx] = materia;
			return TRUE;
		}
	}
	std::cout << "Materias are already everywhere!" << std::endl;

	delete materia;
	return FALSE;
}

void Floor::remove( const AMateria *target )
{
	for ( int idx = 0; idx < SIZE_FLOOR; ++idx )
		if ( _space[idx] == target )
			_space[idx] = NULL;
}
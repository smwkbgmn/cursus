#include <new>

#include "AMateria.hpp"
#include "Floor.hpp"

Floor::Floor( void )
: _idx( 0 )
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
	for ( int cnt = 0; cnt < SIZE_FLOOR; ++cnt )
		_space[cnt] = NULL;
}

void Floor::freeSpace( void )
{
	for ( int cnt = 0; cnt < SIZE_FLOOR; ++cnt )
		if ( _space[cnt] )
			delete _space[cnt];
}

bool Floor::drop( AMateria *materia )
{
	if ( _idx < SIZE_FLOOR )
	{
		_space[_idx++] = materia;
		return TRUE;
	}
	return FALSE;
}

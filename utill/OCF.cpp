#include <iostream>

#include "OCF.hpp"

// Instantiate
OCF::OCF( void )
{
	std::cout << "[CON-DEF] OCF has created" << std::endl;
}

OCF::OCF( const OCF &target )
{
	*this = target;
	
	std::cout << "[CON-CPY] OCF has created" << std::endl;
}

OCF::~OCF( void )
{
	std::cout << "[DES] OCF has destroyed" << std::endl;
}

// Overload
OCF &OCF::operator=( const OCF &target )
{
	std::cout << "[OCF's copy assignment called]" << std::endl;

	// if (this != &target)
}

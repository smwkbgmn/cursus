#include "OCF.hpp"

/* INSTANTIATE */
OCF::OCF( void ) {
	std::clog << "[CON] OCF has created" << std::endl;
}

OCF::OCF( const OCF &target ) {
	*this = target;
	
	std::clog << "[CON-CPY] OCF has created" << std::endl;
}

OCF::~OCF( void ) {
	std::clog << "[DES] OCF has destroyed" << std::endl;
}

/* METHOD */

/* OPERATOR */
OCF &OCF::operator=( const OCF &target ) {
	std::clog << "[OCF's copy assignment called]" << std::endl;

	// if (this != &target)
	// 	copy

	return *this;
}

/* STRUCT */
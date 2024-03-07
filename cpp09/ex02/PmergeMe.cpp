#include "PmergeMe.hpp"

/* INSTANTIATE */
PmergeMe::PmergeMe( void ) {
	std::clog << "[CON] PmergeMe has created" << std::endl;
}

PmergeMe::PmergeMe( const PmergeMe &target ) {
	*this = target;
	
	std::clog << "[CON-CPY] PmergeMe has created" << std::endl;
}

PmergeMe::~PmergeMe( void ) {
	std::clog << "[DES] PmergeMe has destroyed" << std::endl;
}

/* METHOD */

/* OPERATOR */
PmergeMe &PmergeMe::operator=( const PmergeMe &target ) {
	std::clog << "[PmergeMe's copy assignment called]" << std::endl;

	// if (this != &target)
	// 	copy

	return *this;
}

/* STRUCT */
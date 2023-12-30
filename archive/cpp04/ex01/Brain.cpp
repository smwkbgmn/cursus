#include <iostream>

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "[CON_DEF] Brain created" << std::endl;
}

Brain::Brain( const Brain &target )
{
	*this = target;

	std::cout << "[CON_CPY] Brain created" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "[DES] Brain destroyed" << std::endl;
}

Brain &Brain::operator=( const Brain &target )
{
	std::cout << "[Brain's copy assignment called]" << std::endl;

	if (this != &target )
	{
		for (int ptr = 0; ptr < 100; ++ptr)
			_ideas[ptr].assign(target._ideas[ptr]);
	}
	return *this;
}

const std::string &Brain::getIdea( int N ) const
{
	return _ideas[N];
}

void Brain::setIdea( const std::string &idea, int N )
{
	_ideas[N] = idea;
}

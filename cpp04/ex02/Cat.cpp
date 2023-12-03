#include <new>
#include <iostream>

#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << "[CON_DEF] Cat created" << std::endl;

	_type = "Cat";
	_brain = new (std::nothrow) Brain;
}

Cat::Cat( const Cat &target )
: AAnimal()
{
	std::cout << "[CON_CPY] Cat created" << std::endl;

	_brain = new (std::nothrow) Brain;
	*this = target;
}

Cat::~Cat( void )
{
	if (_brain)
		delete _brain;

	std::cout << "[DES] Cat destroyed" << std::endl;
}

Cat &Cat::operator=( const Cat &target )
{
	std::cout << "[Cat's copy assignment called]" << std::endl;

	if (this != &target )
	{
		_type = target._type;
		copyBrain( target );
	}
	
	return *this;
}

void Cat::copyBrain( const Cat &target )
{
	if (_brain)
		delete _brain;
	if (target._brain)
	{
		_brain = new (std::nothrow) Brain;
		if (_brain)
			*_brain = *target._brain;
	}
	else
		_brain = NULL;
}
	
void Cat::setIdeas( const std::string &idea )
{
	for (int cnt = 0; cnt < 10; ++cnt)
		_brain->setIdea( idea, cnt );
}

void Cat::printIdeas( void )
{
	for (int cnt = 0; cnt < 10; ++cnt)
		std::cout << _brain->getIdea(cnt) << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "Nyaong............." << std::endl;
}

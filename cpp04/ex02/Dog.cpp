#include <new>
#include <iostream>

#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << "[CON_DEF] Dog created" << std::endl;

	_type = "Dog";
	_brain = new (std::nothrow) Brain;
}

Dog::Dog( const Dog &target )
{
	std::cout << "[CON_CPY] Dog created" << std::endl;

	_brain = new (std::nothrow) Brain;
	*this = target;
}

Dog::~Dog( void )
{
	if (_brain)
		delete _brain;

	std::cout << "[DES] Dog destroyed" << std::endl;
}

Dog &Dog::operator=( const Dog &target )
{
	std::cout << "[Dog's copy assignment called]" << std::endl;

	if (this != &target )
	{
		_type = target._type;
		copyBrain( target );
	}
	
	return *this;
}

void Dog::copyBrain( const Dog &target )
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
	
void Dog::setIdeas( const std::string &idea )
{
	for (int cnt = 0; cnt < 10; ++cnt)
		_brain->setIdea( idea, cnt );
}

void Dog::printIdeas( void )
{
	for (int cnt = 0; cnt < 10; ++cnt)
		std::cout << _brain->getIdea(cnt) << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "Wearl Wearl!" << std::endl;
}

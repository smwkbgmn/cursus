#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie( std::string input )
{
	name = input;
	announce();
}

Zombie::~Zombie( void )
{
	std::cout << name << " killed by a hero" << std::endl;
}

std::string &Zombie::getName( void )
{
	return name;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

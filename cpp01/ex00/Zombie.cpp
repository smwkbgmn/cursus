#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie( std::string input )
: name(input)
{
}

Zombie::~Zombie( void )
{
	std::cout << name << " killed by a hero" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

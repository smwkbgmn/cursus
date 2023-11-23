#include <iostream>

#include "Zombie.hpp"

int	Zombie::_idx;

Zombie::Zombie( void )
{
	std::cout << "zombie " << _idx++ << " created" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << _name << ' ' << --_idx << " killed by a hero" << std::endl;
}

std::string &Zombie::getName( void )
{
	return _name;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

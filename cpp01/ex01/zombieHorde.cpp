#include <new>
#include <iostream>

#include "Zombie.hpp"

Zombie* zombieHorde( const int N, std::string name )
{
	Zombie	*horde = new Zombie[N];
	
	for (int idx = 0; idx < N; ++idx)
	{
		horde[idx].setName( name );
		std::cout << "Zombie " << idx << " named as \"" << name << '\"' << std::endl;
	}

	return (Zombie *)horde;
}
#include <new>
#include <iostream>

#include "Zombie.hpp"

Zombie* zombieHorde( const int N, std::string name )
{
	Zombie	*ptr = new Zombie[N];
	
	for (int idx = 0; idx < N; ++idx)
	{
		ptr[idx].getName() = name;
		std::cout << "zombie " << idx << " named as " << name << std::endl;
	}

	return (Zombie *)ptr;
}
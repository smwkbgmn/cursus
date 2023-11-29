#include <new>

#include "Zombie.hpp"

Zombie* zombieHorde( const int , std::string );

int main(void)
{
	Zombie	*horde;
	int		n = 3;

	horde = zombieHorde( n, "peter" );

	for (int idx = 0; idx < n; ++idx)
		horde[idx].announce();
		
	delete[] horde;
}

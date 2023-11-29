#include <new>

#include "Zombie.hpp"

Zombie* zombieHorde( const int , std::string );

int main(void)
{
	int		n = 3;
	Zombie	*horde = zombieHorde( n, "peter" );

	if (!horde)
		return 1;

	for (int idx = 0; idx < n; ++idx)
		horde[idx].announce();
		
	delete[] horde;

	return 0;
}

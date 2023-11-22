#include <new>

#include "Zombie.hpp"

int main(void)
{
	Zombie	*horde;

	horde = zombieHorde(3, "peter");
	delete[] horde;
}

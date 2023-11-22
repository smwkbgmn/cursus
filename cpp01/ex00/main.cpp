#include <new>

#include "Zombie.hpp"

int main(void)
{
	Zombie	*ptr = newZombie("peter");
	randomChump("john");
	delete ptr;
}

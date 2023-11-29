#include <new>

#include "Zombie.hpp"

Zombie	*newZombie( std::string );
void randomChump( std::string );

int main(void)
{
	Zombie	*ptr = newZombie( "peter" );
	randomChump( "john" );
	delete ptr;
}

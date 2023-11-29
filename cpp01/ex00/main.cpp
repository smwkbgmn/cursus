#include "Zombie.hpp"

Zombie	*newZombie( std::string );
void randomChump( std::string );

int main(void)
{
	Zombie	*ptr = newZombie( "peter" );

	if (!ptr)
		return 1;
		
	ptr->announce();
	randomChump( "john" );
	
	delete ptr;

	return 0;
}

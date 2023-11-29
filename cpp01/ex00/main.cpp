#include "Zombie.hpp"

Zombie	*newZombie( std::string );
void randomChump( std::string );

int main(void)
{
	Zombie	*ptr;

	try { ptr = newZombie( "peter" ); }
	catch (std::bad_alloc) { return 1; }
		
	ptr->announce();
	randomChump( "john" );
	
	delete ptr;

	return 0;
}

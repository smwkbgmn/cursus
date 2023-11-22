#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"

void	bob( void );
void	jim( void );

int main( void )
{
	bob();
	jim();

	Weapon	weapon("gun");

	HumanA	pete("Pete", weapon);
	HumanB	harry("Harry");

	std::cout << "\n# Pete and Harry are trying to attack" << std::endl;
	pete.attack();
	harry.attack();

	std::cout << "\n# Harry just armed a 'gun'" << std::endl;
	harry.setWeapon(weapon);

	std::cout << "\n# The weapon has changed to 'staff'" << std::endl;
	weapon.setType("staff");

	std::cout << "\n# They try to attack again" << std::endl;
	pete.attack();
	harry.attack();

	return 0;
}

void bob( void )
{
	Weapon	club = Weapon("crude spiked club");

	HumanA	bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}

void jim( void )
{
	Weapon	club = Weapon("crude spiked club");

	HumanB	jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();

}

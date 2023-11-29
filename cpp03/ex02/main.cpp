#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap	frag1;
	FragTrap	frag2 = frag1;

	FragTrap	frag3( "Pete" );
	FragTrap	frag4( frag3 );

	frag4.highFivesGuys();

	frag2.attack( frag1.getName() );
	frag1.takeDamage( frag2.getDamage() );

	return 0;
}

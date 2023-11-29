#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap( const str_t & );
		DiamondTrap( const DiamondTrap & );
		~DiamondTrap( void );
		
		DiamondTrap	&operator=( const DiamondTrap & );

		str_t	getDiaName( void ) const;

		void	attack( const str_t & );
		void	whoAmI( void );

	private:
		str_t	_name;

		void	initAttr( void );
		void	printName( void );
};

#endif
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( const ScavTrap & );
		ScavTrap( const str_t & );
		~ScavTrap( void );

		ScavTrap	&operator=( const ScavTrap & );

		void	guardGate( void );

	private:
		void	printName( void );
};

#endif
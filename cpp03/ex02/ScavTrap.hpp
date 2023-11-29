#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( const str_t & );
		ScavTrap( const ScavTrap & );
		~ScavTrap( void );

		ScavTrap	&operator=( const ScavTrap & );

		void	attack( const str_t & );
		void	guardGate( void );

	private:
		void	printName( void );
};

#endif
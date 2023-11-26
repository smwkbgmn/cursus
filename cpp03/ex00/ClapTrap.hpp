#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

# define FALSE 0
# define TRUE 1

typedef std::string		str_t;
typedef unsigned int	point_t;

class ClapTrap
{
	public:
		ClapTrap( const ClapTrap & );
		ClapTrap( const str_t & );
		~ClapTrap( void );

		ClapTrap	&operator=( const ClapTrap & );

		str_t	getName( void ) const;
		point_t	getHit( void ) const;
		point_t	getEnergy( void ) const;
		point_t	getDamage( void ) const;

		void	attack( const str_t & );
		void	takeDamage( point_t );
		void	beRepaired( point_t );

	private:
		bool	available( void );
		void	printName( void );
		void	printAttr( void );

		str_t	_name;
		point_t	_hit;
		point_t	_energy;
		point_t	_damage;
};

#endif
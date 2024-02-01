#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ICharacter;

class Ice
: public AMateria
{
	public:
		Ice( void );
		Ice( const Ice & );
		~Ice( void );

		Ice	&operator=( const Ice & );

		AMateria	*clone( void ) const;
		void		use( ICharacter & );
		
	private:
};

#endif
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class ICharacter;

class Cure
: public AMateria
{
	public:
		Cure( void );
		Cure( const Cure & );
		~Cure( void );

		Cure	&operator=( const Cure & );

		AMateria	*clone( void ) const;
		void		use( ICharacter & );
		
	private:
};

#endif
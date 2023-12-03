#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure
: virtual AMateria
{
	public:
		Cure( void );
		Cure( const Cure & );
		~Cure( void );

		Cure	&operator=( const Cure & );
		
	private:
};

#endif
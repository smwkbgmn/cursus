#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice
: virtual AMateria
{
	public:
		Ice( void );
		Ice( const Ice & );
		~Ice( void );

		Ice	&operator=( const Ice & );
		
	private:
};

#endif
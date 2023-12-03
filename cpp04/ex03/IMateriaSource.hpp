#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual	~IMateriaSource( void ) {}

		virtual	void		learnMateria( AMateria * ) = 0;
		virtual	AMateria*	createMateria( str_t const &type ) = 0;
};

#endif
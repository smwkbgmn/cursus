#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource
: virtual IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource & );
		~MateriaSource( void );

		MateriaSource	&operator=( const MateriaSource & );

		void		learnMateria( AMateria * );
		AMateria*	createMateria( str_t const &type );
		
	private:
		AMateria	*_memory[4];
};

#endif
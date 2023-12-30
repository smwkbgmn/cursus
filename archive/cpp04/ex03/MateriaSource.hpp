#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

// class IMateriaSource;
# include "IMateriaSource.hpp"

# define FALSE 0
# define TRUE 1

# define SIZE_STORE 4

class AMateria;

class MateriaSource
: public IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource & );
		~MateriaSource( void );

		MateriaSource	&operator=( const MateriaSource & );

		void		learnMateria( AMateria * );
		AMateria*	createMateria( str_t const & );
		
	private:
		typedef bool (MateriaSource::*fp)( int, void * );

		AMateria	*_materia[SIZE_STORE];
		
		bool	iter( fp, void * );
		bool	initMtra( int, void * );
		bool	freeMtra( int, void * );
		bool	assignMtra( int, void * );
		bool	getMtra( int, void * );
		void	copyMtra( const MateriaSource & );
};

#endif
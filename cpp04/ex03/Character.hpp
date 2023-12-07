#ifndef CHARACTER_HPP
# define CHARACTER_HPP

// class ICharacter;
# include "ICharacter.hpp"

# define FALSE 0
# define TRUE 1

# define SIZE_INVEN 4

class	AMateria;
struct	Floor;

class Character
: public ICharacter
{
	public:
		Character( void );
		Character( const str_t & );
		Character( const Character & );
		~Character( void );

		Character	&operator=( const Character & );

		const str_t	&getName( void ) const;

		void	equip( AMateria * );
		void	unequip( int );
		void	use( int, ICharacter & );
		
	private:
		str_t		_name;
		AMateria	*_inven[SIZE_INVEN];

		void	initInven( void );
		void	freeInven( void );
		void	copyInven( const Character & );
};


#endif
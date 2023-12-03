#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character
: virtual ICharacter
{
	public:
		Character( void );
		Character( const str_t & );
		Character( const Character & );
		~Character( void );

		Character	&operator=( const Character & );

		str_t	&getName( void ) const;

		void	equip( AMateria* m );
		void	unequip( int idx );
		void	use( int idx, ICharacter& target );
		
	private:
		str_t		_name;
		AMateria	*_inven[4];
		AMateria	*discard;

		void initInven( void );
};

#endif
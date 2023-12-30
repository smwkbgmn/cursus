#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

typedef std::string	str_t;

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual const str_t	&getName( void ) const = 0;

		virtual void	equip( AMateria* m ) = 0;
		virtual void	unequip( int idx ) = 0;
		virtual void	use( int idx, ICharacter& target ) = 0;
};

#endif
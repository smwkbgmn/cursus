#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

# define FALSE 0
# define TRUE 1

typedef std::string	str_t;

class ICharacter;

class AMateria
{
	public:
		AMateria( void );
		AMateria( str_t const & );
		AMateria( const AMateria & );
		virtual ~AMateria( void );

		const AMateria	&operator=( const AMateria & );

		str_t const	&getType( void ) const;

		virtual AMateria	*clone( void ) const = 0;
		virtual void		use( ICharacter & );

	protected:
		str_t	_type;
};

#endif
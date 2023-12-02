#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal & );
		virtual ~WrongAnimal( void );

		WrongAnimal &operator=( const WrongAnimal & );

		const std::string	&getType( void ) const;

		virtual void	makeSound( void ) const;

	protected:
		std::string	_type;
}; 

#endif
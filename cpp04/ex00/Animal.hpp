#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal( void );
		Animal( const Animal & );
		~Animal( void );

		Animal &operator=( const Animal & );

		const std::string	&getType( void ) const;

		virtual void	makeSound( void ) = 0;

	protected:
		std::string	_type;
}; 

#endif
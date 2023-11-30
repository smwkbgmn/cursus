#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( const Cat & );
		~Cat( void );

		Cat &operator=( const Cat & );

		void	makeSound( void );

	private:
};

#endif
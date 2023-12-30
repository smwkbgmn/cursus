#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog
: public Animal
{
	public:
		Dog( void );
		Dog( const Dog & );
		~Dog( void );

		Dog &operator=( const Dog & );

		void setIdeas( const std::string & );
		void printIdeas( void );

		void	makeSound( void ) const;

	private:
		Brain	*_brain;

		void copyBrain( const Dog & );
};

#endif
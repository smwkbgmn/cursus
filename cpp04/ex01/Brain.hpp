#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		std::string	_ideas[100];
		
		Brain( void );
		Brain( const Brain & );
		~Brain( void );

		Brain &operator=( const Brain & );
}; 

#endif
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain( void );
		Brain( const Brain & );
		~Brain( void );

		Brain &operator=( const Brain & );

		const std::string	&getIdea( int ) const;
		void				setIdea( const std::string &, int );

	private:
		std::string	_ideas[100];
}; 

#endif
#ifndef INTERN_HPP
# define INTERN_HPP

# include <string.h>

# include "AForm.hpp"

# define COUNT_FORM 3

class Intern
{
	public:
		Intern( void );
		~Intern( void );
		
		Form	*makeForm( const std::string &, const std::string & );

		struct unrecognizedTokenException
		: std::exception
		{
			const char *what( void ) const throw();
		};

	private:
		Intern(const Intern &);

		Intern &operator=(const Intern &);
};

#endif
#ifndef INTERN_HPP
# define INTERN_HPP

# include <string.h>

# include "AForm.hpp"

# define COUNT_FORM 3

typedef Form	*(*clone_fp)( const std::string & );

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

	private:
		std::string	_nameForm[COUNT_FORM];
		clone_fp	_newForm[COUNT_FORM];
};

#endif
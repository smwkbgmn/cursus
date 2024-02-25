#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>

# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm
: public AForm
{
	public:
		ShrubberyCreationForm( const std::string & );
		~ShrubberyCreationForm( void );

		void	execute( Bureaucrat const & ) const;

		static Form	*clone( const std::string & );

	private:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm & );
		
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm & );

	private:
		const std::string	_target;
};

#endif
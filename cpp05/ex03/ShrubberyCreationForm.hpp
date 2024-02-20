#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm
: public AForm
{
	public:
		ShrubberyCreationForm( const std::string );
		~ShrubberyCreationForm( void );

		static AForm	*clone( const std::string & );
		
		void	execute( Bureaucrat const & ) const;

	private:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm & );
		
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm & );

	private:
		const std::string	_target;
};

#endif
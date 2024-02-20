#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm
: public AForm
{
	public:
		PresidentialPardonForm( const std::string );
		~PresidentialPardonForm( void );

		void	execute( Bureaucrat const & ) const;

	private:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm & );
		
		PresidentialPardonForm	&operator=( const PresidentialPardonForm & );

	private:
		const std::string	_target;
};

#endif
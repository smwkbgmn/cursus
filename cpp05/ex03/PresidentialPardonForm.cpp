#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

// Instantiate
PresidentialPardonForm::PresidentialPardonForm( const std::string &target )
: AForm("Presidential", 25, 5), _target(target)
{
	std::cout << "[CON-USR] PresidentialPardonForm has created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "[DES] PresidentialPardonForm has destroyed" << std::endl;
}

// Member
void PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	throwGradeExcpt(executor.getGrade(), getGradeExecute());

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

Form *PresidentialPardonForm::clone( const std::string &target )
{
	return new PresidentialPardonForm(target);
}

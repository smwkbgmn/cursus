
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

// Instantiate
PresidentialPardonForm::PresidentialPardonForm( void )
{
	std::cout << "[CON-DEF] PresidentialPardonForm has created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &target )
: AForm(target), _target(target._target)
{
	std::cout << "[CON-CPY] PresidentialPardonForm has created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target )
: AForm("Presidential", 25, 5), _target(target)
{
	std::cout << "[CON-USR] PresidentialPardonForm has created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "[DES] PresidentialPardonForm has destroyed" << std::endl;
}

// Overload
PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &target )
{
	std::cout << "[PresidentialPardonForm's copy assignment called]" << std::endl;

	if (this != &target)
		AForm::operator=(target);
	return *this;
}

// Member
void PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	throwGradeExcpt(executor.getGrade(), getGradeExecute());

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

Form	*PresidentialPardonForm::clone( const std::string &name )
{
	return new PresidentialPardonForm(name);
}


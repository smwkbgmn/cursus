#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// Instantiate
Intern::Intern( void )
{
	std::cout << "[CON-DEF] Intern has created" << std::endl;
}

Intern::~Intern( void )
{
	std::cout << "[DES] Intern has destroyed" << std::endl;
}

// Exception
const char *Intern::unrecognizedTokenException::what( void ) const throw()
{
	return "Couldn't find any form matching with the entered name\n";
}

// Member
Form *Intern::makeForm( const std::string &nameForm, const std::string &nameTarget )
{
	std::string	form[COUNT_FORM] =
	{
		"Shrubbery",
		"Robotomy",
		"Presidential"
	};
	
	Form	*(*clone[COUNT_FORM])( const std::string &name ) =
	{
		&ShrubberyCreationForm::clone,
		&RobotomyRequestForm::clone,
		&PresidentialPardonForm::clone
	};

	for (int idx = 0; idx < COUNT_FORM; idx++)
	{
		if (form[idx] == nameForm)
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return (*clone[idx])(nameTarget);
		}
	}

	throw unrecognizedTokenException();
}

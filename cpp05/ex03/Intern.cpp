#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// Instantiate
Intern::Intern( void )
{
	_nameForm[0] = "Shrubbery";
	_nameForm[1] = "Robotomy";
	_nameForm[2] = "Presidential";

	_newForm[0] = &ShrubberyCreationForm::clone;
	_newForm[1] = &RobotomyRequestForm::clone;
	_newForm[2] = &PresidentialPardonForm::clone;

	std::cout << "[CON-DEF] Intern has created" << std::endl;
}

Intern::Intern( const Intern &target )
{
	*this = target;

	std::cout << "[CON-CPY] Intern has created" << std::endl;
}

Intern::~Intern( void )
{
	std::cout << "[DES] Intern has destroyed" << std::endl;
}

// Overload
Intern &Intern::operator=( const Intern &target )
{
	std::cout << "[Intern's copy assignment called]" << std::endl;

	(void)target;
	return *this;
}

// Exception
const char *Intern::unrecognizedTokenException::what( void ) const throw()
{
	return "Couldn't find any form matching with the entered name\n";
}

// Member
Form *Intern::makeForm( const std::string &nameForm, const std::string &nameTarget )
{
	int idx = 0;

	while (idx < COUNT_FORM && _nameForm[idx] != nameForm)
		idx++;

	if (idx == COUNT_FORM)
		throw unrecognizedTokenException();

	std::cout << "Intern creates " << nameForm << std::endl;
	return (*_newForm[idx])(nameTarget);
}

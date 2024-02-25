#include <iostream>
#include <new>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void newline( void );

int main( void )
{
	/*
		Shruburry		145,	137
		Robotomy		72,		45
		Presidential	25,		5
	*/

	Bureaucrat	peter("Peter", 100);

	AForm		*shrubbery = new ShrubberyCreationForm("Home");
	AForm		*robotomy = new RobotomyRequestForm(peter.getName());
	AForm		*presidential = new PresidentialPardonForm(peter.getName());

	{
		// EXECUTE WITHOUT SIGN
		peter.executeForm(*shrubbery);

		peter.signForm(*shrubbery);
		peter.executeForm(*shrubbery);
		newline();
	}

	{
		// SIGN WITH NOT ENOUGH GRADE 
		peter.signForm(*robotomy);

		peter.upVote(50);
		peter.signForm(*robotomy);
		newline();
	}

	{
		// EXECUTE WITH NOT ENOUGH GRADE
		peter.executeForm(*robotomy);
		
		peter.upVote(25);
		peter.executeForm(*robotomy);
		newline();
	}
	
	{
		// EXECUTE Presidential
		peter.upVote(24);
		peter.signForm(*presidential);
		peter.executeForm(*presidential);
		newline();
	}

	delete shrubbery;
	delete robotomy;
	delete presidential;

	return (0);
}

void newline( void )
{
	std::cout << std::endl;
}

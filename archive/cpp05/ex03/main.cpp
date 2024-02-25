#include "Bureaucrat.hpp"
#include "Intern.hpp"

void newline( void );

int main( void )
{
	Bureaucrat	peter("Peter", 100);

	Intern		intern;
	Form		*form;

	try
	{
		form = intern.makeForm("Shrubbery", "home");
		peter.signForm(*form);
		peter.executeForm(*form);
		delete form;
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what();
	}

	try
	{
		form = intern.makeForm("Robotomy", "peter");
		peter.signForm(*form);
		peter.executeForm(*form);
		delete form;
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what();
	}

	try
	{
		form = intern.makeForm("Preprepresi", "peter");
		peter.signForm(*form);
		peter.executeForm(*form);
		delete form;
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what();
	}

	return (0);
}

void newline( void )
{
	std::cout << std::endl;
}

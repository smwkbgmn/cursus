#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void newline( void );

int main( void )
{
	try
	{
		Form	f_right("F_Right", 1, 150);
		std::cout << f_right;

		Form	f_wrong("F_Wrong", 1, 151);
		std::cout << f_wrong;
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what();
	}
	newline();

	try
	{
		Bureaucrat	peter("Peter", 100);
		Form		f1("F1", 100, 100);
		Form		f2("F2", 50, 50);

		std::cout << peter;
		std::cout << f1;
		std::cout << f2;

		peter.signForm(f1);
		peter.signForm(f2);
		newline();

		std::cout << f1;
		std::cout << f2;
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

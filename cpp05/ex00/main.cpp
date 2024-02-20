#include <iostream>

#include "Bureaucrat.hpp"

void newline( void );

int main( void )
{
	try
	{
		Bureaucrat	peter("Peter", 1);
		Bureaucrat	john("John", 150);

		std::cout << peter;
		std::cout << john;
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what();
	}
	newline();

	try
	{
		Bureaucrat	craig("Craig", 0);
		
		std::cout << craig;
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what(); 
	}
	newline();
	
	try
	{
		Bureaucrat	harry("Harry", 151);

		std::cout << harry;
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what(); 
	}
	newline();

	try
	{
		Bureaucrat	newman("Newman", 100);
		std::cout << newman;

		newman.upVote(50);
		std::cout << newman;
		newman.upVote(50);
		std::cout << newman;

		newman.downVote(150);
		std::cout << newman;
		newman.downVote(150);
		std::cout << newman;
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what();
	}
	newline();

	/* IF DID NOT CATCH EXCEPTION */
	// Bureaucrat	right("Right", 150);
	// Bureaucrat	wrong("Wrong", 151);
	
	// right.downVote(1);
	// wrong.upVote(1);

	return (0);
}

void newline( void )
{
	std::cout << std::endl;
}

#include <iostream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

// Instantiate
RobotomyRequestForm::RobotomyRequestForm( void )
{
	std::cout << "[CON-DEF] RobotomyRequestForm has created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &target )
: AForm(target), _target(target._target)
{
	std::cout << "[CON-CPY] RobotomyRequestForm has created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target )
: AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "[CON-USR] RobotomyRequestForm has created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "[DES] RobotomyRequestForm has destroyed" << std::endl;
}

// Overload
RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &target )
{
	std::cout << "[RobotomyRequestForm's copy assignment called]" << std::endl;

	if (this != &target)
		AForm::operator=(target);
		
	return *this;
}

// Member
void RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	throwGradeExcpt(executor.getGrade(), getGradeExecute());

	std::cout << "ddddddddd.....\n";
	if (std::rand() % 2 == 0)
		std::cout << _target << " has successfully robotomized!" << std::endl;
	else
		std::cout << _target << " has failed to robotomize" << std::endl;
}



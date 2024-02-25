#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

// Instantiate
RobotomyRequestForm::RobotomyRequestForm( const std::string &target )
: AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "[CON-USR] RobotomyRequestForm has created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "[DES] RobotomyRequestForm has destroyed" << std::endl;
}

// Member
void RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	throwGradeExcpt(executor.getGrade(), getGradeExecute());

	std::cout << "ddddddddd.....\n";
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	if (rand() % 2 == 0)
		std::cout << _target << " has successfully robotomized!" << std::endl;
	else
		std::cout << _target << " has failed to robotomize" << std::endl;
}



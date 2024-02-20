#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Instance
Bureaucrat::Bureaucrat( void )
{
	std::cout << "[CON-DEF] Bureaucrat has created" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, int grade )
: _name(name)
{
	throwGradeExcpt(grade);
	_grade = grade;

	std::cout << "[CON-USR] Bureaucrat has created" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &target )
: _name(target.getName()), _grade(target.getGrade())
{
	std::cout << "[CON-CPY] Bureaucrat has created" << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "[DES] Bureaucrat has destroyed" << std::endl;
}

// Overload
Bureaucrat &Bureaucrat::operator=( const Bureaucrat &target )
{
	std::cout << "[Bureaucrat's copy assignment called]" << std::endl;

	if (this != &target)
		_grade = target._grade;

	return *this;
}

// Get & Set
std::string Bureaucrat::getName( void ) const
{
	return _name;
}

int Bureaucrat::getGrade( void ) const
{
	return _grade;
}

// Exception
const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "error: entered grade exceed the highest value\n";
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "error: entered grade exceed the lowest value\n";
}

// Member
void Bureaucrat::upVote( int n )
{
	throwGradeExcpt(_grade - n);
	_grade -= n;
}

void Bureaucrat::downVote( int n )
{
	throwGradeExcpt(_grade + n);
	_grade += n;
}

void Bureaucrat::signForm( Form &form ) throw()
{
	std::cout << _name;
	try
	{
		form.beSigned( *this );
		std::cout << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &excpt )
	{
		std::cout << " couldn't sign " << form.getName() << " because ";
		std::cout << excpt.what();
	}
}

void Bureaucrat::throwGradeExcpt( long grade )
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// NON-Member
std::ostream &operator<<(std::ostream& os, const Bureaucrat &target )
{
	std::cout << target.getName() << ", bureaucrat grade " \
			<< target.getGrade() << "." << std::endl;
			
	return os;
}
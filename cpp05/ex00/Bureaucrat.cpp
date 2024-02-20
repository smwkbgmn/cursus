#include <iostream>

#include "Bureaucrat.hpp"

//  Instantiate
Bureaucrat::Bureaucrat( void )
{
	std::cout << "[CON-DEF] Bureaucrat has created" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade )
: _name(name)
{
	throwGradeExcpt(grade);
	_grade = grade;

	std::cout << "[CON-NME] Bureaucrat has created" << std::endl;
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

// Operator Overload
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

// Member Function
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

void Bureaucrat::throwGradeExcpt( long grade )
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &brcrt )
{
	std::cout << brcrt.getName() << ", bureaucrat grade " \
			<< brcrt.getGrade() << "." << std::endl;
			
	return os;
}
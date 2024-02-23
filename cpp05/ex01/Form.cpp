#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( const Form &target )
: _name(target.getName()), _gradeSign(target.getGradeSign()),
_gradeExecute(target.getGradeExecute()), _signature(target.getSign())
{
	std::cout << "[CON-CPY] Form has created" << std::endl;
}

Form::Form( const std::string &name, int sign, int execute )
: _name(name), _gradeSign(sign), _gradeExecute(execute), _signature(FALSE)
{
	Bureaucrat::throwGradeExcpt(sign);
	Bureaucrat::throwGradeExcpt(execute);

	std::cout << "[CON-USR] Form has created" << std::endl;
}

Form::~Form( void )
{
	std::cout << "[DES] Form has destroyed" << std::endl;
}

// Get & Set
std::string	Form::getName( void ) const
{
	return _name;
}

bool Form::getSign( void ) const
{
	return _signature;
}

int Form::getGradeSign( void ) const
{
	return _gradeSign;
}

int Form::getGradeExecute( void ) const
{
	return _gradeExecute;
}

// Exception
const char *Form::GradeTooHighException::what( void ) const throw()
{
	return "The grade of bureaucrat is too high\n";
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	return "The grade of bureaucrat is too low\n";
}

// Member
void Form::beSigned( Bureaucrat &brcrt )
{
	if (brcrt.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();

	_signature = TRUE;
}

// NON-Member
std::ostream &operator<<( std::ostream& os, const Form &target )
{
	std::cout << "Form info\n";
	std::cout << "\tname: " << target.getName() << "\n";

	std::cout << "\tsignature: ";
	if (target.getSign())
		std::cout << "YES\n";
	else
		std::cout << "NO\n";

	std::cout << "\tgrade_sign: " << target.getGradeSign() << "\n";
	std::cout << "\tgrade_execute: " << target.getGradeExecute() << "\n";
	std::cout << std::endl;
			
	return os;
}

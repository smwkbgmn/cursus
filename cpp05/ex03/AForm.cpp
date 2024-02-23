#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Instance
AForm::AForm( const std::string &name, int sign, int execute )
: _name(name), _gradeSign(sign), _gradeExecute(execute), _signature(FALSE)
{
	Bureaucrat::throwGradeExcpt(sign);
	Bureaucrat::throwGradeExcpt(execute);

	std::cout << "[CON-USR] AForm has created" << std::endl;
}

AForm::~AForm( void )
{
	std::cout << "[DES] AForm has destroyed" << std::endl;
}

// Get & Set
std::string	AForm::getName( void ) const
{
	return _name;
}

bool AForm::getSign( void ) const
{
	return _signature;
}

int AForm::getGradeSign( void ) const
{
	return _gradeSign;
}

int AForm::getGradeExecute( void ) const
{
	return _gradeExecute;
}

// Exception
const char *AForm::GradeTooHighException::what( void ) const throw()
{
	return "The grade of bureaucrat is too high\n";
}

const char *AForm::GradeTooLowException::what( void ) const throw()
{
	return "The grade of bureaucrat is too low\n";
}

const char *AForm::noPermissionException::what( void ) const throw()
{
	return "Has no signature yet\n";
}

// Member
void AForm::beSigned( Bureaucrat &brcrt )
{
	if (brcrt.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();

	_signature = TRUE;
}

void AForm::throwGradeExcpt( int grade, int gradeExecute ) const
{
	if (!_signature)
		throw noPermissionException();
	
	if (grade > gradeExecute)
		throw GradeTooLowException();
}

// NON-Member
std::ostream &operator<<( std::ostream& os, const AForm &target )
{
	std::cout << "AForm info\n";
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

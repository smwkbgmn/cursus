#include <fstream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

// Instantiate
ShrubberyCreationForm::ShrubberyCreationForm( void )
{
	std::cout << "[CON-DEF] ShrubberyCreationForm has created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &target )
: AForm(target), _target(target._target)
{
	std::cout << "[CON-CPY] ShrubberyCreationForm has created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target )
: AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "[CON-USR] ShrubberyCreationForm has created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "[DES] ShrubberyCreationForm has destroyed" << std::endl;
}

// Overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &target )
{
	std::cout << "[ShrubberyCreationForm's copy assignment called]" << std::endl;

	if (this != &target)
		AForm::operator=(target);

	return *this;
}

// Member
void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	throwGradeExcpt(executor.getGrade(), getGradeExecute());
	try
	{
		std::ofstream	ofs;

		ofs.open((_target + "_shrubbery").c_str(), std::fstream::trunc);

		ofs << "+++++++++++++++\n";
		ofs << "+++++++ +++++++\n";
		ofs << "++++++   ++++++\n";
		ofs << "+++++ *   +++++\n";
		ofs << "++++     * ++++\n";
		ofs << "+++   *     +++\n";
		ofs << "++           ++\n";
		ofs << "++++++   ++++++\n";
		ofs << "++++++   ++++++\n";
		ofs << "+++++++++++++++\n";
		ofs << "+++++++++++++++\n";

		ofs.close();
	}
	catch (std::exception &excpt)
	{
		std::cerr << excpt.what();
	}
}

AForm *ShrubberyCreationForm::clone( const std::string &name )
{
	return new ShrubberyCreationForm(name);
}

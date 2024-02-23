#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

// Instantiate
ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target )
: AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "[CON-USR] ShrubberyCreationForm has created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "[DES] ShrubberyCreationForm has destroyed" << std::endl;
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

Form *ShrubberyCreationForm::clone( const std::string &target )
{
	return new ShrubberyCreationForm(target);
}

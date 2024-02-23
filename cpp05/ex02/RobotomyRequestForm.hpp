#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm
: public AForm
{
	public:
		RobotomyRequestForm( const std::string & );
		~RobotomyRequestForm( void );

		void	execute( Bureaucrat const & ) const;

	private:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm & );
		
		RobotomyRequestForm	&operator=( const RobotomyRequestForm & );

	private:
		const std::string	_target;
};

#endif
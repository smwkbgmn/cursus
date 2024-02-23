#ifndef BURUREAUCRAT_HPP
# define BURUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat
{
	/* PUBLIC */
	public:
		Bureaucrat( const Bureaucrat & );
		Bureaucrat( const std::string &, int );
		~Bureaucrat( void );

	public:
		std::string	getName( void ) const;
		int			getGrade( void ) const;
	
	public:
		static void	throwGradeExcpt( long );

		void		upVote( int );
		void		downVote( int );
		void		signForm( AForm & ) throw();
		void		executeForm( AForm const & ) throw();

	public:
		struct GradeTooHighException
		: std::exception
		{
			const char *what( void ) const throw();
		};

		struct GradeTooLowException
		: std::exception
		{
			const char *what( void ) const throw();
		};

	/* PRIVATE */
	private:
		Bureaucrat( void );

		Bureaucrat	&operator=( const Bureaucrat & );

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<( std::ostream&, const Bureaucrat & );

#endif
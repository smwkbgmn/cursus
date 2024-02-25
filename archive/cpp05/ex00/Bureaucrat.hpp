#ifndef BURUREAUCRAT_HPP
# define BURUREAUCRAT_HPP

# include <string>
# include <exception>

class Bureaucrat
{
	/* PUBLIC */
	public:
		Bureaucrat( const Bureaucrat & );
		Bureaucrat( std::string, int );
		~Bureaucrat( void );

	public:
		std::string	getName( void ) const;
		int			getGrade( void ) const;
	
	public:
		void		upVote( int );
		void		downVote( int );
		void		throwGradeExcpt( long );

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
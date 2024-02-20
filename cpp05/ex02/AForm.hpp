#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm( void );
		AForm( const AForm & );
		AForm( const std::string &, int, int );
		virtual ~AForm( void );

		AForm			&operator=( const AForm & );

		std::string		getName( void ) const;
		bool			getSign( void ) const;
		int				getGradeSign( void ) const;
		int				getGradeExecute( void ) const;
	
		void			beSigned( Bureaucrat & );
		void			throwGradeExcpt( int, int ) const;
		virtual void	execute( Bureaucrat const & ) const = 0;
		
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

		struct noPermissionException
		: std::exception
		{
			const char *what( void ) const throw();
		};

	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExecute;

		bool				_signature;
		enum boolValue
		{
			FALSE,
			TRUE
		};
};

std::ostream &operator<<( std::ostream&, const AForm & );

#endif
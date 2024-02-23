#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	/* PUBLIC */
	public:
		Form( const Form & );
		Form( const std::string &, int, int );
		~Form( void );

	public:
		std::string	getName( void ) const;
		bool		getSign( void ) const;
		int			getGradeSign( void ) const;
		int			getGradeExecute( void ) const;
	
	public:
		void		beSigned( Bureaucrat & );
		
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
		enum boolValue
		{
			FALSE,
			TRUE
		};

	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExecute;

		bool				_signature;

	private:
		Form( void );

		Form		&operator=( const Form & );
};

std::ostream &operator<<( std::ostream&, const Form & );

#endif
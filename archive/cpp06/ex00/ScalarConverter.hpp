#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <exception>
# include <string>

# include <iostream>
# include <iomanip>
# include <sstream>

// FOR SOME VALIDATION
# include <limits> 
# include <cctype>
# include <cmath>

# define NONE 0
# define FALSE 0
# define TRUE 1

# define CNT_TYPE 4
# define CNT_LITERAL 6

static const std::string	pesudoLiteral[CNT_LITERAL] =
{
	"nan",
	"+nan",
	"-nan",
	"inf",
	"+inf",
	"-inf"
};

static const double			pesudoLiteralVal[CNT_LITERAL] =
{
	NAN,
	NAN,
	-NAN,
	INFINITY,
	INFINITY,
	-INFINITY
};

class ScalarConverter
{
	public:
		static void		convert( const std::string & );

	private:
		typedef enum valueName
		{
			INT,
			FLOAT,
			DOUBLE,
			CHAR
		}	name_t;

		typedef struct valueSet
		{
			valueSet( void );
			
			char	character;
			int		integer;
			float	decimal_f;
			double	decimal_d;
		}	set_t;

		struct noTypeMatchExcpt
		: std::exception
		{
		};

	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter & );
		~ScalarConverter( void );

		ScalarConverter	&operator=( const ScalarConverter & );

		static void		printValue( const std::string & );
		static void		printImpossible( void );

		static name_t	getType( const std::string &, set_t & );
		static bool		tryInt( const std::string &, set_t & );
		static bool		tryFloat( const std::string &, set_t & );
		static bool		tryDouble( const std::string &, set_t & );
		static bool		tryChar( const std::string &, set_t & );
		static bool		success( const std::istringstream & );
		static bool		literalFloat( const std::string &, set_t & );
		static bool		literalDouble( const std::string &, set_t & );

		static void		fromChar( set_t & );
		static void		fromInt( set_t & );
		static void		fromFloat( set_t & );
		static void		fromDouble( set_t & );

		static void		print( const set_t & );
		static bool		exceedValue( const set_t &, name_t type );
		static bool		hasDecimal( const set_t & );
		static void		newline( void );
};

#endif
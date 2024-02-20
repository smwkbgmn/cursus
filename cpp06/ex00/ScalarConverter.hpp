#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <exception>

# include <iostream>
# include <iomanip>
# include <sstream>
# include <ios>

# include <string>
# include <limits>
# include <climits>

# include <cctype>
# include <cstring>
# include <cmath>
# include <cfloat>

# define NONE 0
# define FALSE 0
# define TRUE 1

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
			CHAR,
			INT,
			FLOAT,
			DOUBLE
		}	name_t;

		typedef struct valueSet
		{
			valueSet( void );
			
			char	character;
			int		integer;
			float	dec_f;
			double	dec_d;
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
		static name_t	detectType( const std::string &, set_t & );

		static bool		tryInt( const std::string &, set_t & );
		static bool		tryFloat( const std::string &, set_t & );
		static bool		tryDouble( const std::string &, set_t & );
		static bool		success( const std::istringstream & );
		static bool		literal( const std::string &, set_t & );

		static void		convertChar( set_t & );
		static void		convertInt( set_t & );
		static void		convertFloat( set_t & );
		static void		convertDouble( set_t & );

		static void		print( const set_t & );
		static bool		exceedValue( const set_t &, name_t type );
		static bool		hasDecimal( const set_t & );
		static void		newline( void );
		static void		printImpossible( void );
	
};

#endif
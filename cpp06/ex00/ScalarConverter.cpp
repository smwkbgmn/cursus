#include "ScalarConverter.hpp"

// Member
void ScalarConverter::convert( const std::string &input )
{
	try
	{
		printValue(input);	
	}
	catch (std::exception &excpt)
	{
		printImpossible();
	}
}

void ScalarConverter::printValue( const std::string &input )
{
	set_t	val;

	void	(*convertValue[CNT_TYPE])( set_t & ) =
	{
		&fromInt,
		&fromFloat,
		&fromDouble,
		&fromChar
	};

	convertValue[getType(input, val)](val);
	print(val);
}

ScalarConverter::name_t ScalarConverter::getType( const std::string &input, set_t &val )
{
	bool	(*get[CNT_TYPE])( const std::string &, set_t & ) =
	{
		&tryInt,
		&tryFloat,
		&tryDouble,
		&tryChar
	};

	for (int type = 0; type < CNT_TYPE; type++)
	{
		if (get[type](input, val))
			return static_cast<name_t>(type);
	}

	throw noTypeMatchExcpt();
}

bool ScalarConverter::tryInt( const std::string &input, set_t &val )
{
	std::istringstream	is(input);

	is >> val.integer;
	return success(is);
}

bool ScalarConverter::tryFloat( const std::string &input, set_t &val )
{
	if (literal(input, val))
		return TRUE;
		
	if (input.back() == 'f' && input.find('.') != std::string::npos)
	{
		std::istringstream	is(input.substr(0, input.length() - 1));

		is >> val.dec_f;
		return success(is);
	}
	return FALSE;
}

bool ScalarConverter::tryDouble( const std::string &input, set_t &val )
{
	std::istringstream	is(input);

	is >> val.dec_d;
	return success(is);
}

bool ScalarConverter::tryChar( const std::string &input, set_t &val )
{
	if (input.length() == 1)
	{
		val.character = input.at(0);
		return TRUE;
	}
	return FALSE;
}

bool ScalarConverter::success( const std::istringstream &is )
{
	return (is.eof() && !is.fail());
}

bool ScalarConverter::literal( const std::string &input, set_t &val )
{
	for (int idx = 0; idx < CNT_LITERAL; idx++)
	{
		if (input == pesudoLiteral[idx] + "f")
		{
			val.dec_f = pesudoLiteralVal[idx];
			return TRUE;
		}
	}
	return FALSE;
}

void ScalarConverter::fromChar( set_t &val )
{
	val.integer = static_cast<int>(val.character);
	val.dec_f = static_cast<float>(val.character);
	val.dec_d = static_cast<double>(val.character);
}

void ScalarConverter::fromInt( set_t &val )
{
	val.character = static_cast<char>(val.integer);
	val.dec_f = static_cast<float>(val.integer);
	val.dec_d = static_cast<double>(val.integer);
}

void ScalarConverter::fromFloat( set_t &val )
{
	val.character = static_cast<char>(val.dec_f);
	val.integer = static_cast<int>(val.dec_f);
	val.dec_d = static_cast<double>(val.dec_f);
}

void ScalarConverter::fromDouble( set_t &val )
{
	val.character = static_cast<char>(val.dec_d);
	val.integer = static_cast<int>(val.dec_d);
	val.dec_f = static_cast<float>(val.dec_d);
}

void ScalarConverter::print( const set_t &val )
{
	std::cout << "char: ";
	if (!std::isfinite(val.dec_f) || exceedValue(val, CHAR) || hasDecimal(val))
		std::cout << "impossible";
	else
	{
		if (std::isprint(val.integer))
			std::cout << '\'' << val.character << '\'';
		else
			std::cout << "Non displayable"; 
	}
	newline();
	
	std::cout << "int: ";
	if (!std::isfinite(val.dec_f) || exceedValue(val, INT) || hasDecimal(val))
		std::cout << "impossible";
	else
		std::cout << val.integer;
	newline();
	
	std::cout << "float: ";
	if (std::isfinite(val.dec_d) && exceedValue(val, FLOAT))
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(2) << val.dec_f << 'f';
	newline();

	std::cout << "double: " << std::fixed << std::setprecision(2) << val.dec_d;
	newline();
}

void ScalarConverter::printImpossible( void )
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

bool ScalarConverter::exceedValue( const set_t &val, ScalarConverter::name_t type )
{
	switch (type)
	{
		case CHAR:
			return val.integer < std::numeric_limits<char>::min() ||
					val.integer > std::numeric_limits<char>::max();
		case INT:
			return val.dec_d < std::numeric_limits<int>::min() ||
					val.dec_d > std::numeric_limits<int>::max();
		case FLOAT:
			return val.dec_d < -std::numeric_limits<float>::max() ||
					val.dec_d > std::numeric_limits<float>::max();
		default:
			return FALSE;
	}
}

bool ScalarConverter::hasDecimal( const set_t &val )
{
	return val.dec_f - static_cast<float>(val.integer) != 0;
}

void ScalarConverter::newline( void )
{
	std::cout << std::endl;
}

ScalarConverter::valueSet::valueSet( void )
: character(NONE), integer(NONE), dec_f(NONE), dec_d(NONE)
{
}

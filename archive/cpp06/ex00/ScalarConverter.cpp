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
	if (literalFloat(input, val))
		return TRUE;

	size_t	len = input.length();	
	if (len > 0 && input.at(len - 1) == 'f' && input.find('.') != std::string::npos)
	{
		std::istringstream	is(input.substr(0, len - 1));

		is >> val.decimal_f;
		return success(is);
	}
	return FALSE;
}

bool ScalarConverter::tryDouble( const std::string &input, set_t &val )
{
	if (literalDouble(input, val))
		return TRUE;

	std::istringstream	is(input);

	is >> val.decimal_d;
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

bool ScalarConverter::literalFloat( const std::string &input, set_t &val )
{
	for (int idx = 0; idx < CNT_LITERAL; idx++)
	{
		if (input == pesudoLiteral[idx] + "f")
		{
			val.decimal_f = pesudoLiteralVal[idx];
			return TRUE;
		}
	}
	return FALSE;
}

bool ScalarConverter::literalDouble( const std::string &input, set_t &val )
{
	for (int idx = 0; idx < CNT_LITERAL; idx++)
	{
		if (input == pesudoLiteral[idx])
		{
			val.decimal_d = pesudoLiteralVal[idx];
			return TRUE;
		}
	}
	return FALSE;
}

void ScalarConverter::fromChar( set_t &val )
{
	val.integer = static_cast<int>(val.character);
	val.decimal_f = static_cast<float>(val.character);
	val.decimal_d = static_cast<double>(val.character);
}

void ScalarConverter::fromInt( set_t &val )
{
	val.character = static_cast<char>(val.integer);
	val.decimal_f = static_cast<float>(val.integer);
	val.decimal_d = static_cast<double>(val.integer);
}

void ScalarConverter::fromFloat( set_t &val )
{
	val.character = static_cast<char>(val.decimal_f);
	val.integer = static_cast<int>(val.decimal_f);
	val.decimal_d = static_cast<double>(val.decimal_f);
}

void ScalarConverter::fromDouble( set_t &val )
{
	val.character = static_cast<char>(val.decimal_d);
	val.integer = static_cast<int>(val.decimal_d);
	val.decimal_f = static_cast<float>(val.decimal_d);
}

void ScalarConverter::print( const set_t &val )
{
	std::cout << "char: ";
	if (!std::isfinite(val.decimal_f) || exceedValue(val, CHAR) || hasDecimal(val))
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
	if (!std::isfinite(val.decimal_f) || exceedValue(val, INT) || hasDecimal(val))
		std::cout << "impossible";
	else
		std::cout << val.integer;
	newline();
	
	std::cout << "float: ";
	if (std::isfinite(val.decimal_d) && exceedValue(val, FLOAT))
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(2) << val.decimal_f << 'f';
	newline();

	std::cout << "double: " << std::fixed << std::setprecision(2) << val.decimal_d;
	newline();
}

bool ScalarConverter::exceedValue( const set_t &val, ScalarConverter::name_t type )
{
	switch (type)
	{
		case CHAR:
			return val.integer < std::numeric_limits<char>::min() ||
					val.integer > std::numeric_limits<char>::max();
		case INT:
			return val.decimal_d < std::numeric_limits<int>::min() ||
					val.decimal_d > std::numeric_limits<int>::max();
		case FLOAT:
			return val.decimal_d < -std::numeric_limits<float>::max() ||
					val.decimal_d > std::numeric_limits<float>::max();
		default:
			return FALSE;
	}
}

bool ScalarConverter::hasDecimal( const set_t &val )
{
	return val.decimal_f - static_cast<float>(val.integer) != 0;
}

void ScalarConverter::newline( void )
{
	std::cout << std::endl;
}

void ScalarConverter::printImpossible( void )
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

ScalarConverter::valueSet::valueSet( void )
: character(NONE), integer(NONE), decimal_f(NONE), decimal_d(NONE)
{
}

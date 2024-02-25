#include <iostream>
#include <string>

#include "whatever.hpp"

typedef struct test1
{
	test1( const std::string &str )
	: _str(str)
	{
	};
	
	std::string	_str;
}	test1_t;

typedef struct test2
{
	test2( const std::string &str )
	: _str(str)
	{
	};

	bool	operator<( const test2 &target ) const 
	{
		return _str < target._str;
	}

	bool	operator>( const test2 &target ) const
	{
		return _str > target._str;
	}
	
	std::string	_str;
}	test2_t;

void subject( void );

int main( void )
{
	subject();

	test1_t	t1("Hello"), t2("There");

	::swap(t1, t2);
	std::cout << t1._str << ", " << t2._str << '\n';

	/* Doesn't support comparison operator */
	// std::cout << ::min(t1, t2)._str;
	// std::cout << ::max(t1, t2)._str;
	std::cout << '\n';

	/* Does support comparison */
	test2_t	t3("Zebra"), t4("Apple");

	std::cout << ::min(t3, t4)._str << std::endl;
	std::cout << ::max(t3, t4)._str << std::endl;
	
	return 0;
}

void subject( void )
{
	int	a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << '\n';

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << '\n';
}
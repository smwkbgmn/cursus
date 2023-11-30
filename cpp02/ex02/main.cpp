#include <iostream>

#include "Fixed.hpp"

std::ostream &operator<<( std::ostream &os, const Fixed &fp)
{
	return os << fp.toFloat();
}

void	subject( void );

int main( void )
{
	subject();
	
	Fixed	a(1.5f);
	Fixed	b(1.625f);


	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * 3 << std::endl;
	std::cout << a / 3 << std::endl;

	std::cout << a-- << std::endl;
	std::cout << --a << std::endl;

	return 0;
}

void subject( void )
{
	Fixed	a;

	Fixed	const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
}

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed( void )
: _fp(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed( const int num )
{
	std::cout << "Int constructor called" << std::endl;

	_fp = num << _bitFrac;
}

Fixed::Fixed( const float fl )
{
	std::cout << "Float constructor called" << std::endl;

	_fp = (int)roundf(fl * (1 << _bitFrac));
}

Fixed::Fixed( const Fixed &fp )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = fp;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &fp )
{
	std::cout << "Copy assignment oprator called" << std::endl;
	
	_fp = fp.getRawBits();

	return *this;
}

int Fixed::getRawBits( void ) const
{
	return _fp;
}

void Fixed::setRawBits( int const raw )
{
	_fp = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)_fp / (1 << _bitFrac); 
}

int Fixed::toInt( void ) const
{
	return _fp >> _bitFrac;
}

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

// Con & Destructor
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

// Operator overload
// Assign
Fixed &Fixed::operator=( const Fixed &target )
{
	std::cout << "Copy assignment oprator called" << std::endl;

	_fp = target._fp;

	return *this;
}

// Comparison
bool Fixed::operator>( const Fixed &target ) const
{
	return _fp > target._fp;
}

bool Fixed::operator<( const Fixed &target ) const
{
	return _fp < target._fp;
}

bool Fixed::operator>=( const Fixed &target ) const
{
	return _fp >= target._fp;
}

bool Fixed::operator<=( const Fixed &target ) const
{
	return _fp <= target._fp;
}

bool Fixed::operator==( const Fixed &target ) const
{
	return _fp == target._fp;
}

bool Fixed::operator!=( const Fixed &target ) const
{
	return _fp != target._fp;
}

// Arithmetic
Fixed Fixed::operator+( const Fixed &target ) const
{
	Fixed	rst(this->toFloat() + target.toFloat());

	return rst;
}

Fixed Fixed::operator-( const Fixed &target ) const
{
	Fixed	rst(this->toFloat() - target.toFloat());

	return rst;
}

Fixed Fixed::operator*( const Fixed &target ) const
{
	Fixed	rst(this->toFloat() * target.toFloat());

	return rst;
}

Fixed Fixed::operator/( const Fixed &target ) const
{
	Fixed	rst(this->toFloat() / target.toFloat());

	return rst;
}

// In & Decreament
Fixed &Fixed::operator++( void )
{
	_fp++;

	return *this;
}

Fixed &Fixed::operator--( void )
{
	_fp--;

	return *this;
}

const Fixed Fixed::operator++( int )
{
	Fixed	res(*this);

	++(*this);

	return (res);
}

const Fixed Fixed::operator--( int )
{
	Fixed	res(*this);

	--(*this);

	return (res);
}

// Function overload
Fixed &Fixed::min(Fixed &fp1, Fixed &fp2 )
{
	return fp1 > fp2? fp2 : fp1;
}

const Fixed &Fixed::min( const Fixed &fp1, const Fixed &fp2 )
{
	return fp1 > fp2? fp2 : fp1;
}

Fixed &Fixed::max(Fixed &fp1, Fixed &fp2 )
{
	return fp1 < fp2? fp2 : fp1;
}

const Fixed &Fixed::max(const Fixed &fp1, const Fixed &fp2 )
{
	return fp1 < fp2? fp2 : fp1;
}

// Function
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
	return _fp / (1 << _bitFrac);
}

std::ostream &operator<<( std::ostream &os, const Fixed &fp)
{
	return os << fp.toFloat();
}

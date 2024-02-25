#include "Array.hpp"

/* STRUCTURE */
template<typename T>
Array<T>::badRefExcpt::badRefExcpt( void )
: range_error("error: entered value exceed range of array\n")
{
}

/* INSTANTIATE */
template<typename T>
Array<T>::Array( void )
{
	init(0);

	std::cout << "[CON] Array has created" << std::endl;
}

template<typename T>
Array<T>::Array( const Array &target )
: _ary(NULL), _size(0)
{
	*this = target;

	std::cout << "[CON-CPY] Array has created" << std::endl;
}

template<typename T>
Array<T>::Array( unsigned int n )
{
	std::cout << "some size taked [" << n << "]\n";
	init(n);

	std::cout << "[CON-USR] Array has created" << std::endl;
}

template<typename T>
Array<T>::~Array( void )
{
	clear();

	std::cout << "[DES] Array has destroyed" << std::endl;
}

/* OPERATOR */
template<typename T>
Array<T> &Array<T>::operator=( const Array &target )
{
	std::cout << "[Array's copy assignment called]" << std::endl;

	if (this != &target)
	{
		clear();
		init(target.size());
		copy(target);
	}

	return *this;
}

template<typename T>
T &Array<T>::operator[]( size_t idx ) const
{
	throwBadRef(idx);

	return _ary[idx];
}

/* MEMBER */
template<typename T>
size_t Array<T>::size( void ) const
{
	return _size;
}

template<typename T>
void Array<T>::init( size_t size )
{
	_size = size;
	
	if (!size)
		_ary = new T[0]();
	else
		_ary = new T[_size]();
}

template<typename T>
void Array<T>::clear( void )
{
	if (_ary)
	{
		delete[] _ary;
		_ary = NULL;
	}
}

template<typename T>
void Array<T>::copy( const Array &target )
{
	for (size_t idx = 0; idx < target.size(); ++idx)
		_ary[idx] = target[idx];
}

template<typename T>
void Array<T>::throwBadRef( size_t idx ) const
{
	if (!_size || idx > _size - 1)
		throw badRefExcpt();
}

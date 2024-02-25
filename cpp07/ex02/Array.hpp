#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <new>
# include <exception>

template<typename T>
class Array
{
	public:
		struct badRefExcpt
		: std::range_error
		{
			badRefExcpt( void );
		};

	public:
		Array( void );	
		Array( const Array & );
		explicit Array( unsigned int );
		~Array( void );

		Array	&operator=( const Array & );
		T		&operator[]( const size_t ) const;

	public:
		size_t	size( void ) const;

	private:
		T		*_ary;
		size_t	_size;

	private:
		void	init( size_t );
		void	clear( void );
		void	copy( const Array & );
		void	throwBadRef( size_t ) const;
};

# include "Array.tpp"

#endif
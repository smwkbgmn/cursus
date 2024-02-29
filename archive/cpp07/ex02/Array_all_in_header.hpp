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
			badRefExcpt( void )
			: range_error("error: entered value exceed range of array")
			{}
		};

	public:
		Array( void ) { init(0); }
		Array( const Array & ): _ary(NULL), _size(0) { *this = target; }
		explicit Array( unsigned int n ) { init(n); }
		~Array( void ) { clear(); }

		Array &operator=( const Array &target )
		{
			if (this != &target)
			{
				clear();
				init(target.size());
				copy(target);
			}
		}

		T &operator[]( const size_t idx )
		{
			throwBadRef(idx);
			return _ary[idx];
		}

		const T &operator[]( const size_t idx ) const
		{
			throwBadRef(idx);
			return _ary[idx];
		}

	public:
		size_t	size( void ) const { return _size; }

	private:
		T		*_ary;
		size_t	_size;

	private:
		void	init( size_t size )
		{
			_size = size;
			
			if (!size)
				_ary = new T[0]();
			else
				_ary = new T[_size]();
		}

		void	clear( void )
		{
			if (_ary)
			{
				delete[] _ary;
				_ary = NULL;
			}
		}

		void	copy( const Array &target )
		{
			for (size_t idx = 0; idx < target.size(); ++size)
				_ary[idx] = target[idx];
		}

		void	throwBadRef( size_t ) const
		{
			if (!_size || idx > _size - 1)
				throw badRefExcpt();
		}
};

#endif
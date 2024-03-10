#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>

# include <string>
# include <exception>
# include <iterator>

# include <algorithm>
# include <cmath>

/* CONTAINER */
# include <vector>
# include <deque>

typedef std::istringstream			isstream_t;
typedef std::string					str_t;
typedef std::runtime_error			err_t;

typedef unsigned int				uint_t;
typedef std::pair<uint_t, uint_t>	pair_t;

typedef std::vector<uint_t>			vec_uint_t;
typedef std::vector<pair_t>			vec_pair_t;
typedef vec_uint_t::iterator		vec_uint_iter_t;
typedef vec_pair_t::iterator		vec_pair_iter_t;

typedef std::deque<uint_t>			deq_uint_t;
typedef std::deque<pair_t>			deq_pair_t;
typedef deq_uint_t::iterator		deq_uint_iter_t;
typedef deq_pair_t::iterator		deq_pair_iter_t;

const str_t	errPrfx		= "Error: ";
const str_t	errMsg[]	= {
	errPrfx + "fail to get a value",
	errPrfx + "not found any value",
	errPrfx + "only positive integer is allowed"
};

enum errIdx {
	FAIL_GET_VAL,
	EMPTY_VAL,
	INVALID_VAL
};

enum Bool {
	FALSE,
	TRUE
};

class PmergeMe {
	public:
		static void				sort( vec_uint_t& );
		static void				sort( deq_uint_t& );
		static void				strVec( char*[], vec_uint_t& );
		static void				strDeq( char*[], deq_uint_t& );
		static void				print( const str_t&, vec_uint_t& );
		static void				print( const str_t&, deq_uint_t& );

	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe & );
		~PmergeMe( void );

		/* METHOD - VECTOR */
		static vec_pair_t		_sortedPair( vec_uint_t& );
		static void				_split( vec_uint_t&, vec_uint_t&, vec_uint_t& );
		static vec_pair_t		_merge( vec_pair_t&, vec_pair_t& );
		static void				_putOdd( vec_uint_t&, uint_t );

		static void				_insert( vec_uint_t&, vec_pair_t& );
		static vec_uint_iter_t	_search( vec_uint_iter_t, vec_uint_iter_t, uint_t );

		/* METHOD - DEQUE */
		static deq_pair_t		_sortedPair( deq_uint_t& );
		static void				_split( deq_uint_t&, deq_uint_t&, deq_uint_t& );
		static deq_pair_t		_merge( deq_pair_t&, deq_pair_t& );
		static void				_putOdd( deq_uint_t&, uint_t );

		static void				_insert( deq_uint_t&, deq_pair_t& );
		static deq_uint_iter_t	_search( deq_uint_iter_t, deq_uint_iter_t, uint_t );

		/* METHOD - COMMON */
		static size_t			_getMid( size_t );
		static pair_t			_getPair( uint_t, uint_t );
		static uint_t			_getBack( vec_uint_t& );
		static uint_t			_getBack( deq_uint_t& );
		static size_t			_nextThreshold( size_t );

		PmergeMe				&operator=( const PmergeMe & );

	/* DEBUGGING */
	private:
		static void	_dbgPrintVec( vec_uint_t& );
		static void	_dbgPrintVec( deq_uint_t& );
		static void	_dbgPrintVec( vec_pair_t& );
		static void	_dbgPrintHalf( vec_uint_t&, vec_uint_t& );

};

#endif
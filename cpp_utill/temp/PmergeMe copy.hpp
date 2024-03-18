#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>

# include <string>
# include <exception>
# include <iterator>

# include <algorithm>

// Container
# include <vector>
# include <deque>

# define LOOP 1

typedef std::istringstream			isstream_t;
typedef std::string					str_t;
typedef std::runtime_error			err_t;

typedef unsigned int				uint_t;
typedef std::pair<uint_t, uint_t>	pair_t;
typedef std::vector<uint_t>			vec_uint_t;
typedef std::vector<pair_t>			vec_pair_t;
// typedef std::deque<uint_t>			deq_t;

const str_t	errPrfx		= "Error: ";
const str_t	errMsg[]	= {
	"fail to get a value"
};

enum errIdx {
	FAIL_GET_VAL
};

class PmergeMe {
	public:
		enum Part {
			LEFT,
			MID,
			RIGHT
		};

	public:
		static void	sort( vec_uint_t& );
		// static void		sort( deq_t& );
		static void	strVec( char* argv[], vec_uint_t& );
		// static deq_t	strDeq( const str_t& );

	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe & );
		~PmergeMe( void );

		static vec_pair_t				_sortedPair( vec_uint_t& );
		static void						_split( vec_uint_t&, vec_uint_t&, vec_uint_t& );
		static vec_pair_t				_merge( vec_pair_t&, vec_pair_t& );

		static void						_insert( vec_uint_t&, vec_pair_t& );
		static vec_uint_t::iterator		_search( vec_uint_t::iterator, vec_uint_t::iterator, uint_t );

		static size_t					_getMid( size_t );
		static pair_t					_getPair( uint_t, uint_t );
		static uint_t					_getBack( vec_uint_t& );
		static size_t					_nextThreshold( size_t );

		PmergeMe						&operator=( const PmergeMe & );

	/* DEBUGGING */
	private:
		static void	_dbgPrintVec( vec_uint_t& );
		static void	_dbgPrintVec( vec_pair_t& );
		static void	_dbgPrintHalf( vec_uint_t&, vec_uint_t& );
};

#endif
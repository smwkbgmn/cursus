#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>

# include <string>
# include <exception>

// Container
# include <vector>
# include <deque>

typedef std::istringstream	isstream_t;
typedef unsigned int		uint_t;
typedef std::string			str_t;
typedef std::vector<uint_t>	vec_t;
typedef std::deque<uint_t>	deq_t;

class PmergeMe
{
	public:
		static void		sort( vec_t& );
		static void		sort( deq_t& );
		static vec_t	strVec( const str_t& );
		static deq_t	strDeq( const str_t& );

	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe & );
		~PmergeMe( void );

		static uint_t	_getVal( isstream_t& );

		PmergeMe	&operator=( const PmergeMe & );
};

#endif
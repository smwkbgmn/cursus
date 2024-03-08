#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

// Container
# include <vector>

typedef unsigned int	uint_t;

class PmergeMe
{
	/*
		ENUM
		STRUCT - FORWARD DECLARE
		TYPEDEF
	*/
	typedef std::vector<int>	vec_t;

	/* INSTANTIATE */
	/* ATTRIBUTE */
	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe & );
		~PmergeMe( void );

	/* METHOD */
	public:
		static void	sort( vec_t& ) throw();

	/* OPERATOR */
		PmergeMe	&operator=( const PmergeMe & );

	/* STRUCT - DEFINE */
};

#endif
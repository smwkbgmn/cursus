#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

class PmergeMe
{
	/*
		ENUM
		STRUCT - FORWARD DECLARE
		TYPEDEF
	*/

	/* INSTANTIATE */
	/* ATTRIBUTE */
	public:
		PmergeMe( void );
		PmergeMe( const PmergeMe & );
		~PmergeMe( void );

	/* METHOD */
	/* OPERATOR */
		PmergeMe	&operator=( const PmergeMe & );

	/* STRUCT - DEFINE */
};

#endif
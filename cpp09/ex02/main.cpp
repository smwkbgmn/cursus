#include <ctime>

#include "PmergeMe.hpp"

int main( int argc, char* argv[] ) {
	if ( argc > 1 ) {
		vec_uint_t	arrVec;
		deq_uint_t	arrDeq;

		clock_t		start;
		clock_t		timeVec;
		clock_t		timeDeq;

		try {
			++argv;

			start = clock();
			PmergeMe::strVec( argv, arrVec );
			PmergeMe::print( "Before\t: ", arrVec );

			PmergeMe::sort( arrVec );
			timeDeq = clock() - start;
			PmergeMe::print( "After\t: ", arrVec );

			start = clock();
			PmergeMe::strDeq( argv, arrDeq );
			PmergeMe::sort( arrDeq );
			timeVec = clock() - start;

			std::cout << "Time to process a range of\t" << argc - 1 <<
				" elements with std::vector\t: " << timeVec << " us\n";
			std::cout << "Time to process a range of\t" << argc - 1 <<
				" elements with std::deque\t: " << timeDeq << " us\n";

		} catch ( err_t& err ) { std::cerr << err.what() << std::endl; }
	}

	return 0;
}
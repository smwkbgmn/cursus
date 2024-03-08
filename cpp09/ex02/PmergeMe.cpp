#include "PmergeMe.hpp"

/*
	1. Group the elements of X into [n/2] pairs
	leaving one element upaired if there is an odd number of elements.

	2. Perform [n/2] comparisons, one per pair, to determine
	the larger of the two elements in each pair.

	3. RECURSIVELY sort the [n/2] larger elements from each pair,
	creating a sorted sequence S of [n/2] of the input elements,
	in ascending order.

	4. Insert at the start of S the element that was paired with the
	first and smallest element of S.

	5. Insert the remaining [n/2] - 1 element of X \ S into S, one at a
	time, with a specially chosen insertion ordering described below.
	Use BINARY SEARCH in subsequences of S (as described below) to
	determine the position at which each element should be inserted.
*/

/* METHOD */
void PmergeMe::sort( vec_t& input ) throw() {
	
}

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

	* When if just insert the remainig element as in order, the possiblity
	arise for next element to be increased search count. To avoid this,
	insert Nth element first that is end of threshold of binary search count.
*/

/* METHOD */
void PmergeMe::sort( vec_uint_t& arr ) {
	uint_t	oddval;
	if ( arr.size() % 2 == 1) {
		oddval = *arr.rbegin();
		arr.pop_back();
	}

	vec_pair_t	pairs = _sortedPair( arr );
	for ( vec_pair_t::iterator iter = pairs.begin(); iter != pairs.end(); ++iter )
		arr.push_back( iter->first );

	std::clog << "sorted pairs:\n";
	_dbgPrintVec( pairs );

	std::clog << "odd value: " << oddval << std::endl;
	std::clog << '\n';

	_insert( arr, pairs );
}

vec_pair_t PmergeMe::_sortedPair( vec_uint_t& arr ) {
	vec_uint_t	half1;
	vec_uint_t	half2;

	_split( arr, half1, half2 );
	if ( half1.size() > 1 ) {
		vec_pair_t	pair1 = _sortedPair( half1 );
		vec_pair_t	pair2 = _sortedPair( half2 );

		return _merge( pair1, pair2 );
	}
	else 
		return vec_pair_t( 1, _getPair( half1.at(0), half2.at(0) ) );
}

void PmergeMe::_split( vec_uint_t& arr, vec_uint_t& half1, vec_uint_t& half2 ) {
	for ( size_t mid = _getMid( arr.size() ); mid > 0; --mid )
		half1.push_back( _getBack( arr ) );
	
	while ( !arr.empty() )
		half2.push_back( _getBack( arr ) );
}

vec_pair_t PmergeMe::_merge( vec_pair_t& pair1, vec_pair_t& pair2 ) {
	vec_pair_t::iterator	it1 = pair1.begin();
	vec_pair_t::iterator	it2 = pair2.begin();
	uint_t					min1 = it1->first;
	uint_t					min2 = it2->first;

	vec_pair_t	merged;
	while ( it1 != pair1.end() || it2 != pair2.end() ) {
		while ( it1 != pair1.end() && 
			( min1 <= min2 || it2 == pair2.end() ) ) {
			merged.push_back( *it1++ );
			min1 = it1->first;
		}
		
		while ( it2 != pair2.end() &&
			( min2 <= min1 || it1 == pair1.end() ) ) {
			merged.push_back( *it2++ );
			min2 = it2->first;
		}
	}

	return merged;
}

void PmergeMe::_insert( vec_uint_t& arr, vec_pair_t& pairs ) {
	size_t	cycle = 1;

	for ( size_t thres = 0; thres < arr.size(); thres = _nextThreshold( thres ) ) {
		size_t	idx = _nextThreshold( thres );

		std::clog << "[cycle " << cycle++ << ", " << idx << "]\n";

		if ( idx >= pairs.size() )
			idx = pairs.size();
		
		
		size_t	right = arr.size() - ( pairs.size() - idx ) - 1;

		while ( idx > thres ) {
			uint_t	val = pairs.at( idx-- - 1 ).second;

			std::clog << "inserting " << val << '\n';

			
			arr.insert( _search( arr.begin(), arr.begin() + right, val ), val );
			
			std::clog << "\tresult: ";
			_dbgPrintVec( arr );
			std::clog << '\n';
		}
	}	
}

vec_uint_t::iterator PmergeMe::_search( vec_uint_t::iterator left, vec_uint_t::iterator right, uint_t val ) {
	vec_uint_t::iterator	mid = left + ( std::distance( left, right ) / 2 );

	std::clog << "\tBinarySearch: " << *left << ", " << *mid << ", " << *right << std::endl;
	
	if ( mid != left )
		return val < *mid? _search( left, mid, val ) : _search( mid + 1, right, val );
	else
		return val < *left? left : right;
}




size_t PmergeMe::_getMid( size_t arrSize ) {
	size_t	mid = arrSize / 2;
	
	return mid + ( mid % 2 == 1 && mid > 1 );
}

pair_t PmergeMe::_getPair( uint_t val1, uint_t val2 ) {
	return val1 > val2?
		pair_t( val1, val2 ) : pair_t( val2, val1 );
}

uint_t PmergeMe::_getBack( vec_uint_t& arr ) {
	uint_t	val = arr.at( arr.size() - 1 );
	arr.pop_back();
	
	return val;
}

size_t PmergeMe::_nextThreshold( size_t thres ) {
	return std::pow( 2, thres + 1 ) - 1;
}




void PmergeMe::strVec( char* argv[], vec_uint_t& vec ) {
	while ( *argv ) {
		isstream_t	iss( *argv++ );
		uint_t		val;

		// discard negative one.
		// it may take negative value resulting underflow.

		iss >> val;
		if ( iss.fail() )
			throw err_t( errMsg[FAIL_GET_VAL] );
		
		vec.push_back( val );
	}
}






/******** DEBUGGING *********/
void PmergeMe::_dbgPrintVec( vec_uint_t& vec ) {
	vec_uint_t::iterator	start = vec.begin();

	while ( start != vec.end() )
		std::cout << *start++ << ' ';
	std::cout << std::endl;
}

void PmergeMe::_dbgPrintVec( vec_pair_t& pairs ) {
	vec_pair_t::iterator	iter = pairs.begin();

	while ( iter != pairs.end() ) {
		std::clog << iter->first << ", " << iter->second << std::endl;
		iter++;
	}
}

void PmergeMe::_dbgPrintHalf( vec_uint_t& arr, vec_uint_t& half ) {
	std::clog << "doHalf\tarr\t: ";
	_dbgPrintVec( arr );
	
	std::clog << "\thalf\t: ";
	_dbgPrintVec( half );
	std::clog << '\n';
}
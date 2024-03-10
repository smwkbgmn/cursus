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

/* METHOD - VECTOR */
void PmergeMe::sort( vec_uint_t& arr ) {
	if ( !arr.size() )
		throw err_t( errMsg[EMPTY_VAL] );

	if ( arr.size() > 1) {
		bool	odd = FALSE;
		uint_t	val = 0;

		if ( arr.size() % 2 == 1) {
			odd = TRUE;
			val = _getBack( arr );
		}

		vec_pair_t	pairs = _sortedPair( arr );
		for ( vec_pair_iter_t iter = pairs.begin(); iter != pairs.end(); ++iter )
			arr.push_back( iter->first );

		_insert( arr, pairs );
		if ( odd )
			_putOdd( arr, val );
	}
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
	vec_pair_iter_t	it1 = pair1.begin();
	vec_pair_iter_t	it2 = pair2.begin();

	vec_pair_t	merged;
	while ( it1 != pair1.end() || it2 != pair2.end() ) {
		while ( it1 != pair1.end() && 
			( it1->first <= it2->first || it2 == pair2.end() ) )
			merged.push_back( *it1++ );
		
		while ( it2 != pair2.end() &&
			( it2->first <= it1->first || it1 == pair1.end() ) )
			merged.push_back( *it2++ );
	}

	return merged;
}

void PmergeMe::_putOdd( vec_uint_t& arr, uint_t val ) {
	if ( val <= *arr.rbegin() ) {
		vec_uint_iter_t	iter = arr.begin();

		arr.insert( _search( iter, iter + arr.size() - 1, val ), val );
	}
	else
		arr.push_back( val );
}

void PmergeMe::_insert( vec_uint_t& arr, vec_pair_t& pairs ) {
	for ( size_t thres = 0; thres < arr.size(); thres = _nextThreshold( thres ) ) {
		size_t	idx = _nextThreshold( thres );

		if ( idx > pairs.size() )
			idx = pairs.size();

		size_t	right = arr.size() - ( pairs.size() - idx ) - 1;
		while ( idx > thres ) {
			uint_t	val = pairs.at( idx-- - 1 ).second;

			arr.insert( _search( arr.begin(), arr.begin() + right, val ), val );	
		}
	}
}

vec_uint_iter_t PmergeMe::_search( vec_uint_iter_t left, vec_uint_iter_t right, uint_t val ) {
	vec_uint_iter_t	mid = left + ( std::distance( left, right ) / 2 );

	if ( mid != left )
		return val < *mid? _search( left, mid, val ) : _search( mid + 1, right, val );
	else
		return val < *left? left : right;
}



/* METHOD - DEQUE */
void PmergeMe::sort( deq_uint_t& arr ) {
	if ( !arr.size() )
		throw err_t( errMsg[EMPTY_VAL] );

	if ( arr.size() > 1) {
		bool	odd = FALSE;
		uint_t	val = 0;

		if ( arr.size() % 2 == 1) {
			odd = TRUE;
			val = _getBack( arr );
		}

		deq_pair_t	pairs = _sortedPair( arr );
		for ( deq_pair_iter_t iter = pairs.begin(); iter != pairs.end(); ++iter )
			arr.push_back( iter->first );

		_insert( arr, pairs );
		if ( odd )
			_putOdd( arr, val );
	}
}

deq_pair_t PmergeMe::_sortedPair( deq_uint_t& arr ) {
	deq_uint_t	half1;
	deq_uint_t	half2;

	_split( arr, half1, half2 );
	if ( half1.size() > 1 ) {
		deq_pair_t	pair1 = _sortedPair( half1 );
		deq_pair_t	pair2 = _sortedPair( half2 );

		return _merge( pair1, pair2 );
	}
	else 
		return deq_pair_t( 1, _getPair( half1.at(0), half2.at(0) ) );
}

void PmergeMe::_split( deq_uint_t& arr, deq_uint_t& half1, deq_uint_t& half2 ) {
	for ( size_t mid = _getMid( arr.size() ); mid > 0; --mid )
		half1.push_back( _getBack( arr ) );
	
	while ( !arr.empty() )
		half2.push_back( _getBack( arr ) );
}

deq_pair_t PmergeMe::_merge( deq_pair_t& pair1, deq_pair_t& pair2 ) {
	deq_pair_iter_t	it1 = pair1.begin();
	deq_pair_iter_t	it2 = pair2.begin();

	deq_pair_t	merged;
	while ( it1 != pair1.end() || it2 != pair2.end() ) {
		while ( it1 != pair1.end() && 
			( it1->first <= it2->first || it2 == pair2.end() ) )
			merged.push_back( *it1++ );
		
		while ( it2 != pair2.end() &&
			( it2->first <= it1->first || it1 == pair1.end() ) )
			merged.push_back( *it2++ );
	}

	return merged;
}

void PmergeMe::_putOdd( deq_uint_t& arr, uint_t val ) {
	if ( val < *arr.rbegin() ) {
		deq_uint_iter_t	iter = arr.begin();

		arr.insert( _search( iter, iter + arr.size() - 1, val ), val );
	}
	else
		arr.push_back( val );
}

void PmergeMe::_insert( deq_uint_t& arr, deq_pair_t& pairs ) {
	for ( size_t thres = 0; thres < arr.size(); thres = _nextThreshold( thres ) ) {
		size_t	idx = _nextThreshold( thres );

		if ( idx > pairs.size() )
			idx = pairs.size();

		size_t	right = arr.size() - ( pairs.size() - idx ) - 1;
		while ( idx > thres ) {
			uint_t	val = pairs.at( idx-- - 1 ).second;

			arr.insert( _search( arr.begin(), arr.begin() + right, val ), val );	
		}
	}	
}

deq_uint_iter_t PmergeMe::_search( deq_uint_iter_t left, deq_uint_iter_t right, uint_t val ) {
	deq_uint_iter_t	mid = left + ( std::distance( left, right ) / 2 );

	if ( mid != left )
		return val < *mid? _search( left, mid, val ) : _search( mid + 1, right, val );
	else
		return val < *left? left : right;
}



/* METHOD - COMMON */
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

uint_t PmergeMe::_getBack( deq_uint_t& arr ) {
	uint_t	val = arr.at( arr.size() - 1 );
	arr.pop_back();
	
	return val;
}

size_t PmergeMe::_nextThreshold( size_t thres ) {
	return std::pow( 2, thres + 1 ) - 1;
}



/* UTILL */
void PmergeMe::strVec( char* argv[], vec_uint_t& vec ) {
	while ( *argv ) {
		isstream_t	iss( *argv++ );
		uint_t		val;

		if ( iss.peek() == '-' )
			throw err_t( errMsg[INVALID_VAL] );

		iss >> val;
		if ( !iss.eof() || iss.fail() )
			throw err_t( errMsg[FAIL_GET_VAL] );
		
		vec.push_back( val );
	}
}

void PmergeMe::strDeq( char* argv[], deq_uint_t& deq ) {
	while ( *argv ) {
		isstream_t	iss( *argv++ );
		uint_t		val;

		if ( iss.peek() == '-' )
			throw err_t( errMsg[INVALID_VAL] );

		iss >> val;
		if ( !iss.eof() || iss.fail() )
			throw err_t( errMsg[FAIL_GET_VAL] );
		
		deq.push_back( val );
	}
}

void PmergeMe::print( const str_t& prfx, vec_uint_t& vec ) {
	vec_uint_iter_t iter = vec.begin();

	std::cout << prfx;
	while ( iter != vec.end() )
		std::cout << *iter++ << ' ';
	std::cout << std::endl;
}

void PmergeMe::print( const str_t& prfx, deq_uint_t& vec ) {
	deq_uint_iter_t iter = vec.begin();

	std::cout << prfx;
	while ( iter != vec.end() )
		std::cout << *iter++ << ' ';
	std::cout << std::endl;
}

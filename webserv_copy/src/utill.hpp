#ifndef UTILL_HPP
# define UTILL_HPP

# include "structure.hpp"

# define NOT_FOUND -1

template<typename Container, typename Target> typename Container::iterator
lookup( Container& obj, Target token ) { return std::find( obj.begin(), obj.end(), token ); }

template<typename Container, typename Target> typename Container::const_iterator
lookup( const Container& obj, Target token ) { return std::find( obj.begin(), obj.end(), token ); }

template<typename Container, typename Target> ssize_t
distance( Container& obj, Target token ) {
	typename Container::iterator	iter = lookup( obj, token );

	if ( iter != obj.end() ) return std::distance( obj.begin(), iter );
	else return -1;
}

/* UTILL */
bool		found( const size_t& );

/* FILE INFO */
bool		getInfo( const str_t&, fstat_t& );
bool		isExist( const str_t& );
bool		isDir( const fstat_t& );

/* BUILT-IN SCRIPT */
void		errpageScript( sstream_t&, const uint_t&, const str_t& );
void		autoindexScript( const path_t&, sstream_t& );

#endif
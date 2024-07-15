#ifndef UTILL_HPP
# define UTILL_HPP

# include "structure.hpp"

# define NOT_FOUND -1

/* UTILL */
bool 			dead( const process_t& );
bool			found( const size_t& );
str_t			token( isstream_t&, const char& );

/* FILE INFO */
bool			getInfo( const str_t&, fstat_t& );
bool			isExist( const str_t& );
bool			isDir( const fstat_t& );

/* TIME */
ctime_t			getNow( void );
str_t			timeToStr( const ctime_t& );

/* BUILT-IN SCRIPT */
void			errpageScript( sstream_t&, const uint_t&, const str_t& );
void			autoindexScript( const path_t&, sstream_t& );

/* TEMPLETE FUNCTION */

// lookup: get iterator for matching with the token whitin container object
template<typename Container, typename Target> typename Container::iterator
lookup( Container& obj, Target token ) { return std::find( obj.begin(), obj.end(), token ); }

template<typename Container, typename Target> typename Container::const_iterator
lookup( const Container& obj, Target token ) { return std::find( obj.begin(), obj.end(), token ); }

// distance: get index of container object matching with the token
template<typename Container, typename Target> ssize_t
distance( Container& obj, Target token ) {
	typename Container::iterator	iter = lookup( obj, token );

	if ( iter != obj.end() ) return std::distance( obj.begin(), iter );
	else return -1;
}

template<typename Container, typename Target> ssize_t
distance( const Container& obj, const Target token ) {
	typename Container::const_iterator	iter = lookup( obj, token );

	if ( iter != obj.end() ) return std::distance( obj.begin(), iter );
	else return -1;
}

// streamsize: get size of stream object
// not actually alloc'd size, but from the current positon to end
typedef std::streamsize	streamsize_t;
typedef std::streampos	streampos_t;

template<typename Stream> streamsize_t
streamsize( Stream& obj ) {
	streampos_t curnt = obj.tellg();
	if ( curnt == streampos_t( ERROR ) ) return 0;

	obj.seekg( 0, std::ios::end );
	streampos_t end = obj.tellg();
	if ( end == streampos_t( ERROR ) ) return 0;

	streampos_t result = end - curnt;
	obj.seekg( curnt );
	
	return result;	
}

#endif
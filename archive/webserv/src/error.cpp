#include "error.hpp"

void
throwSysErr( const str_t& fnName, const uint_t& code ) {
	perror( fnName.c_str() );
	throw errstat_t( code, 0 );
}

void
throwSysErr( const str_t& fnName, const uint_t& code, const size_t& confidx ) {
	perror( fnName.c_str() );
	throw errstat_t( code, confidx );
}

errstat_s::errstat_s( const uint_t& status ): err_t( "something gone wrong" ), code( status ), confidx( 0 ) {}
errstat_s::errstat_s( const uint_t& status, const size_t& idx ): err_t( "something gone wrong" ), code( status ), confidx( idx ) {}
errstat_s::errstat_s( const uint_t& status, const str_t& msg ): err_t( msg ), code( status ), confidx( 0 ) {}
errstat_s::errstat_s( const uint_t& status, const str_t& msg, const size_t& idx ): err_t( msg ), code( status ), confidx( idx ) {}
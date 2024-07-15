#include "webserv.hpp"

int
main( int argc, char* argv[] ) {
	try { if ( argc == 1 || argc == 2 ) run( argc, argv ); }
	catch ( exception_t &exc ) { log( str_t( exc.what() ) ); }

	return EXIT_FAILURE;
}

void
run( const int& argc, char* const argv[] ) {
	vec_config_t confs;

	if ( argc == 2 ) parseConfig( confs, argv[1] );
	else {
		confs.push_back( config_t() );
		confs.front().locations.push_back( location_t( confs.front() ) );
	} 

	HTTP::init();

	Server server( confs );
	server.connectsever( confs );
}

#include "RPN.hpp"

int main( int argc, char *argv[] ) {
	if ( argc == 2 )
		try { std::cout << RPN::calculate( argv[1] ) << std::endl ; }
		catch ( err_t &err ) { std::cerr << err.what() << std::endl; }

	return 0;
}
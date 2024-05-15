#include <iostream>

int main( int argc, char* argv[], char* env[] ) {
	if ( argc )
		std::cout << "0123456789";

	( void )argv;
	( void )env;
	
	return 0;
}
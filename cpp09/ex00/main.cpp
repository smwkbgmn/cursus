#include "BitcoinExchange.hpp"

int main( int argc, char *argv[] )
{
	if ( argc == 2 ) {
		try {
			BitcoinExchange	myData( "data.csv" );
			myData.outResult( argv[1] );
		} catch ( err_t &err ) { std::cerr << err.what() << std::endl; }
	}
	else
		std::cerr << errPrfx + "please enter a file" << std::endl;

	return 0;
}
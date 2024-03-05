#include "BitcoinExchange.hpp"

int main( int argc, char *argv[] )
{
	if ( argc == 2 ) {
		try {
			BitcoinExchange	myData( "data.csv" );
			myData.outResult( argv[1] );
		} catch ( err_t &err ) { std::cout << err.what() << std::endl; }
	}

	return 0;
}
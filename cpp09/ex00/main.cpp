#include "BitcoinExchange.hpp"

// int main( int argc, char *argv[] )
int main( void )
{
	try {
		BitcoinExchange	myData("data.csv");
		myData.outResult("input.txt");
	} catch ( err_t &err ) { std::cout << err.what() << std::endl; }

	return 0;
}
#include "Sed.hpp"

int main( int argc, char *argv[] )
{
	if (Sed::valid( argc, argv ))
		Sed::proceed( argv );
		
	return 0;
}

#include "Sed.hpp"

int main( int argc, char *argv[] )
{
	Sed	sed;

	if (Sed::valid( argc, argv ))
		sed.proceed( argv );
		
	return 0;
}

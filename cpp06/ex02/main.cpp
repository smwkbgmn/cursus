#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );

int main( void )
{
	Base	*base = NULL;

	identify(base);
	std::cout << '\n';

	base = new A;
	identify(base); 
	identify(*base);
	delete base;
	std::cout << '\n';

	base = new B;
	identify(base); 
	identify(*base);
	delete base;
	std::cout << '\n';

	base = new C;
	identify(base); 
	identify(*base);
	delete base;
	std::cout << '\n';

	base = generate();
	identify(base);
	identify(*base);
	delete base;
	std::cout << '\n';

	return 0;
}

Base *generate( void )
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	switch (std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify( Base *p )
{
	if (p)
	{
		std::cout << "The actual type of object is ";
		if (dynamic_cast<A *>(p))
			std::cout << 'A';
		else
		{
			if (dynamic_cast<B *>(p))
				std::cout << 'B';
			else
				std::cout << 'C';
		}
	}
	else
		std::cout << "The pointer to Base is pointing nothing";
	std::cout << std::endl;
}

void identify( Base &p )
{
	std::cout << "The actual type of object is ";
	try
	{
		A	ra = dynamic_cast<A &>(p);
		std::cout << 'A';
	}
	catch (std::exception &excpt)
	{
		try
		{
			B	rb = dynamic_cast<B &>(p);
			std::cout << 'B';
		}
		catch (std::exception &excpt)
		{	
			std::cout << 'C';
		}
	}
	std::cout << std::endl;		
}
#include <string>
#include <iostream>

#include "iter.hpp"

template<typename T>
void print( const T &obj )
{
	std::cout << obj;
}

template<typename T>
void addone( T &obj )
{
	obj += 1;
}

template<typename T>
void addstar( T &obj )
{
	obj += '*';
}

int main( void )
{
	std::string	str("Hello");
	int			num[5] = {0, 1, 2, 3, 4};
	const int	num_const[5] = {5, 6, 7, 8, 9};

	iter(&str, 1, &print);
	std::cout << '\n';
	iter(num, 5, &print);
	std::cout << '\n';
	iter(num_const, 5, &print);
	std::cout << "\n\n";

	iter(num, 5, &addone);
	// iter(num_const, 5, &addone);
	// Const prevent value to be modified
	iter(num, 5, &print);
	std::cout << "\n\n";

	iter(&str, 1, &addstar);
	iter(num, 5, &addstar);

	iter(&str, 1, &print);
	std::cout << '\n';
	iter(num, 5, &print);
	std::cout << '\n';

	return 0;
}


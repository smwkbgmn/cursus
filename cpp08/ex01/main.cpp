#include <cstdlib>
#include <ctime>

#include "Span.hpp"

void	subject( void );
void	randN( void );
void	noSpan( void );
void	assignRandN( std::set<int>& target, unsigned int n );

int main( void ) {
	subject();
	std::cout << std::endl;

	noSpan();
	std::cout << std::endl;

	randN();
	std::cout << std::endl;

	return 0;
}

void subject( void ) {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void noSpan( void ) {
	try {
		Span	noSize(0);

		noSize.addNumber(42);
	} catch (std::exception &excpt) { std::cout << excpt.what() << '\n'; }

	try {
		Span	noSpan;

		std::cout << noSpan.shortestSpan() << '\n';
		std::cout << noSpan.longestSpan() << '\n';
	} catch (std::exception &excpt) { std::cout << excpt.what() << '\n'; }

	try {
		Span	noSpan(1);

		noSpan.addNumber(42);
		std::cout << noSpan.shortestSpan() << '\n';
		std::cout << noSpan.longestSpan() << '\n';
	} catch (std::exception &excpt) { std::cout << excpt.what() << '\n'; }
}

void randN( void ) {
	std::set<int>	randN;
	assignRandN(randN, 15000);
	
	try {
		Span	sp(15000);
		sp.addNumber(randN.begin(), randN.end());
	
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';
	} catch (std::exception &excpt) { std::cout << excpt.what() << '\n'; }
}

void assignRandN( std::set<int>& target, unsigned int n ) {
	std::srand(std::time(NULL));
	
	while (target.size() < n)
		target.insert(std::rand());
}
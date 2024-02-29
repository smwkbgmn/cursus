#include "Span.hpp"

/* STRUCTURE */
Span::duplicationExcpt::duplicationExcpt( void )
: runtime_error("Entered value already exist") {}

Span::exceedSizeExcpt::exceedSizeExcpt( void )
: runtime_error("No space has left") {}

Span::noSpanExcpt::noSpanExcpt( void )
: runtime_error("Span has not found. Ensure some elements are in") {}

/* INSTANTIATE */
Span::Span( void ): _size(0) {
	std::cout << "[CON] Span has created" << std::endl;
}

Span::Span( const Span& target ) {
	*this = target;

	std::cout << "[CON-CPY] Span has created" << std::endl;	
}

Span::Span( unsigned int n ): _size(n) {
	std::cout << "[CON-USR] Span has created" << std::endl;
}

Span::~Span( void ) {
	std::cout << "[DES] Span has destroyed" << std::endl;
}

/* MEMBER */
void Span::addNumber( int n ) {
	throwExceedSize();
	throwDuplication(n);
	
	_elem.insert(n);
}

void Span::addNumber( iterator begin, iterator end )
{
	// while (begin != end)
	// 	addNumber(*begin++);
	
	_elem.insert(begin, end);
}

unsigned int Span::shortestSpan( void ) const {
	throwNoSpan();

	unsigned int	shortest = longestSpan();

	for (iterator it = _elem.begin(); it != _elem.end(); ++it) {
		unsigned int span = *_elem.upper_bound(*it) - *it;
		if (span < shortest && span != 0)
			shortest = span;
	}

	return shortest;
}

unsigned int Span::longestSpan( void ) const {
	throwNoSpan();

	return *_elem.rbegin() - *_elem.begin();
}

void Span::throwExceedSize( void ) const {
	if (_elem.size() == _size)
		throw exceedSizeExcpt();
}

void Span::throwDuplication( int n ) const {
	if (std::find(_elem.begin(), _elem.end(), n) != _elem.end())
		throw duplicationExcpt();
}

void Span::throwNoSpan( void ) const {
	if (_elem.size() < 2)
		throw noSpanExcpt();
}

/* OPERATOR */
Span& Span::operator=( const Span& target ) {
	
	std::cout << "[Span's copy assignment called]" << std::endl;

	if (this != &target)
	{
		_elem.clear();
		_elem = target._elem;
		_size = target._size;
	}
	return *this;
}

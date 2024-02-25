#include "Data.hpp"

Data::Data( void )
:_integer(0), _name("noname")
{
}

Data::Data( const int &integer, const std::string &name )
: _integer(integer), _name(name)
{
}

std::ostream &operator<<(std::ostream &os, const Data &target)
{
	os << target._integer << ", " << target._name << std::endl;

	return os;
}
#include "Serializer.hpp"
#include "Data.hpp"

uintptr_t Serializer::serialize( Data *target )
{
	return reinterpret_cast<uintptr_t>(target);
}

Data *Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data *>(raw);
}
#include <new>
#include <ios>

#include "Data.hpp"
#include "Serializer.hpp"

void printAddress( void *ptr );
void printAddressUint( uintptr_t ptr );

int main( void )
{
	Data	*info = new Data(42, "Snufkin");

	std::cout << *info;
	std::cout << *Serializer::deserialize(Serializer::serialize(info)) << std::endl;

	uintptr_t	serialized = Serializer::serialize(info);
	Data		*deserialized = Serializer::deserialize(serialized);

	std::cout << "Original pointer\n";
	std::cout << "\traw bits: ";
	printAddress(info);
	std::cout << "\taddress: ";
	std::cout << info << '\n' << std::endl;

	std::cout << "Serialized data\n";
	std::cout << "\traw bits: ";
	printAddressUint(serialized);
	std::cout << "\tvalue: ";
	std::cout << "0x" << std::hex << serialized << '\n' << std::endl;

	std::cout << "Deserialized pointer\n";
	std::cout << "\traw bits: ";
	printAddress(deserialized);
	std::cout << "\taddress: ";
	std::cout << deserialized << std::endl;

	delete info;
	
	return 0;
}

void printAddress( void *ptr )
{
	size_t size = sizeof(ptr);

    const unsigned char *bytes = reinterpret_cast<const unsigned char *>(&ptr);
    for (size_t idx = 0; idx < size; ++idx)
	{
        for (int bit = 7; bit >= 0; --bit)
		{
            int raw = (bytes[idx] >> bit) & 01;
            std::cout << raw;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

void printAddressUint( uintptr_t ptr )
{
	for (size_t len = sizeof(ptr) * 8; len > 0; --len)
	{
		std::cout << (ptr >> (len - 1) & 01);
		if ((len - 1) % 8 == 0)
			std::cout << " ";
	}
	std::cout << std::endl;
}
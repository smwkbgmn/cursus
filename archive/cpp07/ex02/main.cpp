#include "Array.hpp"

int main( void )
{
	try
	{
		Array<int>			integer(3);
		Array<std::string>	str(3);

		for (size_t idx = 0; idx < 3; ++idx)
		{
			integer[idx] = idx;
			str[idx] = '0' + idx;
			std::cout << integer[idx] << ", " << str[idx] << '\n'; 
		}
		
		Array<int>			integer_cpy(integer);
		Array<std::string>	str_cpy;
		str_cpy = str;

		for (size_t idx = 0; idx < 3; ++idx)
			std::cout << integer_cpy[idx] << ", " << str_cpy[idx] << '\n'; 

		integer_cpy[0] = 100;
		std::cout << integer[0] << ", " << integer_cpy[0] << '\n';

		integer[3] = 42;
	}
	catch (std::exception &excpt)
	{
		std::cout << excpt.what();
	}

	return 0;
}
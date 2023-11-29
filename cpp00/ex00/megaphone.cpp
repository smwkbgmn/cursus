#include <iostream>
#include <string>
#include <cctype>

std::string toupper_str( char *str_c );

int main( int argc, char *argv[] )
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int ptr = 1; ptr < argc; ++ptr)
			std::cout << toupper_str(argv[ptr]);
	}
	std::cout << std::endl;
}

std::string toupper_str( char *str_c )
{
	std::string	str = str_c;
	size_t		len = str.length();

	for (int idx = 0; idx < len; ++idx)
		str[idx] = (char)(std::toupper((unsigned char)str_c[idx]));

	return str;
}

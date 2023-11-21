#include <iostream>
#include <cctype>

char	*toupper_str(char *arg);

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int ptr = 1; ptr < ac; ++ptr)
			std::cout << toupper_str(av[ptr]);
	}
	std::cout << "\n";
}

char	*toupper_str(char *arg)
{
	int	idx = 0;

	while (arg[idx])
	{
		arg[idx] = static_cast<char>(toupper(static_cast<unsigned char>(arg[idx])));
		idx++;
	}
	return (arg);
}

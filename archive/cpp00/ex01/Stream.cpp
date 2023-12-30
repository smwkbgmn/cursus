#include "Stream.hpp"

bool Stream::std_cin(std::string &target)
{
	std::getline(std::cin, target);

	if (std::cin.eof())
		exit_error("\nyou may not enter EOF");
	if (std::cin.fail())
		exit_error("fatal error occured");
	if (target.empty() || !valid(target))
	{
		std::cout << "you may not enter empty string" << std::endl;
		return FALSE;
	}
	return TRUE;
}

bool Stream::std_cin(int *target)
{
	std::cin >> *target;
	
	if (std::cin.eof())
		exit_error("\nyou may not enter EOF");
	if (std::cin.peek() != '\n')
	{
		std::cout << "you may only enter a number" << std::endl;
		flush_istream();
		return FALSE;
	}
	if (std::cin.fail())
	{
		std::cout << "you may only enter a number within range of integer" << std::endl;
		std::cin.clear();
		flush_istream();
		return FALSE;
	}
	flush_istream();
	return TRUE;
}

void Stream::flush_istream(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Stream::valid(std::string input)
{
	size_t	size;

	size = input.size();
	if (size)
	{
		for (int idx = 0; idx < size; ++idx)
			if (!isspace(input[idx]))
				return TRUE;
	}		
	return FALSE;
}

void Stream::exit_error(std::string const &msg)
{
	std::cout << msg << std::endl;
	std::exit(EXIT_FAILURE);
}

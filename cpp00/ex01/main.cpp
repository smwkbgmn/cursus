#include <cctype>
#include <stdexcept>
#include <iostream>
#include <limits>

#include "PhoneBook.hpp"

static void	prompt(PhoneBook &book);

int main(void)
{
	PhoneBook	book;

	while (LOOP)
	{
		prompt(book);
		std::cout << std::endl;
	}
}

static void prompt(PhoneBook &book)
{
	std::string	input;

	std::cout << "Command: ";
	if (std_cin(input))
	{
		if (input == "ADD")
			book.Add(book);
		else if (input == "SEARCH")
			book.Search(book);
		else if (input == "EXIT")
			book.Exit();
		else
			std::cout << "please type correct command\n"
				<< "(ADD, SEARCH, EXIT)" << std::endl;
	}
}

static void	exit_error(std::string const &msg);
static bool	valid(std::string input);
static void flush_istream(void);

bool std_cin(std::string &target)
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

bool std_cin(int *target)
{
	std::cin >> *target;
	
	if (std::cin.eof())
		exit_error("\nyou may not enter EOF");
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

static void flush_istream(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static bool valid(std::string input)
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

static void exit_error(std::string const &msg)
{
	std::cout << msg << std::endl;
	std::exit(EXIT_FAILURE);
}

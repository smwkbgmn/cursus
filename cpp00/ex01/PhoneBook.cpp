#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
: idx(0)
{
}

// PROMPT
bool PhoneBook::prompt(void)
{
	std::string	input;

	std::cout << "Command: ";
	if (Stream::std_cin(input))
	{
		if (input == "ADD")
			add();
		else if (input == "SEARCH")
			search();
		else if (input == "EXIT")
			exit();
		else
			std::cout << "please type correct command\n"
				<< "(ADD, SEARCH, EXIT)" << std::endl;
	}
	return TRUE;
}

// ADD
void PhoneBook::add(void)
{
	for (int order = 0; order < 5; ++order)
		while (!queryAdd(contact[idx], order));
	++idx %= 8;
}

bool PhoneBook::queryAdd(Contact &contact, int order)
{
	switch (order)
	{
		case 0: ask("First name?");
			break ;
		case 1: ask("Last name?");
			break ;
		case 2: ask("Nickname?");
			break ;
		case 3: ask("Phone number?");
			break ;
		case 4: ask("What is your secretary secret?");
			break ;
	}
	return Stream::std_cin(contact[order]);
}

void PhoneBook::ask(const char *msg)
{
	std::cout << msg << ' ';
}

// SEARCH
void PhoneBook::search(void)
{
	int input = 0;
	
	if (contact[0][0].empty())
		std::cout << "nothing has saved on this phonebook" << std::endl;
	else
	{
		showList();
		
		while (!querySearch(&input));
		if (input < 1 || input > 8)
			std::cout << "wrong index, plese type between 1-8\n";
		else if (contact[input - 1][0].empty())
			std::cout << "that contact is empty\n";
		else
			printContact(contact[input - 1]);
	}
}

void PhoneBook::showList(void)
{
	for (int idx = 0; idx < 8 && !contact[idx][0].empty(); ++idx)
	{
		std::cout << format << idx + 1 << '|';
		std::cout << format << truncate(contact[idx][0]) << '|';
		std::cout << format << truncate(contact[idx][1]) << '|';
		std::cout << format << truncate(contact[idx][2]) << std::endl;
	}
}

std::ostream &format(std::ostream &os)
{
	return os << std::setw(10) << std::setfill(' ') << std::right;;
}

std::string PhoneBook::truncate(std::string const &src)
{
	std::string	rst;

	if (src.size() > 10)
	{
		rst = src.substr(0, 9);
		rst += ".";
	}
	else
		rst.assign(src);
	return (rst);
}

bool PhoneBook::querySearch(int *input)
{
	std::cout << "Which contact do you want to see? ";
	return Stream::std_cin(input);
}

void PhoneBook::printContact(Contact &contact)
{
	for (int order = 0; order < 5; ++order)
		std::cout << contact[order] << std::endl;
}

// EXIT
void PhoneBook::exit(void)
{
	std::exit(EXIT_SUCCESS);
}

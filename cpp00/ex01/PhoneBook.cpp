#include <cstdlib>
#include <iomanip>

#include "PhoneBook.hpp"

static bool	query_add(Contact &, int);
static void	ask(const char *);

void PhoneBook::Add(PhoneBook &book)
{
	for (int order = 0; order < 5; ++order)
		while (!query_add(book[book.idx], order));
	++(book.idx) %= 8;
}

static bool query_add(Contact &contact, int order)
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
	return std_cin(contact[order]);
}

static void ask(const char *msg)
{
	std::cout << msg << ' ';
}

static bool			query_search(PhoneBook &, int *);
static void 		show_list(PhoneBook &);
static std::ostream	&format(std::ostream &);
static std::string	truncate(std::string const &);
static void			print_contact(Contact &);

void PhoneBook::Search(PhoneBook &book)
{
	int input = 0;
	
	if (book[0][0].empty())
		std::cout << "nothing has saved on this phonebook" << std::endl;
	else
	{
		show_list(book);
		
		while (!query_search(book, &input));
		if (input < 1 || input > 8)
			std::cout << "wrong index, plese type between 1-8\n";
		else if (book[input - 1][0].empty())
			std::cout << "that contact is empty\n";
		else
			print_contact(book[input - 1]);
	}
}

static bool query_search(PhoneBook &book, int *input)
{
	std::cout << "Which contact do you want to see? ";
	return std_cin(input);
}

static void show_list(PhoneBook &book)
{
	for (int idx = 0; idx < 8 && !book[idx][0].empty(); ++idx)
	{
		std::cout << format << idx + 1 << '|';
		std::cout << format << truncate(book[idx][0]) << '|';
		std::cout << format << truncate(book[idx][1]) << '|';
		std::cout << format << truncate(book[idx][2]) << std::endl;
	}
}

static std::ostream	&format(std::ostream &os)
{
	return os << std::setw(10) << std::setfill(' ') << std::right;
}

static std::string truncate(std::string const &src)
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

static void print_contact(Contact &contact)
{
	for (int order = 0; order < 5; ++order)
		std::cout << contact[order] << std::endl;
}

void PhoneBook::Exit(void)
{
	std::exit(EXIT_SUCCESS);
}

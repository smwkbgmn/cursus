#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	book;

	while (book.prompt())
		std::cout << std::endl;
}

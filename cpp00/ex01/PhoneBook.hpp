#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define FALSE 0
# define TRUE 1
# define LOOP 1

bool std_cin(std::string &target);
bool std_cin(int *target);

class PhoneBook
{
	public:
		PhoneBook(void);

		Contact	&operator[](int idx);

		void	Add(PhoneBook &);
		void	Search(PhoneBook &);
		void	Exit(void);
		
	private:
		Contact	contact[8];
		int		idx;
};

#endif
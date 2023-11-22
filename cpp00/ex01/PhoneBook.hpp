#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>

# define FALSE 0
# define TRUE 1
# define LOOP 1

bool std_cin(std::string &target);
bool std_cin(int *target);

class Contact
{
	public:
		std::string &operator[](int which)
		{
			switch (which)
			{
				case 0: return (name_f);
				case 1: return (name_l);
				case 2: return (nick);
				case 3: return (phone);
				case 4: return (secret);
			}
			return (phone);
		}

	private:
		std::string	name_f;
		std::string	name_l;
		std::string	nick;
		std::string	phone;
		std::string	secret;
};

class PhoneBook
{
	public:
		PhoneBook(void)
		{
			idx = 0;
		}

		Contact	&operator[](int idx)
		{
			return contact[idx];
		}

		void	Add(PhoneBook &);
		void	Search(PhoneBook &);
		void	Exit(void);
		
	private:
		Contact	contact[8];
		int		idx;
};

#endif
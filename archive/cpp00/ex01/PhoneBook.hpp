#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Stream.hpp"
# include "Contact.hpp"

# define LOOP 1

std::ostream	&format(std::ostream &);

class PhoneBook
{
	public:
		PhoneBook(void);

		bool	prompt(void);
		void	add(void);
		void	search(void);
		void	exit(void);
		
	private:
		Contact	contact[8];
		int		idx;

		bool			queryAdd(Contact &, int);
		void			ask(const char *);
		
		bool			querySearch(int *);
		void 			showList(void);
		std::string		truncate(std::string const &);
		void			printContact(Contact &);
};

#endif
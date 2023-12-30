#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		std::string &operator[](int which);

	private:
		std::string	name_f;
		std::string	name_l;
		std::string	nick;
		std::string	phone;
		std::string	secret;
};

#endif
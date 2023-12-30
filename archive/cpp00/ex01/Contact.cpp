#include "Contact.hpp"

std::string &Contact::operator[](int which)
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
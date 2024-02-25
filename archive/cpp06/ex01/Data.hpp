#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data
{
	Data( void );
	Data( const int &, const std::string & );

	int			_integer;
	std::string	_name;
};

std::ostream	&operator<<(std::ostream &os, const Data &target);

#endif
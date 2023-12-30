#ifndef STREAMS_HPP
# define STREAMS_HPP

# include <iostream>
# include <cstdlib>
# include <stdexcept>
# include <limits>

# define FALSE 0
# define TRUE 1

class Stream
{
	public:
		static bool	std_cin(std::string &target);
		static bool	std_cin(int *target);

	private:
		static void	exit_error(std::string const &msg);
		static bool	valid(std::string input);
		static void flush_istream(void);
};

#endif
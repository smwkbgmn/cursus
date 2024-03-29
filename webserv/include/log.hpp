#ifndef LOG_HPP
# define LOG_HPP

# include <ctime>

# include "structure.hpp"

extern File logfile;

std::string	logFname( void );
std::string	strTime( void );

void		printVec( vec_str_t&, const str_t );

#endif
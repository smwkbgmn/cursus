#ifndef LOG_HPP
# define LOG_HPP

# include <ctime>
# include <filesystem>

# include "structure.hpp"

extern const std::time_t	begin;
extern File					logging;

std::string	logFname( void );
std::string	strTime( void );

void		timestamp( void );
void		log( const str_t& );

void		printVec( vec_str_t&, const str_t );

#endif
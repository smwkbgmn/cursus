#ifndef STRUCTURE_HPP
# define STRUCTURE_HPP

/* STREAM */
# include <iostream>
# include <sstream>

/* CONTAINER */
# include <vector>
# include <map>

/* UTILL */
# include <string>

typedef int								socket_t;

typedef unsigned int					uint_t;
typedef unsigned int					bits_t;

typedef std::ostringstream				osstream_t;
typedef std::istringstream				isstream_t;

typedef std::string						str_t;

typedef std::vector<str_t>				vec_str_t;
typedef vec_str_t::iterator				vec_str_iter_t;

typedef std::map<vec_str_t, str_t>		mime_t;
typedef std::map<uint_t, str_t>			status_t;

# include "File.hpp"
# include "filter.hpp"
# include "error.hpp"

#endif

#ifndef STRUCTURE_HPP
# define STRUCTURE_HPP

# include <string>

# define FALSE		0
# define TRUE		1

# define SIZE_BUF	2048

typedef int							socket_t;
typedef int							port_t;
typedef int							pipe_t;
typedef int							stat_t;

typedef unsigned int				uint_t;
typedef unsigned int				bits_t;

typedef std::string					str_t;

/*
	name_t: the name of file, means when use it, should be combined with path
	path_t: absolute/relative path
	type_t: the type of mime
*/

typedef str_t						name_t;
typedef str_t						path_t;
typedef str_t						type_t;

/* POSIX */
# include <sys/stat.h>

typedef struct stat					fstat_t;

/* I/O */
# include <iostream>
# include <sstream>

typedef std::stringstream			sstream_t;
typedef std::ostringstream 			osstream_t;
typedef std::istringstream 			isstream_t;

/* Container */
# include <map>
# include <vector>

typedef std::vector<uint_t>			vec_uint_t;
typedef std::vector<str_t>			vec_str_t;
typedef vec_str_t::iterator			vec_str_iter_t;
typedef vec_str_t					vec_name_t;
typedef std::vector<char*>			vec_cstr_t;

typedef std::map<uint_t, str_t>		map_uint_str_t;
typedef std::map<str_t, type_t>		map_str_type_t;
typedef std::map<str_t, path_t>		map_str_path_t;

/* STRUCT */
typedef struct c_buffer_s {
	c_buffer_s( void );
	
	char		ptr[SIZE_BUF];

	size_t		total;
	ssize_t		read;
}	c_buffer_t;

typedef struct process_s {
	process_s( void );

	void		reset( void );

	pid_t		pid;
	stat_t		stat;
	pipe_t		fd[2];

	vec_str_t	argv;
	vec_str_t	env;

}	process_t;


# include "File.hpp"

# include "error.hpp"
# include "filter.hpp"

#endif

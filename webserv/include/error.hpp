#ifndef ERROR_HPP
# define ERROR_HPP

# include <exception>
# include <sys/errno.h>

# include "structure.hpp"

# define ERROR -1

extern int errno;

typedef std::runtime_error	err_t;

enum errID {
	INVALID_REQUEST_LINE,
	INVALID_REQUEST_FIELD,
	FAIL_SEND
};

const str_t	errMsg[] = {
	"invalid request line",
	"invalid request field",
	"fail to send"
};

#endif
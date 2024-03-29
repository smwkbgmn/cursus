#ifndef ERROR_HPP
# define ERROR_HPP

# include <exception>

# include "structure.hpp"

# define ERROR -1

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
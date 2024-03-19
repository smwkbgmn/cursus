#ifndef ERR_HPP
# define ERR_HPP

# include <string>

const std::string	errPrfx		= "Error: ";
const std::string	errMsg[]	= {
	errPrfx + "fail to read data",
	errPrfx + "fail to read input",
	errPrfx + "data has not found",
	errPrfx + "fail to get a value",
	errPrfx + "the value is out of range",
	errPrfx + "fail to open file "
};

enum errIdx {
	FAIL_RD_DATA,
	FAIL_RD_INPUT,
	NO_DATA,
	FAIL_GET_VAL,
	OUT_OF_RANGE,
	FAIL_OPN_FILE
};

#endif
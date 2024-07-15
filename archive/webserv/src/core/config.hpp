#ifndef CONFIG_HPP
# define CONFIG_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <cctype>

#include "structure.hpp"

#define on true
#define off false

void parseConfig(std::vector<config_t>& serv, const std::string& filename);

#endif
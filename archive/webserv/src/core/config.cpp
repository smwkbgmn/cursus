#include "config.hpp"

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

unsigned int parseSize(const std::string& sizeStr) {
    unsigned long long size = 0;
    int multiplier = 1;
    size_t i = 0;

    for (; i < sizeStr.size() && std::isdigit(sizeStr[i]); ++i);

    std::istringstream iss(sizeStr.substr(0, i));
    iss >> size;

    if (i != sizeStr.size()) {
        std::string suffix = sizeStr.substr(i);
        if (suffix == "K" || suffix == "k") {
            multiplier = 1024;
        } else if (suffix == "M" || suffix == "m") {
            multiplier = 1024 * 1024;
        } else if (suffix == "G" || suffix == "g") {
            multiplier = 1024 * 1024 * 1024;
        }
    }

    unsigned long long result = size * multiplier;
    if (result > static_cast<unsigned long long>(UINT_MAX)) {
        return static_cast<size_t>(UINT_MAX);
    }
    return static_cast<size_t>(result);
}

void handleListen(std::istringstream& iss, config_t& currentConfig) {
    int port;
    if (!(iss >> port) || iss.peek() != EOF) {
        throw std::runtime_error("Error: Invalid listen format");
    }
    currentConfig.listen = port;
}

void handleServerName(std::istringstream& iss, config_t& currentConfig) {
    std::string serverName;
    while (iss >> serverName) {
        currentConfig.names.push_back(serverName);
    }
    if (iss.fail() && !iss.eof()) {
        throw std::runtime_error("Error: Invalid server_name format");
    }
}

void handleClientBodySize(std::istringstream& iss, config_t& currentConfig) {
    std::string clientbody;
    if (!(iss >> clientbody) || iss.peek() != EOF) {
        throw std::runtime_error("Error: Invalid Client_body_size format");
    }
    currentConfig.client_max_body = parseSize(clientbody);
}

void handleFile40x(std::istringstream& iss, config_t& currentConfig) {
    if (!(iss >> currentConfig.file_40x) || iss.peek() != EOF) {
        throw std::runtime_error("Error: Invalid file40x format");
    }
}

void handleFile50x(std::istringstream& iss, config_t& currentConfig) {
    if (!(iss >> currentConfig.file_50x) || iss.peek() != EOF) {
        throw std::runtime_error("Error: Invalid file50x format");
    }
}

void handleRoot(std::istringstream& iss, location_t& currentLocation) {
    std::string rootValue;
    iss >> rootValue;
    iss >> std::ws;

    if (iss.peek() != EOF) {
        throw std::runtime_error("Error in root directive");
    }
    // if (!rootValue.empty() && rootValue[rootValue.size() - 1] == '/') {
    //     throw std::runtime_error("Error: Can't finish with '/'");
    // }
    currentLocation.root = rootValue;
}

void handleAllowedMethod(std::istringstream& iss, location_t& currentLocation) {
    std::string method;
    std::map<std::string, method_e> validMethods;
    validMethods["get"] = GET;
    validMethods["post"] = POST;
    validMethods["delete"] = DELETE;
    validMethods["not_allowed"] = NOT_ALLOWED;
    validMethods["unknown"] = UNKNOWN;

    while (iss >> method) {
        std::string lowerMethod = toLower(method);
        std::map<std::string, method_e>::iterator it = validMethods.find(lowerMethod);
        if (it == validMethods.end()) {
            throw std::runtime_error("Invalid method: " + method + ". Only GET, POST, DELETE are allowed.");
        }
        currentLocation.allow.push_back(static_cast<uint_t>(it->second));
    }
}

void handleAutoindex(std::istringstream& iss, location_t& currentLocation) {
    std::string value;
    iss >> value;
    currentLocation.index_auto = (value == "on");
}

void handleIndex(std::istringstream& iss, location_t& currentLocation) {
    std::string indexFile;
    while (iss >> indexFile) {
        currentLocation.index.push_back(indexFile);
    }
}

void handleRewrite(std::istringstream& iss, location_t& currentLocation) {
    if (!(iss >> currentLocation.rewrite) || iss.peek() != EOF) {
        throw std::runtime_error("Error: Invalid rewrite format");
    }
}

void handleCGI(std::istringstream& iss, location_t& currentLocation) {
    std::string value;
    iss >> value;
    if (value == "on") {
        currentLocation.cgi = true;
    } else if (value == "off") {
        currentLocation.cgi = false;
    } else {
        throw std::runtime_error("Invalid value for CGI: " + value);
    }
}

// void handleUpload(std::istringstream& iss, location_t& currentLocation) {
//     std::string value;
//     iss >> value;
//     if (value == "on") {
//         currentLocation.upload = true;
//     } else if (value == "off") {
//         currentLocation.upload = false;
//     } else {
//         throw std::runtime_error("Invalid value for Upload: " + value);
//     }
// }

void handleUploadPath(std::istringstream& iss, location_t& currentLocation) {
    if (!(iss >> currentLocation.upload) || iss.peek() != EOF) {
        throw std::runtime_error("Error: Invalid upload format");
    }
}

bool validateLocationPath(const std::string& path) {
    if (path.empty()) return false;
    if (path[0] == '/' || path[0] == '.') return true;
    return false;
}

std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.size() && (str[start] == ' ' || str[start] == '\t')) {
        ++start;
    }
    size_t end = str.size();
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t')) {
        --end;
    }
    return str.substr(start, end - start);
}

void parseConfig(std::vector<config_t>& serv, const std::string& filename) {
    std::ifstream configFile(filename.c_str());
    if (!configFile.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    config_t currentConfig;
    location_t currentLocation(currentConfig);
    bool inLocation = false;
    std::string line;

    while (std::getline(configFile, line)) {
        line = trim(line);

        if (line.substr(0, 6) == "server" && line.find("{") != std::string::npos) {
            std::string rest = line.substr(6);
            rest = trim(rest);
            if (rest != "{") {
                throw std::runtime_error("Server config block not opened correctly: " + line);
            }
            currentConfig = config_t();
            continue;
        }

        if (line.substr(0, 8) == "location") {
            size_t pos = line.find("{");
            if (pos == std::string::npos) {
                throw std::runtime_error("Location block not opened correctly: " + line);
            }

            std::string locationPath = trim(line.substr(8, pos - 8));
            std::string rest = trim(line.substr(pos));
            if (!validateLocationPath(locationPath) || rest != "{") {
                throw std::runtime_error("Location block not opened correctly: " + line);
            }
            inLocation = true;
            currentLocation = location_t(currentConfig);
            currentLocation.path = locationPath;
            continue;
        }

        std::istringstream iss(line);
        std::string key;
        iss >> key;

        if (key.empty()) {
            continue;
        }

        if (key == "}") {
            if (inLocation) {
                inLocation = false;
                currentConfig.locations.push_back(currentLocation);
            } else {
                serv.push_back(currentConfig);
            }
        } else if (inLocation) {
            if (key == "root") {
                handleRoot(iss, currentLocation);
            } else if (key == "allowed_method") {
                handleAllowedMethod(iss, currentLocation);
            } else if (key == "index_auto") {
                handleAutoindex(iss, currentLocation);
            } else if (key == "index") {
                handleIndex(iss, currentLocation);
            } else if (key == "rewrite") {
                handleRewrite(iss, currentLocation);
            } else if (key == "cgi") {
                handleCGI(iss, currentLocation);
            // } else if (key == "upload") {
            //     handleUpload(iss, currentLocation);
            } else if (key == "upload") {
                handleUploadPath(iss, currentLocation);
            } else {
                throw std::runtime_error("Unknown directive in location block: " + key);
            }
        } else {
            if (key == "listen") {
                handleListen(iss, currentConfig);
            } else if (key == "server_name") {
                handleServerName(iss, currentConfig);
            } else if (key == "client_max_body") {
                handleClientBodySize(iss, currentConfig);
            } else if (key == "file40x") {
                handleFile40x(iss, currentConfig);
            } else if (key == "file50x") {
                handleFile50x(iss, currentConfig);
            } else {
                throw std::runtime_error("Unknown directive in server block: " + key);
            }
        }
    }
	
	vec_config_t::iterator it = serv.begin();
    vec_config_t::iterator ite = serv.end();
    for(; it !=ite; it++)
    {
        if(it->locations.empty())
            it->locations.push_back( location_t(*it) );
    }
}
#ifndef TCP_HPP
#define TCP_HPP

#include "error.hpp"
#include "log.hpp"
#include "structure.hpp"
#include <cstring>
#include <exception>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <stdio.h>
#include <string>
#include <sys/event.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define LOOP 1

typedef struct sockaddr_in sockaddr_t;
typedef int socket_t;
typedef std::vector<int> socket_list_t;

class ASocket {
public:
    sockaddr_t addr;
    socket_t server_socket;
    socket_list_t server_list;

    ASocket();
    virtual ~ASocket();

    void setAddr();
    void setNonBlocking(int);
    void socketOpen();
    void preSet();
    void openSocket();
};

#endif

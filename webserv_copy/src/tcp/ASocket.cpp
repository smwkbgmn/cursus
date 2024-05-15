#include "ASocket.hpp"

ASocket::ASocket() : server_socket(-1) {}

ASocket::~ASocket() {
    for (size_t i = 0; i < server_list.size(); ++i)
        close(server_list[i]);
}

void ASocket::socketOpen() {
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket == -1)
        throw err_t("Failed to create socket");
    server_list.push_back(server_socket);
}

void ASocket::setAddr() {
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);
}

void ASocket::preSet() {
    if (bind(server_socket, reinterpret_cast<const struct sockaddr*>(&addr), sizeof(addr)) == ERROR)
        throw err_t("Failed to bind");
    if (listen(server_socket, 10) == ERROR)
        throw err_t("Failed to listen");
}

void ASocket::setNonBlocking(int fd) {
    if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1) {
        close(fd);
        throw err_t("Failed to set non-blocking mode");
    }
}

void ASocket::openSocket() {
    socketOpen();
    setAddr();

    ////////// FOR TEST //////////
    int optval = 1;
    setsockopt(this->server_socket, SOL_SOCKET, SO_REUSEADDR, &optval,
               sizeof(optval));

    preSet();
    setNonBlocking(server_socket);
    log("TCP\t: Listening on port 8080\n");
}

#include "Server.hpp"
#include "HTTP.hpp"

Server::Server() : ASocket(), EventList(8), client_event("client"), server_event("serv") {
    kq = kqueue();
    if (kq == -1)
        throw err_t("Failed to create kqueue");
    timeout.tv_sec = 5;
    timeout.tv_nsec = 0;

    // conf.push_back( config_t() );
}

Server::~Server() {
    for (ConnectClients::iterator it = ClientMap.begin(); it != ClientMap.end(); ++it) {
        delete it->second;
        it->second = NULL;
    }
    for (size_t i = 0; i < EventList.size(); ++i) {
        close(EventList[i].ident);
    }
    close(kq);
}

struct kevent &Server::getEventList(int idx) {
    return EventList[idx];
}

int Server::eventOccure() {
    int occure;
    occure = kevent(this->kq, NULL, 0, &EventList[0], 8, &timeout);
    if (occure == -1)
        throw err_t("Failed to make event");
    return occure;
}


bool Server::errorcheck(struct kevent & kevent) {
    bool isEof = (kevent.flags & EV_EOF) && (kevent.filter != EVFILT_PROC);
    bool hasError = (kevent.flags & EV_ERROR);
    if (isEof || hasError) {
        close(kevent.ident);  
        return true; 
    }
    return false;  
}

void Server::ServerPreset() {
    openSocket();
    add_events(server_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, &server_event);
}

void Server::add_events(uintptr_t ident, int16_t filter, uint16_t flags,
                           uint32_t fflags, intptr_t data, void *udata) {
    struct kevent temp_event;
    EV_SET(&temp_event, ident, filter, flags, fflags, data, udata);
    kevent(kq, &temp_event, 1, NULL, 0, NULL);
}




bool Server::handleReadEvent(struct kevent &occur_event) {
    char *check_type = static_cast<char*>(occur_event.udata);              
    if (std::strcmp(check_type, "serv") == 0) {
        int client_fd = accept(server_socket, NULL, NULL);
        if (client_fd == -1) {
            return false;
        }
        Client* newClient = new Client(*this);
        newClient->setSocket(client_fd);
        this->setNonBlocking(newClient->getSocket());
        ClientMap[client_fd] = newClient;
        add_events(client_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, &client_event);
    } 
    else if(std::strcmp(check_type, "client") == 0) {
      ConnectClients::iterator it = ClientMap.find(occur_event.ident);
        if (it != ClientMap.end()) {
            Client* client = it->second;
            client->processClientRequest(*client);
        }
    }
    return true;
}



void Server::connectsever() {
    // struct kevent* curr_event;
    ServerPreset();
    while (true) {
        int newEvent = eventOccure();
        for (int i = 0; i < newEvent; ++i) {
            struct kevent &event = getEventList(i);
            if (!errorcheck(event)) {
                if (event.filter == EVFILT_READ) {
                    if (!handleReadEvent(event)) continue;
                } else if (event.filter == EVFILT_WRITE) {
                    ConnectClients::iterator it = ClientMap.find(event.ident);
                    if (it != ClientMap.end()) {
                        Client* client = it->second;
                        if (!client->sendData()) {
                            throw err_t("fail to send");
                        }
                    }
                }
            }
        }
    }
}

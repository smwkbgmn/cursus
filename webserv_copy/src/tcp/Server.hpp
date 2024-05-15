#ifndef SERVER_HPP
#define SERVER_HPP

#include "ASocket.hpp"
#include "Client.hpp"
#include "structure.hpp"

#define MAX_EVENTS 10
class Client;

typedef std::map<int, Client*> ConnectClients;
typedef int kque;
typedef std::vector<struct kevent> eventQueue;

class Server : public ASocket {
private:
    kque kq;
    eventQueue EventList;
    // struct kevent *occur_event;
    struct timespec timeout;
    ConnectClients ClientMap;
    char client_event[8];
    char server_event[8];

    // vec_config_t conf;
	config_t	conf;

public:
    Server();
    ~Server();
    void add_events(uintptr_t, int16_t, uint16_t, uint32_t, intptr_t, void *);
    void connectsever();
    void ServerPreset();
    int eventOccure();
    bool errorcheck(struct kevent &);
    bool handleReadEvent(struct kevent &);
    struct kevent &getEventList(int);

    // const vec_config_t& config( void ) const { return conf; }
	const config_t&	config( void ) const { return conf; }
};

#endif

#include "Server.hpp"
#include "HTTP.hpp"

Server::Server( const vec_config_t& configs ) : ASocket(), EventList(8), client_event("client"), server_event("serv"), confs( configs ) {
    this->kq = kqueue();

    timeout.tv_sec = 120;
    timeout.tv_nsec = 0;
}

Server::~Server() {
    for (ConnectClients::iterator it = ClientMap.begin(); it != ClientMap.end(); ++it) {
        delete it->second;
        it->second = NULL;
    }
    for (size_t i = 0; i < EventList.size(); ++i) {
        close(EventList[i].ident);
    }
}

void Server::DisconnectClient(int client_fd) {
    std::map<int, Client*>::iterator it = ClientMap.find(client_fd);
    if (it != ClientMap.end()) {
        close(client_fd);
        delete it->second;
        ClientMap.erase(it);
    } else {
        std::cout << "Client not found in map: " << client_fd << std::endl;
    }
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


bool Server::errorcheck(struct kevent &kevent) {
    if (kevent.flags & EV_ERROR) {
        DisconnectClient(kevent.ident);
        return true;
    }
    if ((kevent.flags & EV_EOF) && (kevent.filter != EVFILT_PROC)) {
        std::map<int, Client*>::iterator it = ClientMap.find(kevent.ident);
        if (it != ClientMap.end()) {
        if (!it->second->getCgiCheck())
            DisconnectClient(kevent.ident);
            return true;
        }
    }
    return false;
}


void Server::ServerPreset(int port) {
    int server_socket = -1;
    openSocket(port, server_socket);
    add_events(server_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, &server_event);
   
}

void Server::add_events(uintptr_t ident, int16_t filter, uint16_t flags,
                           uint32_t fflags, intptr_t data, void *udata) {
    struct kevent temp_event;
    EV_SET(&temp_event, ident, filter, flags, fflags, data, udata);
    kevent(kq, &temp_event, 1, NULL, 0, NULL);
        
}


void Server::handleNewConnection(int server_socket) {
    int client_fd = accept(server_socket, NULL, NULL);
    if (client_fd == -1) {
        std::cout << "check accept status" << std::endl;
        return;
    }
    Client* newClient = new Client(*this);
    newClient->setSocket(client_fd);
    this->setNonBlocking(newClient->getSocket());
    ClientMap[client_fd] = newClient;
    add_events(client_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, &client_event);
    add_events(client_fd, EVFILT_TIMER,EV_ADD |EV_ONESHOT, 0, 30000,NULL);
}

void Server::handleClientEvent(struct kevent &occur_event) {
    ConnectClients::iterator it = ClientMap.find(occur_event.ident);
    if (it != ClientMap.end()) {
            it->second->processClientRequest();
       
    } 

}




void Server::handleReadEvent(struct kevent &occur_event) {
    char *check_type = static_cast<char*>(occur_event.udata);
    if (std::strcmp(check_type, "serv") == 0) 
        handleNewConnection(occur_event.ident);
    else if (std::strcmp(check_type, "client") == 0) 
        handleClientEvent(occur_event);
}


void Server::handleWriteEvent(struct kevent& event) {

    ConnectClients::iterator it = ClientMap.find(event.ident);
    if (it != ClientMap.end()) {
        if (!it->second->sendData()) {
            DisconnectClient(it->second->getSocket());
            return;
        }

          if (it->second->get_process().pid)
        {
            kill(it->second->get_process().pid,SIGTERM);
            it->second->setCgiCheck(FALSE);
            return;
        }
        if (it->second->action != NULL && it->second->action->connection() == 1) {
            DisconnectClient(it->second->getSocket());
            return;
        }
    	} 
		add_events(event.ident, EVFILT_TIMER, EV_DELETE, 0, 0, NULL);
}



void Server::handleProcessExitEvent(struct kevent& event) {
   int client = *(static_cast<int*>(event.udata));
    ConnectClients::iterator it = ClientMap.find(client);
	Client& cl = *it->second;

    try {

        process_t& procs = it->second->get_process();
        CGI::wait(procs);
        it->second->setCgiExit(TRUE);

        if (WEXITSTATUS(cl.subprocs.stat) != EXIT_SUCCESS) {
            throw errstat_t(500, "the CGI failed to exit as SUCCESS");
        }

		CGI::readFrom( cl.subprocs, cl.out.body );
		CGI::build( cl.out );

		cl.in.reset();
		cl.subprocs.reset();
        cl.setCgiExit(FALSE);

        // std::clog << event.ident<<std::endl;
    	add_events(event.ident, EVFILT_TIMER, EV_DELETE, 0, 0, NULL);
        add_events(event.ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
		add_events(client ,EVFILT_TIMER, EV_DELETE, 0, 0, NULL);
        add_events(client, EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, NULL);
    }
	
	catch (const errstat_t& e) {
        log( "TCP\t: " + str_t( e.what() ) );

		cl.out.reset();
        close(cl.subprocs.fd[R]);
		Transaction::buildError( e.code, cl );
		
		cl.setCgiCheck(TRUE);

    	add_events(it->second->get_process().pid, EVFILT_TIMER, EV_DELETE, 0, 0, NULL);
        add_events(event.ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
        add_events(client, EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, NULL);
    } 
   
}



void Server::handleTimerEvent(struct kevent& event) {
    ConnectClients::iterator it;
    int check_client = 0;
     if (event.udata != NULL) {
        check_client = *(static_cast<int *>(event.udata));
    }
    it = ClientMap.find(event.ident);
    try{
    if (it != ClientMap.end()) {
		// add_events(event.ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
        // add_events(event.ident,EVFILT_TIMER,EV_DELETE,0,0,NULL);
        // throw errstat_t(503,"Time out request");
		DisconnectClient(event.ident);
    }
    else if (event.udata != NULL) 
    {
		add_events(event.ident,EVFILT_READ,EV_DELETE,0,0,NULL);
       	add_events(event.ident,EVFILT_TIMER,EV_DELETE,0,0,NULL);
        throw errstat_t(503,"Time out request IN CGI");
    }
    }
    catch (const errstat_t& e) {
		log( "TCP\t: " + str_t( e.what() ) );
        
        if (it != ClientMap.end()) {    
            Client& cl = *it->second;
             cl.out.reset();
            Transaction::buildError( e.code, cl );
            add_events(event.ident, EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, NULL);
            return ;
        }
        else if (event.udata != NULL) 
        {
			// std::clog <<event.ident;

            it = ClientMap.find(check_client);
            if (it != ClientMap.end() && it->second != NULL) {
                Client& cl = *it->second;
                if (it->second->get_process().pid) {
                    if (it->second->getCgiExit()) {
                         cl.out.reset();
                        Transaction::buildError( e.code, cl );
                        close(event.ident);
                        it->second->setCgiExit(FALSE);
                    }
                    else {
                         cl.out.reset();
                        Transaction::buildError( e.code, cl );
                        kill(event.ident, SIGTERM);
                        it->second->setCgiExit(FALSE);
                    }
                    add_events(check_client, EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, NULL);
                }
            }
    }
    } 
}
void Server::devide(vec_config_t& confs) {
    vec_config_t::iterator it = confs.begin();
    vec_config_t::iterator ite = confs.end();  
    for (; it != ite; ++it) { 
		
        if ( distance( port_tried, it->listen) == NOT_FOUND )
            ServerPreset(it->listen);
        port_tried.push_back( it->listen );
    }
}

// void Server::connectsever( ){
void Server::connectsever(vec_config_t confs) {
    devide(confs);
    // ServerPreset(8080);
    while (true) {
        int newEvent = eventOccure();
        for (int i = 0; i < newEvent; ++i) {
            struct kevent &event = getEventList(i);
                if (errorcheck(event))
                    continue;
					
                if (event.filter == EVFILT_READ)
                    handleReadEvent(event);      

                else if (event.filter == EVFILT_WRITE)
                    handleWriteEvent(event);

                else if (event.filter == EVFILT_PROC)
                    handleProcessExitEvent(event); 
					
                else if (event.filter == EVFILT_TIMER)
                    handleTimerEvent(event);
        }
    }
}
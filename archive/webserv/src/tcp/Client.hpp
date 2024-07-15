#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "utill.hpp"
 
#include "ASocket.hpp"
#include "Server.hpp"

#include <sstream>
#include <map>
#include <string>

#include <cstring>

#define SIZE_BUFF 1024
#define SIZE_CRLF 2
#define SIZE_CHUNK_HEAD 3

#include "Transaction.hpp"

class Server;

class Client {
private:
    Server&		srv;
    int			client_socket;

    bool        Cgi_check;
    bool        Cgi_exit;

public:
	msg_buffer_t	in;
    msg_buffer_t	out;

	Transaction*	action;
    process_t		subprocs;

    Client(Server& server);
    ~Client();

    bool sendData();              
    void processClientRequest();

	const msg_buffer_t&	buffer() const;
    const std::string getBufferContents() const;
  
    const Server& getServer() const;
	const Server& server() const;
    int* get_client_socket_ptr();
    const int& getSocket() const;
    bool getCgiCheck();
    bool getCgiExit();
    msg_buffer_t& get_in();
    process_t& get_process();

    void setSocket(const int& );
    void setServer(const Server& );
    void setCgiCheck(bool ); 
    void setCgiExit(bool ) ;

};

#endif // CLIENT_HPP

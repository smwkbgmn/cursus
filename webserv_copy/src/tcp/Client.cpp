#include "Client.hpp"
#include "HTTP.hpp"

Client::Client(Server &connect_server) : srv(connect_server),client_socket(-1) {}

Client::~Client() {}



const Server& Client::getServer() const {
    return srv;
}

const Server& Client::server() const { return srv; }

const int& Client::getSocket() const {
    return client_socket;
}

const msg_buffer_t& Client::buffer() const {
	return in;
}

void Client::setSocket(const int& socket ){
    client_socket = socket;
}
void Client::setServer(const Server& serv){
    srv = serv;
}


void Client::disconnect_client(int client_fd) {
    std::cout << "Client disconnected: " << client_fd << std::endl;
    close(client_fd);
}



void Client::processClientRequest(Client& client) {
    char buf[SIZE_BUF];

    log( "TCP\t: receiving data" );
    ssize_t byte = recv(client_socket, buf, SIZE_BUF, 0);

    osstream_t stream;
    stream << "TCP\t: receiving done by " << byte;
    log( stream.str() );

    if (byte < 0) {
        disconnect_client(client_socket);
        throw err_t("Server socket error on receive");
    }
    
    else if (byte == 0) {
        std::cout << "Client disconnected on file descriptor " << client_socket << std::endl;
        disconnect_client(client_socket);
    }
    
    else {
        if (isMsgDone( buf, byte ) && isBodyDone( buf, byte ) ) {
			logging.fs << in.msg.str() << std::endl;
			logging.fs << in.body.str() << std::endl;

            HTTP::transaction( *this, client.subprocs, out );

			in.reset();
        	subprocs.reset();

            srv.add_events(client_socket, EVFILT_WRITE, EV_ADD | EV_ONESHOT, 0, 0, NULL);
        }
    }
}

bool Client::sendData() 
{
        std::string data = out.str(); 
        const char* buffer = data.c_str();  
        size_t length = data.size(); 

        log( "TCP\t: sending\n" );
        // std::clog << out.str() << std::endl;
        logging.fs << out.str() << "\n" << std::endl;

        ssize_t bytesSent = send(client_socket, buffer, length, 0);  
        if (bytesSent < 0) {
            return false;
        }

        // out.flush();
        out.str( "" );
        out.clear();  

        return true;
}


bool
Client::isMsgDone( const char* buf, ssize_t& byte_read ) {
	if ( !in.msg_done ) {
		in.msg.write( buf, byte_read );

		size_t pos_header_end = in.msg.str().find( MSG_END, in.msg_read - \
			( in.msg_read * ( in.msg_read < 3 ) + 3 * !( in.msg_read < 3 ) ) );

		if ( !found( pos_header_end ) ) in.msg_read += byte_read;
		else {
			// log( "TCP\t: end of header has found" );
			in.msg_done			= TRUE;
			
			size_t body_begin	= pos_header_end - in.msg_read + 4;
			in.body_read		= byte_read - body_begin;

			if ( in.body_read )
				in.body.write( &buf[body_begin], in.body_read );

			byte_read			= 0;

			size_t pos_header_len = in.msg.str().find( HTTP::key.header_in.at( IN_CONTENT_LEN ) );
			if ( found( pos_header_len ) ) {
				// log( "TCP\t: header content-length has found" );
				isstream_t  iss( in.msg.str().substr( pos_header_len, in.msg.str().find( CRLF, pos_header_len ) ) ); 
				str_t       discard;

				std::getline( iss, discard, ':' );
				iss >> std::ws >> in.body_size;
			}
		}
	}
	return in.msg_done;
}

bool Client::isBodyDone(const char* buf, const size_t& byte_read) {
	in.body.write( buf, byte_read );
	in.body_read += byte_read;

    if ( in.body_read ) {
        osstream_t oss;
        oss << "TCP\t: body read by " << byte_read << " so far: " << in.body_read << " / " << in.body_size << std::endl;
        log( oss.str() );
    }
	
	return in.body_size == in.body_read;
}

/* STRUCT */
msg_buffer_s::msg_buffer_s( void ) { reset(); }

void
msg_buffer_s::reset( void ) {
	msg.str( "" );
	msg.clear();

	msg_done	= FALSE;
	msg_read	= 0;

	body.str( "" );
	body.clear();

	body_size	= 0;
	body_read	= 0;
}

process_s::process_s( void ) { reset();	}

void
process_s::reset( void ) {
	pid			= NONE;
	stat		= NONE;
	fd[R]		= NONE;
	fd[W]		= NONE;

	argv.clear();
	env.clear();
}
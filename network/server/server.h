// server.h

#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <sys/socket.h>

class Server {
public:
    Server(const std::string& address, int port);
    ~Server();

    void listen();
    void stop();

private:
    std::string address;
    int port;
    int serverSocket;
};

#endif // SERVER_H

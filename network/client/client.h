// client.h

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <sys/socket.h>

class Client {
public:
    Client(const std::string& address, int port);
    ~Client();

    void connect();
    void disconnect();

private:
    std::string address;
    int port;
    int clientSocket;
};

#endif // CLIENT_H

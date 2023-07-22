// server.cpp

#include "server.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

// コンストラクタ
Server::Server(const std::string& address, int port) 
    : address(address), port(port), serverSocket(-1) {
}

// デストラクタ
Server::~Server() {
    stop();
}

// サーバを開始し、クライアントからの接続を待つ
void Server::listen() {
    sockaddr_in serverAddr{};
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, address.c_str(), &(serverAddr.sin_addr));

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    ::listen(serverSocket, 1);

    sockaddr_in clientAddr{};
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrSize);

    // 以下、受け取ったデータを処理するコードを書く...
}

// サーバを停止する
void Server::stop() {
    if (serverSocket != -1) {
        close(serverSocket);
    }
}

// client.cpp

#include "client.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// コンストラクタ
Client::Client(const std::string& address, int port) 
    : address(address), port(port), clientSocket(-1) {
}

// デストラクタ
Client::~Client() {
    disconnect();
}

// サーバに接続する
void Client::connect() {
    sockaddr_in serverAddr{};
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, address.c_str(), &(serverAddr.sin_addr));

    ::connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // 以下、サーバにデータを送信するコードを書く...
}

// サーバから切断する
void Client::disconnect() {
    if (clientSocket != -1) {
        close(clientSocket);
    }
}

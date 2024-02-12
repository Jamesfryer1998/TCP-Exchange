#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>

class NetworkServer {
private:
    int serverSocket;
    bool isRunning;

public:
    NetworkServer();

    int startServer();
    void stopServer();

private:
    void handleConnection(int clientSocket);
};

#endif // NETWORK_SERVER_H
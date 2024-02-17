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
    bool setSocketReuseAddr(int socketFd);
    void handleConnection(int clientSocket);
    void mainSwitch(const int recievedInput);
    void returnUserStats();
    void returnExchangeStats();
    void makeOrder();
    void returnWalletStats();
    void returnExchangeStatus();

};

#endif // NETWORK_SERVER_H
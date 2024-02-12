#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>

class NetworkClient {
public:
    NetworkClient();
    ~NetworkClient();

    int startClient(const std::string& serverIP, int port);
    void sendData(const std::string& data);

private:
    int clientSocket;
};

#endif // NETWORK_CLIENT_H
#pragma once 

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

class NetworkClient {
public:
    NetworkClient();
    ~NetworkClient();

    int startClient();
    void stopClient();
    bool isClientConnected();
    void receiveData();
    void sendData(const char* data);

private:
    int clientSocket;
};
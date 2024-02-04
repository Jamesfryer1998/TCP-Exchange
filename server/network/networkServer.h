#pragma once 


class NetworkServer {
public:
    NetworkServer();
    ~NetworkServer();

    int startServer();
    void stopServer();
    bool isServerRunning();
    void receiveData();
    void sendData(const char* data);

private:
    int serverSocket;
};
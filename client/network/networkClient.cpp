#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include "networkClient.h"

NetworkClient::NetworkClient() : clientSocket(-1) 
{

}

NetworkClient::~NetworkClient()
{
    // stopClient();
}

int NetworkClient::startClient() {
    // Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    // Connect to the server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");  // IP address of the server
    serverAddress.sin_port = htons(12345);

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error connecting to server" << std::endl;
        close(clientSocket);
        return -1;
    }

    return 0;
}

void NetworkClient::stopClient() 
{
    if (clientSocket != -1) {
        close(clientSocket);
        clientSocket = -1;
        std::cout << "Client stopped." << std::endl;
    }
}

bool NetworkClient::isClientConnected() 
{
    return clientSocket != -1;
}

void NetworkClient::receiveData() 
{
    if (clientSocket == -1) {
        std::cerr << "Error: Client not connected." << std::endl;
        return;
    }

    // Receive data from the server
    char buffer[1024];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        std::cerr << "Error receiving data" << std::endl;
    } else if (bytesRead == 0) {
        // Connection closed by the server
        std::cout << "Server closed the connection." << std::endl;
        stopClient();
    } else {
        // Process received data
        std::cout << "Received data from server: " << buffer << std::endl;
    }
}

void NetworkClient::sendData(const char* data) {
    if (clientSocket == -1) {
        std::cerr << "Error: Client not connected." << std::endl;
        return;
    }

    // Send data to the server
    ssize_t bytesSent = send(clientSocket, data, strlen(data), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending data" << std::endl;
    }

    if(bytesSent >= 0){
        std::cout << "Message sent: " << data << std::endl;
    }
}
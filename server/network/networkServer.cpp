#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include "networkServer.h"

NetworkServer::NetworkServer() 
{

}

NetworkServer::~NetworkServer() 
{
    // stopServer();
}

int NetworkServer::startServer() 
{
    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    // Bind the socket to an address and port
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(12345);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error binding socket" << std::endl;
        close(serverSocket);
        return -1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error listening on socket" << std::endl;
        close(serverSocket);
        return -1;
    }

    std::cout << "Server listening on port 12345..." << std::endl;

    return 0;
}

void NetworkServer::stopServer() 
{
    if (serverSocket != -1) {
        close(serverSocket);
        serverSocket = -1;
        std::cout << "Server stopped." << std::endl;
    }
}

bool NetworkServer::isServerRunning() 
{
    return serverSocket != -1;
}

void NetworkServer::receiveData() 
{
    // Accept a connection
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == -1) {
        std::cerr << "Error accepting connection" << std::endl;
        close(serverSocket);
        return;
    }

    // Receive data from the client
    char buffer[1024];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        std::cerr << "Error receiving data" << std::endl;
        close(serverSocket);
        close(clientSocket);
        return;
    }

    std::cout << "Received data from client: " << buffer << std::endl;

    // Send a response to the client
    const char* response = "Hello from the server!";
    ssize_t bytesSent = send(clientSocket, response, strlen(response), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending data" << std::endl;
    }
}

void NetworkServer::sendData(const char* data) 
{
    if (serverSocket == -1) {
        std::cerr << "Error: Server not running." << std::endl;
        return;
    }

    // Accept a connection
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == -1) {
        std::cerr << "Error accepting connection" << std::endl;
        close(serverSocket);
        return;
    }

    // Send data to the client
    ssize_t bytesSent = send(clientSocket, data, strlen(data), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending data" << std::endl;
    }

    // Close client socket
    // close(clientSocket);
}
#include "networkClient.h"

NetworkClient::NetworkClient() : clientSocket(-1) {}

NetworkClient::~NetworkClient() 
{
    // Close the socket when the object is destroyed
    if (clientSocket != -1) {
        close(clientSocket);
    }
}

int NetworkClient::startClient(const std::string& serverIP, int port) {

    // Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    // Connect to the server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(serverIP.c_str());
    serverAddress.sin_port = htons(port);

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Error connecting to server" << std::endl;
        close(clientSocket);
        clientSocket = -1;
        return -1;
    }

    return 0;
}

void NetworkClient::sendData(const std::string& data) 
{
    // Send data to the server
    ssize_t bytesSent = send(clientSocket, data.c_str(), data.size(), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending data" << std::endl;
    }
}

std::string NetworkClient::receiveData(int serverSocket) 
{
    char buffer[1024];
    ssize_t bytesRead = recv(serverSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        std::cerr << "Error receiving data" << std::endl;
        return json::object(); // Return empty JSON object on error
    }
    buffer[bytesRead] = '\0'; // Null-terminate received data
    return json::parse(buffer); // Parse received JSON data
}

void NetworkClient::requestData(const int userInput)
{
    // Send the integer data to the server
    ssize_t bytesSent = send(clientSocket, &userInput, sizeof(userInput), 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending data" << std::endl;
    }

    recieveData(clientSocket);
}
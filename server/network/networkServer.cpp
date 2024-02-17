#include "networkServer.h"

NetworkServer::NetworkServer() : serverSocket(-1), isRunning(false) {}

int NetworkServer::startServer() 
{
    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    // Set socket option SO_REUSEADDR
    if (!setSocketReuseAddr(serverSocket)) {
        std::cerr << "Failed to set SO_REUSEADDR option" << std::endl;
        close(serverSocket);
        return 1;
    }

    int port = 12345;
    // Bind the socket to an address and port
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

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

    std::cout << "Server listening on port " << port << "..." << std::endl;

    isRunning = true;

    // Accept and handle incoming connections and data
    while (isRunning) {
        // Accept a connection
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            std::cerr << "Error accepting connection" << std::endl;
            continue;
        }

        // Handle the connection
        handleConnection(clientSocket);
    }

    // Close the server socket
    close(serverSocket);

    return 0;
}

void NetworkServer::stopServer() 
{
    isRunning = false;
}

bool NetworkServer::setSocketReuseAddr(int socketFd) 
{
    int enable = 1;
    if (setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
        return false;
    }
    return true;
}

void NetworkServer::handleConnection(int clientSocket) 
{
    while (true) {
        // Receive and process data from the client
        int recievedInput;
        ssize_t bytesRead = recv(clientSocket, &recievedInput, sizeof(recievedInput), 0);
        if (bytesRead == -1) {
            std::cerr << "Error receiving data" << std::endl;
            break;
        } else if (bytesRead == 0) {
            std::cout << "Client disconnected" << std::endl;
            break;
        }
        
        mainSwitch(recievedInput);
    }

    // Close the client socket
    close(clientSocket);
}

void NetworkServer::mainSwitch(const int recievedInput)
{
    switch (recievedInput) {
    case 1:
        returnUserStats();
        break;
    case 2:
        returnExchangeStats();
        break;
    case 3:
        makeOrder();
        break;
    case 4:
        returnWalletStats();
        break;
    case 5:
        returnExchangeStatus();
        break;
    case 6:
        delete this;
        break;
    }
};

void NetworkServer::returnUserStats()
{
    std::cout << "Processing User Stats" << std::endl;
}

void NetworkServer::returnExchangeStats()
{
    std::cout << "Processing Exchange Stats" << std::endl;
    // Num orders
    // Num products
    // Total spent, bought, sold etc...
}

void NetworkServer::makeOrder()
{
    std::cout << "Processing making an order" << std::endl;
}

void NetworkServer::returnWalletStats()
{
    std::cout << "Processing Wallet Stats" << std::endl;
}

void NetworkServer::returnExchangeStatus()
{
    std::cout << "Processing Exchange Status" << std::endl;
    // Is exchange live?

}
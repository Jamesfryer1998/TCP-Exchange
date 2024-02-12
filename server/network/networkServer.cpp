#include "networkServer.h"

NetworkServer::NetworkServer() : serverSocket(-1), isRunning(false) {}

int NetworkServer::startServer() {
    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
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

void NetworkServer::stopServer() {
    isRunning = false;
}

void NetworkServer::handleConnection(int clientSocket) {
    while (true) {
        // Receive and process data from the client
        char buffer[1024];
        ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead == -1) {
            std::cerr << "Error receiving data" << std::endl;
            break;
        } else if (bytesRead == 0) {
            std::cout << "Client disconnected" << std::endl;
            break;
        }

        std::cout << "Received data from client: " << buffer << std::endl;
    }

    // Close the client socket
    close(clientSocket);
}
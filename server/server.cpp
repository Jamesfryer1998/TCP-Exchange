#include "interface/interface.h"
#include "networkServer.h"

int main()
{
    NetworkServer server;
    Interface interface;

    server.startServer();
    server.receiveData();

    // interface.Init(orderbook);
    // std::cout << serverConn << std::endl;
}
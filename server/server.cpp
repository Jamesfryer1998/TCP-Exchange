#include "interface/interface.h"
#include "networkServer.h"

int main()
{
    NetworkServer server;
    OrderBook orderbook;
    Interface interface;

    orderbook.loadOrderBook("20200317.csv");

    server.startServer();
<<<<<<< HEAD

    // orderbook.loadOrderBook("20200317.csv");
    // interface.Init(orderbook);
    // std::cout << serverConn << std::endl;
=======
    server.receiveData();
>>>>>>> main
}
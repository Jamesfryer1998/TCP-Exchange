#include "interface/interface.h"
#include "OrderBook.h"

#include "networkServer.h"
#include "networkClient.h"

int main()
{
    Interface interface;
    NetworkClient client;
    OrderBook orderbook;

    client.startClient("127.0.0.1", 12345);
        
    interface.Init(orderbook, &client);

    return 0;

}
#include "interface/interface.h"
#include "OrderBook.h"

#include "networkServer.h"
#include "networkClient.h"

int main()
{
    NetworkClient client;
    Interface interface;

    if (client.startClient("127.0.0.1", 12345) == 0) {
        // Successfully connected to the server
        client.sendData("Hello from the client!");
    }
    return 0;
    // client.sendData("hello");

    // interface.Init(orderbook);
}
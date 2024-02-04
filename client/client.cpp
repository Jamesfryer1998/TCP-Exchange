#include "interface/interface.h"
#include "networkServer.h"
#include "networkClient.h"

int main()
{
    NetworkClient client;
    Interface interface;

    client.startClient();
    client.sendData("hello");

    // interface.Init(orderbook);
}
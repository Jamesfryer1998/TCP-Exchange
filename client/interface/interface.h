#pragma once 

#include "networkClient.h"
#include "OrderBook.h"
#include "Order.h"
#include "../../shared/util/CSVReader.h"
#include "../../server/user_management/UserWallet.h"

#include <iostream>


class Interface{
    public:
        Interface();
        ~Interface();
        void Init(OrderBook orderBook,
                  NetworkClient *client);

        void printMenu();
        void printStats(std::string type);
        void printUserStats();
        void printExchangeStats();
        void invalidChoice();
        void processUserInput(int userInput);
        void exchangeStatus();
        void walletState();
        void processOrder();

    
    private:
        int getUserInput();
        void makeOrder();
        void displayOrderOptions();
        void getUserOrderType();
        void getToSymbol();
        void getFromSymbol();
        void getProductAmount();
        void getProductPrice();
        void handleInvalidOrderType();
        void handleInvalidProduct();
        void getOrderDetails();

        NetworkClient client;
        OrderBook orderBook;
        Wallet wallet;

        std::string to;
        std::string from;
        std::string product;
        std::string orderTypeInput;
        Type orderType = Type::Unknown;
        std::string prodAmount;
        std::string prodPrice;

};
#include "OrderBook.h"
#include "util/CSVReader.h"

int OrderBook::currentOrderId = 0;
std::unordered_map<int, Order> OrderBook::orders;
std::vector<PriceLevel> OrderBook::bidLevels;
std::vector<PriceLevel> OrderBook::askLevels;

OrderBook::OrderBook(){

};

void OrderBook::loadOrderBook(std::string fileName){
    orders = CSVReader::readCSV(fileName);
    updateProductList();
}

void OrderBook::insertOrder(const Order& order, double price, Type type){
    orders[order.orderId] = order;
    PriceLevel newPriceLevel = { price, { &orders[order.orderId] } };

    if (type == Type::Bid){
        bidLevels.push_back(newPriceLevel); // If type is Bid, add to bidLevel
    } else if (type == Type::Ask)
    {
        askLevels.push_back(newPriceLevel); // If type is Ask, add to askLevel
    }
};

void OrderBook::updateOrder(int orderId, double newProductAmount){
    auto it = orders.find(orderId);
    if (it != orders.end()) {
        Order& order = it->second;

        // Update the order's product amount
        order.amount = newProductAmount;

        // Update the order in the price level
        std::vector<PriceLevel>& priceLevels = order.type == Type::Bid ? bidLevels : askLevels;

        for (PriceLevel& priceLevel : priceLevels) {
            for (Order* priceLevelOrder : priceLevel.orders) {
                if (priceLevelOrder == &order) {
                    // Update the order's amount within the price level
                    priceLevelOrder->amount = newProductAmount;
                    return;
                }
            }
        }
    }
};

void OrderBook::deleteOrder(int orderId) {
    auto it = orders.find(orderId);
    if (it != orders.end()) {
        Order& order = it->second;

        // Delete the order from the order book
        orders.erase(it);

        // Delete the order from the price level
        std::vector<PriceLevel>& priceLevels = order.type == Type::Bid ? bidLevels : askLevels;

        for (PriceLevel& priceLevel : priceLevels) {
            auto orderIt = std::find(priceLevel.orders.begin(), priceLevel.orders.end(), &order);
            if (orderIt != priceLevel.orders.end()) {
                // Remove the order pointer from the price level
                priceLevel.orders.erase(orderIt);
                return;
            }
        }
    }
};

Order* OrderBook::lookupOrder(int orderId) {
    if (orders.find(orderId) != orders.end()) {
        return &orders[orderId];
    } else {
        return nullptr;
    }
};

void OrderBook::updateProductList(){
    // Function to update the product list
        for (const auto& pair : orders) {
            const Order& order = pair.second;
            // Check if the product is in the product list
            auto it = std::find(productList.begin(), productList.end(), order.product);
            if (it == productList.end()) {
                // Product not found in the list, add it
                productList.push_back(order.product);
            }
        }
};

bool OrderBook::lookupProduct(std::string product){
    auto it = std::find(productList.begin(), productList.end(), product);
    if (it == productList.end()) {
        return false;
    }
    else { return true; }   
};
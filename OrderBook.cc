#include "OrderBook.h"

OrderBook::OrderBook() {};

void OrderBook::displayOrders() const {
    std::cout << std::endl;
    if (asks_.empty() && bids_.empty()) {
        std::cout << "No Orders in OrderBook" << std::endl;
    } else {
        std::cout << std::left << std::setw(15) << "Asks" << std::left << std::setw(15) << "Bids" << std::endl;
    }
    
    auto asksIt = asks_.begin();
    auto bidsIt = bids_.begin();

    while (asksIt != asks_.end() || bidsIt != bids_.end()) {
        std::string askStr, bidStr;
        if (asksIt != asks_.end()) {
            // calculate total quantity by iterating through deque of orders
            // print total quantity @ price
            int totalQuantity = 0;
            for (Order order : asksIt->second) {
                totalQuantity += order.getOrderQuantity();
            }
            std::ostringstream ss;
            ss << totalQuantity << " @ $" << std::fixed << std::setprecision(2) << asksIt->first / 100.0;
            askStr = ss.str();
            asksIt++;
        }

        if (bidsIt != bids_.end()) {
            int totalQuantity = 0;
            for (Order order : bidsIt->second) {
                totalQuantity += order.getOrderQuantity();
            }
            std::ostringstream ss;
            ss << totalQuantity << " @ $" << std::fixed << std::setprecision(2) << bidsIt->first / 100.0;
            bidStr = ss.str();
            bidsIt++;
        }

        std::cout << std::left << std::setw(15) << askStr << std::left << std::setw(15) << bidStr << std::endl;
    }
    std::cout << std::endl;
}

void OrderBook::placeOrder(Order order) {
    if (order.getOrderSide() == Order::OrderSide::BUY) {
        bids_[order.getOrderPriceCents()].push_back(order);
    } else {
        asks_[order.getOrderPriceCents()].push_back(order);
    }
}
#include "OrderBook.h"

OrderBook::OrderBook() {};

std::vector<Order> OrderBook::getOrders() const {
    return orders_;
}

void OrderBook::displayOrders() const {
    std::cout << "Order Book:" << std::endl;
    if (orders_.size() == 0) {
        std::cout << "No Orders in OrderBook" << std::endl;
    }
    for (Order order : orders_) {
        order.display();
    }
}

void OrderBook::placeOrder(Order order) {
    orders_.push_back(order);
}
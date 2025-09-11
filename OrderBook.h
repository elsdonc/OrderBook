#ifndef Order_Book_H
#define Order_Book_H

#include "Order.h"
#include <vector>

class OrderBook {
public:
    OrderBook();
    std::vector<Order> getOrders() const;
    void displayOrders() const;
    void placeOrder(Order order);
private:
    std::vector<Order> orders_;
};

#endif // Order_Book_H
#ifndef Order_Book_H
#define Order_Book_H

#include "Order.h"
#include <map>
#include <deque>
#include <sstream>

class OrderBook {
public:
    OrderBook();
    void displayOrders() const;
    void placeOrder(Order order);
private:
    std::map<int, std::deque<Order>> asks_;
    std::map<int, std::deque<Order>> bids_;
};

#endif // Order_Book_H
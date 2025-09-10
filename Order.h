#ifndef Order_H
#define Order_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <cmath>
#include <iomanip>

class Order {
public:
    enum class OrderType : int {
        LIMIT
    };

    enum class OrderSide : int {
        BUY,
        SELL
    };

    Order(OrderType type, OrderSide side, double price, int quantity);

    std::string getOrderType() const;
    std::string getOrderSide() const;
    double getOrderPriceDollars() const;
    int getOrderPriceCents() const;
    int getOrderQuantity() const;
    std::time_t getOrderTime() const;
    std::string getFormattedTime() const;
    void display() const;
private:
    const OrderType type_;
    const OrderSide side_;
    const int price_in_cents_;
    const int quantity_;
    const std::time_t time_;
};

#endif // Order_H
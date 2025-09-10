#include "Order.h"

Order::Order(Order::OrderType type, Order::OrderSide side, double price_in_dollars, int quantity)
    : type_(type), side_(side), price_in_cents_(static_cast<int>(std::ceil(price_in_dollars * 100.0))), 
    quantity_(quantity), time_(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())) {
        std::cout << "Order Placed!" << std::endl;
    }

std::string Order::getOrderType() const {
    switch (type_) {
        case OrderType::LIMIT: return "LIMIT";
        default: return "Unknown Order Type";
    }
}

std::string Order::getOrderSide() const {
    switch (side_) {
        case OrderSide::BUY: return "BUY";
        case OrderSide::SELL: return "SELL";
        default: return "Unknown Order Side";
    }
}

int Order::getOrderQuantity() const {
    return quantity_;
}

double Order::getOrderPriceDollars() const {
    return static_cast<double>(price_in_cents_) / (100.0);
}

int Order::getOrderPriceCents() const {
    return price_in_cents_;
}

std::time_t Order::getOrderTime() const {
    return time_;
}

std::string Order::getFormattedTime() const {
    std::tm* datetime = gmtime(&time_);
    return std::to_string(datetime->tm_hour) + ":" + std::to_string(datetime->tm_min) + ":" + std::to_string(datetime->tm_sec);
}

void Order::display() const {
    std::cout << getOrderSide() << " " << getOrderType() << " " << "$" << std::fixed << std::setprecision(2) << getOrderPriceDollars() << " " << std::to_string(quantity_) << " " << getFormattedTime() << std::endl;
}
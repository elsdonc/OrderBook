#include <iostream>
#include "Order.h"
#include "OrderBook.h"
#include <vector>
#include <map>
#include <limits>

int main() {
    OrderBook orderBook;

    std::unordered_map<std::string, Order::OrderType> order_type_map;
    std::unordered_map<std::string, Order::OrderSide> order_side_map;

    order_type_map["l"] = Order::OrderType::LIMIT;

    order_side_map["b"] = Order::OrderSide::BUY;
    order_side_map["s"] = Order::OrderSide::SELL;

    std::string command;
    std::string input_type;
    std::string input_side;
    double input_price;
    int input_quantity;
    while (command != "q") {
        std::cout << "(d) to display all orders" << std::endl;
        std::cout << "(p) to place an order" << std::endl;
        std::cout << "(q) to quit" << std::endl;
        std::cout << "Your input: ";

        std::cin >> command;
        if (command == "p") {
            do {
                std::cout << std::endl;
                std::cout << "Choose order type" << std::endl << "(l) limit order: ";
                std::cin >> input_type;
            } while (input_type != "l");

            do {
                std::cout << std::endl;
                std::cout << "Choose order side" << std::endl << "(b) buy, (s) sell: ";
                std::cin >> input_side;
            } while (input_side != "b" && input_side != "s");

            do {
                std::cout << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter price: ";
                std::cin >> input_price;
            } while (std::cin.fail());

            do {
                std::cout << std::endl;
                std::cout << "Enter quantity (positive integer only): ";
                if (std::cin >> input_quantity && std::cin.peek() == '\n' && input_quantity > 0) {
                    break;
                }
                std::cout << "Invalid input. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while (true);

            Order::OrderType type = order_type_map.at(input_type);
            Order::OrderSide side = order_side_map.at(input_side);
            
            orderBook.placeOrder(Order(type, side, input_price, input_quantity));
        } else if (command == "d") {
            std::cout << std::endl;
            orderBook.displayOrders();
            std::cout << std::endl;
        }
    }

    return 0;
}
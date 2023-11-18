// main.cpp

#include <iostream>
#include "calculator.hpp"

int main() {
    // Lambda expression for addition
    auto addCallback = [](int a, int b) {
        return add(a, b);
    };

    // Lambda expression for multiplication
    auto multiplyCallback = [](int a, int b) {
        return multiply(a, b);
    };

    // Use the lambda expressions as callbacks
    int result = addCallback(2, 3);
    std::cout << "Result of addition: " << result << std::endl;

    result = multiplyCallback(2, 3);
    std::cout << "Result of multiplication: " << result << std::endl;

    return 0;
}

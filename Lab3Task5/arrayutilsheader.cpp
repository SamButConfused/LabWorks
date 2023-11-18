#include <iostream>
#include "ArrayUtils.h"

int main() {
    // Example with integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(int);

    swapElements(intArray, 1, 3);
    std::cout << "After swapping elements 1 and 3: ";
    for (size_t i = 0; i < intArraySize; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    size_t foundIndex = findElement(intArray, intArraySize, 4);
    std::cout << "Index of value 4: " << foundIndex << std::endl;

    swapAdjacentElements(intArray, intArraySize);
    std::cout << "After swapping adjacent elements: ";
    for (size_t i = 0; i < intArraySize; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Example with doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(double);

    swapElements(doubleArray, 0, 4);
    std::cout << "After swapping elements 0 and 4: ";
    for (size_t i = 0; i < doubleArraySize; ++i) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    foundIndex = findElement(doubleArray, doubleArraySize, 3.3);
    std::cout << "Index of value 3.3: " << foundIndex << std::endl;

    swapAdjacentElements(doubleArray, doubleArraySize);
    std::cout << "After swapping adjacent elements: ";
    for (size_t i = 0; i < doubleArraySize; ++i) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    // Example with characters
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArraySize = sizeof(charArray) / sizeof(char);

    swapElements(charArray, 2, 4);
    std::cout << "After swapping elements 2 and 4: ";
    for (size_t i = 0; i < charArraySize; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    foundIndex = findElement(charArray, charArraySize, 'c');
    std::cout << "Index of value 'c': " << foundIndex << std::endl;

    swapAdjacentElements(charArray, charArraySize);
    std::cout << "After swapping adjacent elements: ";
    for (size_t i = 0; i < charArraySize; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

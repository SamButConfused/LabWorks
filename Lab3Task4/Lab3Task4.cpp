#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

class SimpleFraction {
private:
    int numerator;
    int denominator;

public:
    SimpleFraction(int num, int den) : numerator(num), denominator(den) {}

    bool operator<(const SimpleFraction& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    bool operator>(const SimpleFraction& other) const {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    friend std::ostream& operator<<(std::ostream& os, const SimpleFraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

template <typename T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, T>::type
findMinimum(const std::vector<T>& arr) {
    if (arr.empty()) {
        throw std::runtime_error("Cannot find minimum of an empty array.");
    }

    T minVal = arr[0];
    for (const T& item : arr) {
        if (item < minVal) {
            minVal = item;
        }
    }

    return minVal;
}

template <typename T>
typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type
findMinimum(const std::vector<T>& arr) {
    if (arr.empty()) {
        throw std::runtime_error("Cannot find minimum of an empty array.");
    }

    T minVal = std::numeric_limits<T>::max();
    for (const T& item : arr) {
        if (item < minVal) {
            minVal = item;
        }
    }

    return minVal;
}

int main() {
    try {
        std::vector<int> integers = {5, 9, 1, 13, 3};
        int minInt = findMinimum(integers);
        std::cout << "Minimum integer: " << minInt << std::endl;

        std::vector<double> realNumbers = {8.11, 1.93, 2.21, 1.99, 5.1};
        double minReal = findMinimum(realNumbers);
        std::cout << "Minimum real number: " << minReal << std::endl;

        std::vector<SimpleFraction> fractions = {SimpleFraction(1, 2), SimpleFraction(3, 4), SimpleFraction(1, 3)};
        SimpleFraction minFraction = findMinimum(fractions);
        std::cout << "Minimum fraction: " << minFraction << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}

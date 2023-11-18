#include <iostream>

class SumCalculator {
private:
    int value;
    static int sum;

public:
    SumCalculator(int val) {
        value = val;
        sum += value;
    }

    int getValue() const {
        return value;
    }

    static int getSum() {
        return sum;
    }
};

int SumCalculator::sum = 0;

int main() {
    // Creating objects and calculating the sum
    SumCalculator obj1(25);
    SumCalculator obj2(38);
    SumCalculator obj3(40);

    // Accessing individual values
    std::cout << "Object 1 value: " << obj1.getValue() << std::endl;
    std::cout << "Object 2 value: " << obj2.getValue() << std::endl;
    std::cout << "Object 3 value: " << obj3.getValue() << std::endl;

    // Accessing the calculated sum
    std::cout << "Sum of all values: " << SumCalculator::getSum() << std::endl;

    return 0;
}

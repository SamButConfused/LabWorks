#include <iostream>
#include <vector>

class TwoDimensionalArray {
public:
    TwoDimensionalArray(int rows, int columns) : data(rows, std::vector<int>(columns)) {}

    int& operator()(int row, int column) {
        return data[row][column];
    }

private:
    std::vector<std::vector<int>> data;
};

int main() {
    TwoDimensionalArray arr(3, 4);

    // Assign values to the array
    arr(0, 0) = 1;
    arr(1, 2) = 2;
    arr(2, 3) = 3;

    // Read values from the array
    int value1 = arr(0, 0); // 1
    int value2 = arr(1, 2); // 2
    int value3 = arr(2, 3); // 3

    std::cout << "Value at (0, 0): " << value1 << std::endl;
    std::cout << "Value at (1, 2): " << value2 << std::endl;
    std::cout << "Value at (2, 3): " << value3 << std::endl;

    return 0;
}

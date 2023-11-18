#include <iostream>

// Function object for the first function
struct FunctionObject {
    double operator()(double x) const {
        return x * x;
    }
};

// Template function for applying parentheses operation and calculating derivatives
template<typename T>
double calculate(T func, double x) {
    // Apply parentheses operation
    double result = func(x);

    // Calculate first derivative
    double h = 1e-6; // Step size for derivative calculation
    double derivative = (func(x + h) - func(x - h)) / (2 * h);

    // Calculate second derivative
    double secondDerivative = (func(x + h) - 2 * func(x) + func(x - h)) / (h * h);

    std::cout << "Function value: " << result << std::endl;
    std::cout << "First derivative: " << derivative << std::endl;
    std::cout << "Second derivative: " << secondDerivative << std::endl;

    return result;
}

// Regular function for the second function
double secondFunction(double x) {
    return 2 * x + 3;
}

int main() {
    // Create a function object and pass it to the template function
    FunctionObject funcObj;
    calculate(funcObj, 2.0);

    // Pass the regular function to the template function
    calculate(secondFunction, 2.0);

    return 0;
}

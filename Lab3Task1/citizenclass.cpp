#include <iostream>
#include <string>

class Human {
public:
    virtual void displayData() const {
        std::cout << "Human" << std::endl;
    }
};

class Citizen : public Human {
public:
    virtual void displayData() const override {
        std::cout << "Citizen" << std::endl;
    }
};

class Student : public Citizen {
public:
    virtual void displayData() const override {
        std::cout << "Student" << std::endl;
    }
};

class Employee : public Citizen {
public:
    virtual void displayData() const override {
        std::cout << "Employee" << std::endl;
    }
};

int main() {
    const int size = 4;
    Human* objects[size] = { new Human(), new Citizen(), new Student(), new Employee() };

    for (int i = 0; i < size; i++) {
        objects[i]->displayData();
    }

    for (int i = 0; i < size; i++) {
        delete objects[i];
    }

    return 0;
}

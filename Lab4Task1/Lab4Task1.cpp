#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional> // for std::greater

// Student class
class Student {
public:
    std::string lastName;
    std::vector<int> grades;

    // Constructor
    Student(const std::string& lastName, const std::vector<int>& grades)
        : lastName(lastName), grades(grades) {}

    // Calculate average score
    double calculateAverageScore() const {
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / grades.size();
    }
};

// GroupOfStudents class
class GroupOfStudents {
public:
    std::vector<Student> students;

    // Add student to the group
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Sort students based on individual task criteria
    void sortStudents() {
        std::sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
            // Sorting based on average score in descending order
            return s1.calculateAverageScore() > s2.calculateAverageScore();
        });
    }

    // Perform an action for each student
    void forEachStudent(std::function<void(const Student&)> action) {
        std::for_each(students.begin(), students.end(), action);
    }
};

int main() {
    // Creating a group of students
    GroupOfStudents group;

    // Adding students to the group
    group.addStudent(Student("Smith", { 85, 81, 70 }));
    group.addStudent(Student("Johnson", { 99, 92, 88 }));
    group.addStudent(Student("Williams", { 69, 82, 87 }));

    // Sorting students based on average score
    group.sortStudents();

    // Printing sorted students
    std::cout << "Students sorted by average score:\n";
    group.forEachStudent([](const Student& student) {
        std::cout << "Last Name: " << student.lastName << ", Average Score: " << student.calculateAverageScore() << "\n";
    });

    // Using priority queue to store students in descending order of average score
    std::priority_queue<Student, std::vector<Student>, std::function<bool(const Student&, const Student&)>> priorityQueue(
        [](const Student& s1, const Student& s2) {
            return s1.calculateAverageScore() < s2.calculateAverageScore();
        }
    );

    // Adding students to the priority queue
    priorityQueue.push(Student("Smith", { 85, 81, 70 }));
    priorityQueue.push(Student("Johnson", { 99, 92, 88 }));
    priorityQueue.push(Student("Williams", { 69, 82, 87 }));

    // Printing students from the priority queue in descending order of average score
    std::cout << "\nStudents in priority queue (descending order of average score):\n";
    while (!priorityQueue.empty()) {
        const Student& student = priorityQueue.top();
        std::cout << "Last Name: " << student.lastName << ", Average Score: " << student.calculateAverageScore() << "\n";
        priorityQueue.pop();
    }

    return 0;
}

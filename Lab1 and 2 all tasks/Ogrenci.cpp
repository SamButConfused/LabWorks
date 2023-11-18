#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    unsigned int id;
    char surname[30];
    int marks[5]; // assuming 5 subjects
};

void printStudentData(const Student& student) {
    cout << "Student ID: " << student.id << endl;
    cout << "Surname: " << student.surname << endl;
    cout << "Marks: ";
    for (int i = 0; i < 5; i++) {
        cout << student.marks[i] << " ";
    }
    cout << endl << endl;
}

void sortStudentsById(Student* students[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (students[j]->id > students[j + 1]->id) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void sortStudentsBySurname(Student* students[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (strcmp(students[j]->surname, students[j + 1]->surname) > 0) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void searchStudentsByMark(Student* students[], int length, int mark) {
    bool found = false;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 5; j++) {
            if (students[i]->marks[j] == mark) {
                printStudentData(*students[i]);
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "No students found with mark " << mark << endl << endl;
    }
}

void displayStudents(Student* students[], int length) {
    for (int i = 0; i < length; i++) {
        printStudentData(*students[i]);
    }
}

int main() {
    Student students[MAX_STUDENTS] = {
        { 123, "Volodimir Zelenski", { 90, 99, 94, 92, 95 } },
        { 234, "Recep Tayyip Erdogan", { 85, 80, 70, 75, 80 } },
        { 345, "Joe Biden", { 75, 70, 85, 90, 80 } },
        { 456, "Emmanuel Macron", { 80, 75, 90, 85, 95 } },
        { 567, "Frank-Walter Steinmeier", { 70, 85, 80, 75, 65 } }
    };
    int numStudents = 5;

    Student* studentPtrs[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        studentPtrs[i] = &students[i];
    }

    // sort students by ID and display
    sortStudentsById(studentPtrs, numStudents);
    displayStudents(studentPtrs, numStudents);

    // sort students by surname and display
    sortStudentsBySurname(studentPtrs, numStudents);
    displayStudents(studentPtrs, numStudents);

    // search for students with mark 80 and display
    searchStudentsByMark(studentPtrs, numStudents, 80);

    return 0;
}



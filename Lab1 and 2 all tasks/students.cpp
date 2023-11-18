#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

const int MAX_STUDENTS = 50;

class Group; // forward declaration

class Student
{
private:
    unsigned int id_;
    char *last_name_;
    int *grades_;
    Group *group_;

public:
    Student() : id_(0), last_name_(nullptr), grades_(nullptr), group_(nullptr) {}
    Student(unsigned int id, const char *last_name, int *grades, Group *group)
        : id_(id), last_name_(nullptr), grades_(nullptr), group_(group)
    {
        set_last_name(last_name);
        set_grades(grades);
    }
    Student(const Student &other) : Student(other.id_, other.last_name_, other.grades_, other.group_) {}
    ~Student()
    {
        delete[] last_name_;
        delete[] grades_;
    }
    void set_id(unsigned int id) { id_ = id; }
    unsigned int get_id() const { return id_; }
    void set_last_name(const char *last_name)
    {
        if (last_name_)
            delete[] last_name_;
        last_name_ = new char[strlen(last_name) + 1];
        strcpy(last_name_, last_name);
    }
    const char *get_last_name() const { return last_name_; }
    void set_grades(int *grades)
    {
        if (grades_)
            delete[] grades_;
        grades_ = new int[5];
        memcpy(grades_, grades, 5 * sizeof(int));
    }
    const int *get_grades() const { return grades_; }
    void set_group(Group *group) { group_ = group; }
    Group *get_group() const { return group_; }
    Student &operator=(const Student &other)
    {
        if (this != &other)
        {
            set_id(other.id_);
            set_last_name(other.last_name_);
            set_grades(other.grades_);
            set_group(other.group_);
        }
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const Student &student)
    {
        if (&student != nullptr) // TODO check if redundant
        {

            os << student.id_ << ' ' << student.last_name_ << ':';
            for (int i = 0; i < 3; i++)
            {
                os << ' ' << student.grades_[i];
            }
            return os;
        }
        else
        {
            return os;
        }
    }
    bool operator<(const Student &other) const
    {
        return strcmp(last_name_, other.last_name_) < 0;
    }
};

class Group
{
private:
    int index_;
    Student *students_[MAX_STUDENTS];
    int num_students_;

public:
    Group() : index_(0), students_{}, num_students_(0) {}
    Group(int index) : index_(index), students_{}, num_students_(0) {}
    void set_index(int index) { index_ = index; }
    int get_index() const { return index_; }
    Student *get_student(int index) { return students_[index]; }
    Group &operator=(const Group &other)
    {
        if (this != &other)
        {
            set_index(other.index_);
            num_students_ = other.num_students_;
            for (int i = 0; i < num_students_; i++)
            {
                students_[i] = new Student(*other.students_[i]);
            }
        }
        return *this;
    }
    void add_student(Student *student)
    {
        if (num_students_ < MAX_STUDENTS)
        {
            students_[num_students_++] = student;
            student->set_group(this);
        }
    }
    void sort_students_by_last_name()
    {
        std::sort(students_, students_ + num_students_,
                  [](Student *s1, Student *s2)
                  { return *s1 < *s2; });
    }

    Student *find_student_by_id(unsigned int id)
    {
        for (int i = 0; i < num_students_; i++)
        {
            if (students_[i]->get_id() == id)
            {
                return students_[i];
            }
        }
        return nullptr;
    }
    Student *find_student_by_last_name(const char *last_name)
    {
        for (int i = 0; i < num_students_; i++)
        {
            int temp = std::strcmp(students_[i]->get_last_name(), last_name);
            if (temp == 0)
            {
                return students_[i];
            }
        }
        return nullptr;
    }
    friend std::ostream &operator<<(std::ostream &os, const Group &group)
    {
        os << "Group " << group.index_ << ":\n";
        for (int i = 0; i < group.num_students_; i++)
        {
            os << "  " << *group.students_[i] << '\n';
        }
        return os;
    }
};

int main()
{
    int temp[5] = {80, 70, 90, 85, 75};
    Group group(1);
    Student s1(1, "Smith", temp, &group);
    Student s2(2, "Johnson", new int[5]{75, 85, 70, 80, 90}, &group);
    Student s3(3, "Williams", new int[5]{90, 80, 85, 75, 70}, &group);
    Student s4(4, "Jones", new int[5]{70, 75, 80, 90, 85}, &group);

    group.add_student(&s1);
    group.add_student(&s2);
    group.add_student(&s3);
    group.add_student(&s4);

    std::cout << "Before sorting by last name:\n"
              << group << '\n';
    group.sort_students_by_last_name();
    std::cout << "After sorting by last name:\n"
              << group << '\n';
    std::cout << "Find student by ID 2: " << *group.find_student_by_id(2) << '\n';

    std::cout << "Find student by last name Williams:" << *group.find_student_by_last_name("Williams") << '\n';

    return 0;
}
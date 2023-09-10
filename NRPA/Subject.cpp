#include "Subject.h"

//Constructors and Destructor
Subject::Subject() {}

Subject::Subject(int i, std::string n, std::string t) {
    id = i;
    name = n;
    teacher = t;
}

Subject::~Subject() {}

//Setters
void Subject::setId(int i) { id = i; }
void Subject::setName(std::string n) { name = n; }
void Subject::setTeacher(std::string t) { teacher = t; }

//Getters
int Subject::getId() { return id; }
std::string Subject::getName() { return name; }
std::string Subject::getTeacher() { return teacher; }

std::vector<Student> Subject::getStudents() {
    return students;
}

void Subject::printInfo() {
    std::cout << "ID: " << id << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Teacher: " << teacher << "\n";
    std::cout << "Students:\n";
    if(!students.empty()){
        for(auto i : students) {
            std::cout << i.getName() << "\n";
        }
    }else {
        std::cout << "The subject does not possess any students.\n";
    }
    std::cout << "\n";
}

// Class methods
void Subject::addStudent(Student student) {
    int target = student.getId();
    auto it = std::find_if(students.begin(), students.end(), [target](Student s) { return s.getId() == target; });

    if (it == students.end()) {
        std::cout << student.getName() + " added successfully!\n";
        students.push_back(student);
    } else {
        std::cout << student.getName() << " is already in the subject.\n";
    }
}


void Subject::getAllStudents() {
    if(students.empty()) {
        std::cout << "This subject does not have any students.\n";
    }else {
        for(auto i : students) {
            std::cout << "Name: " << i.getName() << i.getId() << "\n";
        }
    }
}

std::vector<Student> Subject::removeStudent(int studentID) {
    auto it = students.begin();
    while(it != students.end()) {
        if(it->getId() == studentID) {
            std::cout << it->getName() << " was removed from " << name << " successfully!\n";
            students.erase(it);
            return students;
        }else {
            it++;
        }
    }
    std::cout << "Student with ID " << studentID << " was not found.\n";
    return students;
}

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
    printText("ID: " + toString(id));
    printText("Name: " + name);
    printText("Teacher: " + teacher);
    printText("Students:");
    if(!students.empty()){
        for(auto i : students) {
            printText("\t" + i.getName());
        }
    }else {
        printText("The subject does not possess any students.");
    }
    std::cout << "\n";
}

// Class methods
bool Subject::addStudent(Student student) {
    int target = student.getId();
    auto it = std::find_if(students.begin(), students.end(), [target](Student s) { return s.getId() == target; });

    if (it == students.end()) {
        printText(student.getName() + " added successfully!");
        students.push_back(student);
        return true;
    } else {
        printText(student.getName() + " is already in the subject.");
        return false;
    }
}


void Subject::getAllStudents() {
    if(students.empty()) {
        printText("This subject does not have any students.");
    }else {
        for(auto i : students) {
            printText("Name: " + i.getName());
        }
    }
}

std::vector<Student> Subject::removeStudent(int studentID) {
    auto it = students.begin();
    while(it != students.end()) {
        if(it->getId() == studentID) {
            printText(it->getName() + " was removed from " + name + " successfully!");
            students.erase(it);
            return students;
        }else {
            it++;
        }
    }
    printText("Student with ID " + toString(studentID) + " was not found");
    return students;
}

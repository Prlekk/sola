#include "Student.h"
#include "Subject.h"
#include "Functions.h"

#include <iostream>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    std::vector<Student> students = generateStudent(5);
    std::vector<Subject> subjects = generateSubject();
    for(int i = 0; i < subjects.size(); i++) {
        for(int j = 0; j < students.size(); j++) {
            subjects[i].addStudent(students[j]);
        }
    }
    subjects[2].printInfo();
    subjects[2].getAllStudents();
    subjects[2].removeStudent(6);
    subjects[2].getAllStudents();
}
#ifndef SUBJECT_H
#define SUBJECT_H

#include "Student.h"

#include <algorithm>

class Subject {
    private:
        int id;
        std::string name;
        std::string teacher;
        std::vector<Student> students;
    public:
        Subject();
        Subject(int i, std::string n, std::string t);
        ~Subject();
        void setId(int i);
        void setName(std::string n);
        void setTeacher(std::string t);
        int getId();
        std::string getName();
        std::string getTeacher();
        std::vector<Student> getStudents();
        void printInfo();
        void addStudent(Student student);
        void getAllStudents();
        std::vector<Student> removeStudent(int studentID);
};

#endif
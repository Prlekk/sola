#ifndef SUBJECT_H
#define SUBJECT_H

#include "Student.h"
#include "Grades.h"

#include <vector>

class Subject {
  private:
    int id;
    std::string name;
    std::string teacher;
    std::vector<Student> students;
  public:
    Subject();
    Subject(int i, std::string n, std::string t);
    void setId(int i);
    void setName(std::string n);
    void setTeacher(std::string t);
    
    int getId();
    std::string getName();
    std::vector<Student> getStudents();
    std::string getTeacher();
    void addStudent(Student student);
    void allStudents();
    void addGradeToStudent(int grade, int studentId);
};


#endif 
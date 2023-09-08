#include "Subject.h"

Subject::Subject()
{
    id = -1;
    name = "undefined";
    teacher = "undefined";
}

Subject::Subject(int i, std::string n, std::string t)
{
    id = i;
    name = n;
    teacher = t;
}

void Subject::setId(int i) { id = i; }
void Subject::setName(std::string n) { name = n; }
void Subject::setTeacher(std::string t) { teacher = t; }

int Subject::getId() { return id; }
std::string Subject::getName() { return name; }
std::string Subject::getTeacher() { return teacher; }
std::vector<Student> Subject::getStudents() { return students; }
void Subject::addStudent(Student student) {
    int targetId = student.getId();
    auto it = std::find_if(students.begin(), students.end(), [targetId](Student s) { return s.getId() == targetId; });
    if (it == students.end()) {
        students.push_back(student);
    } else {
        std::cout << student.getName() << " was not added because he is already assigned to " << name << ".\n";
    }
}


void Subject::allStudents()
{
    std::cout << "All students in class " << name << ":\n";
    for(auto i : students) {
        std::vector<Grades> studentGrades = i.getGradesFromSpecificSubject(id);
        std::cout << "    " << i.getId() << ":  " << i.getName() << std::endl;
        std::cout << "        Student grades: " << std::endl << "\t";
        if(studentGrades.empty()) {
            std::cout << i.getName() << " does not have any grades in this class.\n";
        }else {
            for (auto j = studentGrades.begin(); j != studentGrades.end(); j++) {
                std::cout << j->getGrade();
                if (std::next(j) != studentGrades.end()) {
                    std::cout << ", ";
                }
            }
            std::cout << "\n        Average grade: ";
            std::cout << averageGrade(studentGrades);
        }
        std::cout << std::endl << std::endl;
    }
}

void Subject::addGradeToStudent(int grade, int studentId)
{
    auto it = std::find_if(students.begin(), students.end(), [studentId](Student& student) { return student.getId() == studentId; });
    if(it != students.end()) {
        Grades newGrade(1, studentId, id, grade);
        it->addGrade(newGrade);
    }else {
        std::cout << "Error: Student with ID " << studentId << " does not exist. Try again.\n"; 
    }
}



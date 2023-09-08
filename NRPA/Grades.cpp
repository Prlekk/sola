#include "Grades.h"

Grades::Grades()
{
}

Grades::Grades(int i, int student, int subject, int g)
{
    id = i;
    studentId = student;
    subjectId = subject;
    grade = g;
}

void Grades::setId(int i){ id = i; }
void Grades::setStudentId(int i){ studentId = i; }
void Grades::setSubjectId(int i){ subjectId = i; }
void Grades::setGrade(int g){ grade = g; }
int Grades::getId(){ return id; }
int Grades::getStudentId(){ return studentId; }
int Grades::getSubjectId(){ return subjectId; }
int Grades::getGrade(){ return grade; }

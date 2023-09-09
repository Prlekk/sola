#include "Grade.h"

//Constructors and Destructor
Grade::Grade(){}

Grade::Grade(int i, int stid, int suid, int g) {
    gradeID = i;
    studentID = stid;
    subjectID = suid;
    grade = g;
}

Grade::~Grade(){}

//Setters
void Grade::setGradeID(int i){ gradeID = i; }
void Grade::setStudentID(int i){ studentID = i; }
void Grade::setSubjectID(int i){ subjectID = i; }
void Grade::setGrade(int g){ grade = g; }

//Getters
int Grade::getGradeID(){ return gradeID;}
int Grade::getStudentID() { return studentID; }
int Grade::getSubjectID() { return subjectID; }
int Grade::getGrade() { return grade; }

//Class methods

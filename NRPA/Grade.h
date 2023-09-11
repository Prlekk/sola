#ifndef GRADE_H
#define GRADE_H

#include <iostream>
#include <thread>
#include <chrono>

class Grade
{
private:
    int gradeID;
    int studentID;
    int subjectID;
    int grade;
public:
    Grade();
    Grade(int i, int stid, int suid, int g);
    ~Grade();
    void setGradeID(int i);
    void setStudentID(int i);
    void setSubjectID(int i);
    void setGrade(int g);
    int getGradeID();
    int getStudentID();
    int getSubjectID();
    int getGrade();
};

void sleep(int time);
void printText(std::string text);
std::string toString(int num);
int toInt(std::string str);

#endif
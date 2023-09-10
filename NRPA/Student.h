#ifndef STUDENT_H
#define STUDENT_H

#include "Grade.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student
{
private:
    int id;
    std::string mail;
    std::string name;
    std::string birthDate;
    std::string emso;
    std::string city;
    std::string country;
    std::string phoneNumber;
    std::vector<Grade> grades;
public:
    Student();
    Student(int i, std::string m, std::string n, std::string b, std::string e, std::string ci, std::string count, std::string p);
    ~Student();
    void setId(int i);
    void setMail(std::string m);
    void setName(std::string n);
    void setBirthDate(std::string b);
    void setEmso(std::string e);
    void setCity(std::string c);
    void setCountry(std::string c);
    void setPhoneNumber(std::string p);
    int getId();
    std::string getMail();
    std::string getName();
    std::string getBirthDate();
    std::string getEmso();
    std::string getCity();
    std::string getCountry();
    std::string getPhoneNumber();
    std::vector<Grade> getGrades();
    void printInfo();
    bool addGrade(Grade grade);
    std::vector<Grade> removeGrade(int gradeID);

};


#endif
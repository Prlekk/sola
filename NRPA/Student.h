#ifndef STUDENT_H
#define STUDENT_H

#include "Functions.h"
#include "Grades.h"

#include <string>
#include <iostream>

class Student {
  private:
    int id;
    std::string mail;
    std::string name;
    std::string gender;
    std::string birthDate;
    std::string streetName;
    std::string houseNumber;
    std::string city;
    std::string country;
    std::string phoneNumber;
    std::vector<Grades> grades;
  public:
    Student();
    Student(int id, std::string mail, std::string name, std::string gender, 
            std::string birthDate, std::string streetName, 
            std::string houseNumber, std::string city,
            std::string country, std::string phoneNumber);

    void setId(int i);
    void setMail(std::string m);
    void setName(std::string n);
    void setGender(std::string g);
    void setBirthDate(std::string b);
    void setStreetName(std::string s);
    void setHouseNumber(std::string h);
    void setCity(std::string c);
    void setCountry(std::string c);
    void setPhoneNumber(std::string p);

    int getId();
    std::string getMail();
    std::string getName();
    std::string getGender();
    std::string getBirthDate();
    std::string getStreetName();
    std::string getHouseNumber();
    std::string getCity();
    std::string getCountry();
    std::string getPhoneNumber();
    std::vector<Grades> getGrades();

    void printInfo();
    void addGrade(Grades grade);

    std::vector<Grades> getGradesFromSpecificSubject(int subjectId);
    
};
std::string generateEmail(std::string name, std::string surname);
std::vector<Student> generateStudent();
double averageGrade(std::vector<Grades> grades);
#endif
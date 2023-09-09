#include "Student.h"

//Constructors and Destructor
Student::Student()
{
}

Student::Student(int i, std::string m, std::string n, std::string b, std::string e, std::string ci, std::string count, std::string p)
{
    id = i;
    mail = m; 
    name = n; 
    birthDate = b;
    emso = e;
    city = ci;
    country = count;
    phoneNumber = p;
}

Student::~Student()
{
}

//Setters
void Student::setId(int i) { id = i; }
void Student::setMail(std::string m) { mail = m; }
void Student::setName(std::string n) { name = n; }
void Student::setBirthDate(std::string b) { birthDate = b; }
void Student::setEmso(std::string e) { emso = e; }
void Student::setCity(std::string c) { city = c; }
void Student::setCountry(std::string c) { country = c; }
void Student::setPhoneNumber(std::string p) { phoneNumber = p;}

//Getters
int Student::getId() { return id; }
std::string Student::getMail() { return mail; }
std::string Student::getName() { return name; }
std::string Student::getBirthDate() { return birthDate; }
std::string Student::getEmso() { return emso; }
std::string Student::getCity() { return city; }
std::string Student::getCountry() { return country; }
std::string Student::getPhoneNumber() { return phoneNumber; }
std::vector<Grade> Student::getGrades() { return grades; }

//Class methods
void Student:: printInfo() {
    std::cout << "ID: " << id << "\n";
    std::cout << "Mail: " << mail << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Birth Date: " << birthDate << "\n";
    std::cout << "EMSO: " << emso << "\n";
    std::cout << "City: " << city << "\n";
    std::cout << "Country: " << country << "\n";
    std::cout << "Phone Number: " << phoneNumber << "\n";
    std::cout << "\n";
}

void Student::addGrade(Grade grade) {
    grades.push_back(grade);
}

std::vector<Grade> Student::removeGrade(int gradeID) {
    auto it = grades.begin();
    while(it != grades.end()) {
        if(it->getGradeID() == gradeID) {
            grades.erase(it);
            std::cout << "Grade removed successfully!\n";
            return grades;
        }else{
            it++;
        }
    }
    std::cout << "Grade ID " << gradeID << " was not found.\n";
    return grades;
}
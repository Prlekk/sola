#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Student.h"
#include "Grade.h"
#include "Subject.h"

#include <fstream>
#include <algorithm>
#include <random>

std::vector<std::string> extractArray(std::string filename);
bool compareStrings(Student a, Student b);

std::string generateEmail(std::string name, std::string surname);
std::string randomDate();
std::string randomEMSO(std::string date);
std::string toString(int num);
std::string toLowerCase(std::string str);
std::string controlNumber(std::string emso);

std::vector<Student> generateStudent(int size);
std::vector<Subject> generateSubject();
#endif
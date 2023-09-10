#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include "Student.h"
#include "Grade.h"
#include "Subject.h"

#include <fstream>
#include <algorithm>
#include <random>
#include <thread>
#include <chrono>

std::vector<std::string> extractArray(std::string filename);
bool compareStrings(Student a, Student b);

std::string generateEmail(std::string name, std::string surname);
std::string randomDate();
std::string randomEMSO(std::string date);
std::string toString(int num);
std::string toLowerCase(std::string str);
std::string controlNumber(std::string emso);
void sleep(int time);
void printText(std::string text);

int userInput(int input);
double userInput(double input);
std::string userInput(std::string input);

std::vector<Student> generateStudent(int size);
std::vector<Subject> generateSubject();
bool findId(int id, std::vector<Subject> subjects);
bool findId(int id, std::vector<Student> students);
bool findId(int id, std::vector<Grade> grades);
int firstAvaliableGradeId(std::vector<Grade> grades);
void printAllSubjects(std::vector<Subject> subjects);
void printAllStudents(std::vector<Student> students);
void printAllGrades(std::vector<Grade> grades);
void printSubjectOptions();
void printAllAvailableStudents(std::vector<Student> students, Subject &selectedSubject);
Student& getStudent(int studentId, std::vector<Student> students);
void printAllStudentsInSubject(std::vector<Student> students);
void printStudentOptions();
int findIndexOfVector(int studentId, std::vector<Student> students);
int findIndexOfVector(int studentId, std::vector<Subject> subjects);
void printOptions(Student student, Subject subject);
#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Subject.h"

#include <fstream>
#include <algorithm>
#include <random>
#include <set>

std::vector<std::string> extractArray(std::string filename);
bool compareStrings(Student a, Student b);

std::string generateEmail(std::string name, std::string surname);
std::string randomDate();
std::string randomEMSO(std::string date);

std::string toLowerCase(std::string str);
std::string controlNumber(std::string emso);

int userInput(int input);

std::vector<Student> generateStudent(int size);
std::vector<Subject> generateSubject();
bool findId(int id, std::vector<Subject> subjects);
bool findId(int id, std::vector<Student> students);
bool findId(int id, std::vector<Grade> grades);
int firstAvaliableGradeId(std::vector<Grade> grades);
void printAllSubjects(std::vector<Subject> subjects);
void printAllStudents(std::vector<Student> students);
void printAllGrades(std::vector<Grade> grades, std::vector<Subject> subjects);
std::string returnSubjectName(std::vector<Subject> subjects, int subjectId);
void printSubjectOptions();
void printAllAvailableStudents(std::vector<Student> students);
Student& getStudent(int studentId, std::vector<Student> students);
void printAllStudentsInSubject(std::vector<Student> students);
void printStudentOptions();
int findIndexOfVector(int studentId, std::vector<Student> students);
int findIndexOfVector(int studentId, std::vector<Subject> subjects);
void printOptions(Student student, Subject subject);
std::vector<int> returnDistinctSubjectId(std::vector<Grade> grades);
void printInfo(Student student, std::vector<Subject> subjects);

#endif
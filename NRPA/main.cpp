#include "Student.h"
#include "Subject.h"
#include "Functions.h"

#include <iostream> 

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int input = 0;

    printText("Welcome to the World Redovalnica Organization a.k.a WRO");
    printText("The program will now ask you to input the number of students you want to create.");
    do{
        input = userInput(input);
        if(input <= 1) {
            printText("Size must be greater than 1.");
        }
    }while(input <= 1 );
    std::vector<Student> students = generateStudent(input);
    std::vector<Subject> subjects = generateSubject();
    std::vector<Grade> allGrades;
    printText("Created a list of students with size of " + toString(input) + ".");
    while(1) {
        input = 0;
        printAllSubjects(subjects);

        //Choose a subject

        do{
            input = userInput(input);
            if(!findId(input, subjects)) {
                printText("ID " + toString(input) + " does not exist in subjects list.");
            }
        }while(!findId(input, subjects));
        Subject &selectedSubject = subjects[input - 1];
        int studentsIndex = -1;
        printText("Selected " + selectedSubject.getName());
        //Choose an action for a subject
        input = 0;
        printSubjectOptions();
        do{
            input = userInput(input);
            if(input < 1 || input > students.size()) {
                printText("Select an option from the displayed options.");
            }
        }while(input < 1 || input > students.size());
        switch (input){
            case 1 : 
                selectedSubject.printInfo();
                break;
            case 2 :
                printAllAvailableStudents(students, selectedSubject);
                do{
                    input = userInput(input);
                    if(input < 1 || input > 4) {
                        printText("Student with ID " + toString(input) + " does not exist in students list.");
                    }
                }while(input < 1 || input > 4);
                selectedSubject.addStudent(getStudent(input, students));
                break;
            case 3 :
                printAllStudentsInSubject(selectedSubject.getStudents());
                if(!selectedSubject.getStudents().empty()) {
                    do{
                        input = userInput(input);
                        if(!findId(input, selectedSubject.getStudents())) {
                            printText("Student with ID " + toString(input) + " does not exist in this subject.");
                        }
                    }while(!findId(input, selectedSubject.getStudents()));
                    printStudentOptions();
                    do{
                        input = userInput(input);
                        if(input < 1 || input > 3) {
                            printText("Select an option from the displayed options.");
                        }
                    }while (input < 1 || input > 3);
                    Grade grade;
                    switch (input){
                    case 1:
                        getStudent(input, students).printInfo();
                        break;
                    case 2:
                        printText("Choose a grade:");
                        printText("1\t2\t3\t4\t5");
                        do{
                            input = userInput(input);
                            if(input < 1 || input > 5) {
                                printText("Select an option from the displayed options.");
                            }
                        }while (input < 1 || input > 5);
                        grade.setGradeID(firstAvaliableGradeId(allGrades));
                        grade.setStudentID(getStudent(input, students).getId());
                        grade.setSubjectID(selectedSubject.getId());
                        grade.setGrade(input);
                        if(getStudent(getStudent(input, students).getId(), students).addGrade(grade)) {
                            printText("Grade added successfully!");
                        }else {
                            printText("Grade was not added because the grade with the same ID already exists.");
                        }
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 4 :
                printAllStudentsInSubject(selectedSubject.getStudents());
                do{
                    input = userInput(input);
                    if(!findId(input, selectedSubject.getStudents())) {
                        printText("Student with ID " + toString(input) + " does not exist in this subject.");
                    }
                }while(!findId(input, selectedSubject.getStudents()));
                selectedSubject.removeStudent(input);
                break;
            default:
                break;
        }
    }

}
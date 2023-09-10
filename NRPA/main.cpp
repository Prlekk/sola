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

    while(1){
        //Choose a student
        printAllStudents(students);
        do{
            input = userInput(input);
            if(!findId(input, students)) {
                printText("Student with ID " + toString(input) + " does not exist.");
            }
        }while(!findId(input, students));
        Student &selectedStudent = students[findIndexOfVector(input, students)];
        printText("Selected " + selectedStudent.getName() + ".");

        //Choose a subject
        printAllSubjects(subjects);
        do{
            input = userInput(input);
            if(!findId(input, subjects)) {
                printText("Subject with ID " + toString(input) + " does not exist.");
            }
        }while(!findId(input, subjects));
        Subject &selectedSubject = subjects[findIndexOfVector(input, subjects)];
        printText("Selected " + selectedSubject.getName() + ".");

        //Displaying options
        printOptions(selectedStudent, selectedSubject);

        do{
            input = userInput(input);
            if(input < 1 || input > 7) {
                printText("Invalid input. Try again.");
            }
        }while(input < 1 || input > 7);

        //Student options
        if(input == 1) {
            selectedStudent.printInfo();
        }
        if(input == 2) {
            printText("Choose a grade:");
            printText("1\t2\t3\t4\t5");
            do{
                input = userInput(input);
                if(input < 1 || input > 5) {
                    printText("Invaild grade. Try again.");
                }
            }while(input < 1 || input > 5);
            Grade grade(firstAvaliableGradeId(allGrades), selectedStudent.getId(), selectedSubject.getId(), input);
            if(selectedStudent.addGrade(grade)) {
                printText("Grade added successfully!");
            }else {
                printText("Error. Grade already exists and was not added.");
            }
        }
        if(input == 3) {
            printText("Choose a grade ID:");
            printAllGrades(selectedStudent.getGrades());
            do{
                input = userInput(input);
                if(!findId(input, selectedStudent.getGrades())) {
                    printText("Grade with ID " + toString(input) + " does not exist");
                }
            }while(!findId(input, selectedStudent.getGrades()));
            selectedStudent.removeGrade(input);
        }

        //Subject options
        if(input == 4) {
            selectedSubject.printInfo();
        }
        if(input == 5) {
            selectedSubject.addStudent(selectedStudent);
        }
        if(input == 6) {
            selectedSubject.getAllStudents();
        }
        if(input == 7) {
            selectedSubject.removeStudent(selectedStudent.getId());
        }
    }
}
#include "Student.h"
#include "Subject.h"
#include "Functions.h"

#include <iostream> 

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int input = -1;
    int exitButton = 0;

    printText("-----------------------------------------");
    printText("Welcome to the World Redovalnica Organization");
    printText("-----------------------------------------");
    printText("The program will now ask you to input the number of students you want to create.");
    do{
        input = userInput(input);
        if(input == exitButton) {
            printText("Exiting program...");
            sleep(500);
            return 0;
        }
        if(input <= 1) {
            printText("Invalid input. Please enter a number between 2 and 100.");
        }
    }while(input <= 1);
    std::vector<Student> students = generateStudent(input);
    std::vector<Subject> subjects = generateSubject();
    std::vector<Grade> allGrades;
    printText("Created a list of students with size of " + toString(input) + ".");
    printText("-----------------------------------------");
    while(1){
        //Choose a student
        printAllStudents(students);
        do{
            input = userInput(input);
            if(input == exitButton) {
                printText("Exiting program...");
                sleep(500);
                return 0;
            }
            if(!findId(input, students)) {
                printText("Student with ID " + toString(input) + " does not exist.");
            }
        }while(!findId(input, students));
        Student &selectedStudent = students[findIndexOfVector(input, students)];
        printText("Selected " + selectedStudent.getName() + ".");
        printText("-----------------------------------------");
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
        printText("-----------------------------------------");
        //Displaying options
        printOptions(selectedStudent, selectedSubject);

        do{
            input = userInput(input);
            if(input == exitButton) {
                printText("Exiting program...");
                sleep(500);
                return 0;
            }
            if(input < 1 || input > 7) {
                printText("Invalid input. Please enter a number between 1 and 7.");
            }
        }while(input < 1 || input > 7);
        printText("-----------------------------------------");
        
        //Student options

        //Print selected student info
        if(input == 1) {
            printInfo(selectedStudent, subjects);
            input = -1;
            printText("-----------------------------------------");
        }
        //Add a grade to the selected student
        if(input == 2) {
            if(!findId(selectedStudent.getId(), selectedSubject.getStudents())) {
                printText("Student is not in the selected subject. Adding the student to the subject...");
                selectedSubject.addStudent(selectedStudent);
            }
            printText("Choose a grade:");
            printText("1\t2\t3\t4\t5\t0-->ExitButton Program");
            do{
                input = userInput(input);
                if(input == exitButton) {
                    printText("Exiting program...");
                    sleep(500);
                    return 0;
                }
                if(input < 1 || input > 5) {
                    printText("Invalid input. Please enter a number between 1 and 5.");
                }
            }while(input < 1 || input > 5);
            Grade grade(firstAvaliableGradeId(allGrades), selectedStudent.getId(), selectedSubject.getId(), input);
            allGrades.push_back(grade);
            if(selectedStudent.addGrade(grade)) {
                printText("Grade added successfully!");
            }else {
                printText("Error. Grade already exists and was not added.");
            }
            input = -1;
            printText("-----------------------------------------");
        }
        //Remove a grade from the selected student
        if(input == 3) {
            printText("Choose a grade ID:");
            printAllGrades(selectedStudent.getGrades(), subjects);
            do{
                input = userInput(input);
                if(input == exitButton) {
                    printText("Exiting program...");
                    sleep(500);
                    return 0;
                }
                if(!findId(input, selectedStudent.getGrades())) {
                    printText("Grade with ID " + toString(input) + " does not exist");
                }
            }while(!findId(input, selectedStudent.getGrades()));
            selectedStudent.removeGrade(input);
            input = -1;
            printText("-----------------------------------------");
        }

        //Subject options

        //Print selected subject info
        if(input == 4) {
            selectedSubject.printInfo();
            printText("-----------------------------------------");
        }
        //Add selected student to the selected subject
        if(input == 5) {
            selectedSubject.addStudent(selectedStudent);
            printText("-----------------------------------------");
        }
        //Print all students in the selected subject
        if(input == 6) {
            selectedSubject.getAllStudents();
            printText("-----------------------------------------");
        }
        //Remove the selected student from the selected subject
        if(input == 7) {
            selectedSubject.removeStudent(selectedStudent.getId());
            printText("-----------------------------------------");
        }
    }
}
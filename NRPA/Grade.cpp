#include "Grade.h"

//Constructors and Destructor
Grade::Grade(){}

Grade::Grade(int i, int stid, int suid, int g) {
    gradeID = i;
    studentID = stid;
    subjectID = suid;
    grade = g;
}

Grade::~Grade(){}

//Setters
void Grade::setGradeID(int i){ gradeID = i; }
void Grade::setStudentID(int i){ studentID = i; }
void Grade::setSubjectID(int i){ subjectID = i; }
void Grade::setGrade(int g){ grade = g; }

//Getters
int Grade::getGradeID(){ return gradeID;}
int Grade::getStudentID() { return studentID; }
int Grade::getSubjectID() { return subjectID; }
int Grade::getGrade() { return grade; }

//Class methods

//Other
void sleep(int time) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void printText(std::string text) {
    for(int i = 0; i < text.length(); i++) {
        std::cout << text[i] << std::flush;
        sleep(20);
    }
    std::cout << std::endl;
}

std::string toString(int num) {
    if (num == 0) {
        return "0";
    }

    std::string temp = "";
    while (num != 0) {
        int digit = num % 10;
        char digitChar = '0' + digit;
        temp = digitChar + temp;
        num /= 10;
    }
    return temp;
}

int toInt(std::string str) {
    try {
        return std::stoi(str);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 0;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 0;
    }
}

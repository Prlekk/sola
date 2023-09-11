#include "Functions.h"

std::vector<std::string> extractArray(std::string filename) {
    std::ifstream file(filename);
    std::vector<std::string> temp;
    std::string data;
    if(!file.is_open()) {
        std::cout << "Error opening file " << filename << "\n";
        return temp;
    }
    while(getline(file, data)) {
        temp.push_back(data);
    }
    file.close();
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(temp.begin(), temp.end(), g);
    return temp;
}

bool compareStrings(Student a, Student b) {
    return a.getName() < b.getName();
}

std::string generateEmail(std::string name, std::string surname) {
    return toLowerCase(surname) + "." + toLowerCase(name) + "@gmail.com";
}

std::string randomDate() {
    int d = rand() % 31 + 1;
    int m = rand() % 12 + 1;
    int y = 2005;
    
    std::string day = toString(d);
    if(day.length() == 1) {
        day = "0" + day;
    }
    std::string month = toString(m);
    if(month.length() == 1) {
        month = "0" + month;
    }
    std::string year = toString(y);

    return day + "." + month + "." + year;
}

std::string randomNumber(int length) {
    std::string temp = "";
    for(int i = 0; i < length; i++) {
        temp += char(rand() % 10 + 48);
    }
    return temp;
}

std::string randomEMSO(std::string date) {
    int firstDot = date.find('.');
    int secondDot = date.find('.', firstDot + 1);

    if (firstDot != std::string::npos && secondDot != std::string::npos) {
        std::string day = date.substr(0, firstDot);
        std::string month = date.substr(firstDot + 1, secondDot - firstDot - 1);
        std::string year = date.substr(secondDot + 2);

        std::string temp = day + month + year + "500" + randomNumber(2);
        return temp + controlNumber(temp);
    } else {
        return "Invalid date format";
    }
}

std::string toLowerCase(std::string str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    return str;
}

std::string controlNumber(std::string emso) {
    int weight[] = {7, 6, 5, 4, 3, 2, 7, 6, 5, 4, 3, 2};
    int sum = 0;

    for(int i = 0; i < emso.length(); i++) {
        sum += weight[i] * (emso[i] - '0');
    }

    int remainder = sum % 11;
    int controlNumber = 11 - remainder;

    if(controlNumber == 10) {
        controlNumber = 0;
    }
    return toString(controlNumber);
}

int userInput(int input) {
    std::cout << "Input: ";
    std::cin >> input;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return -1;
    }
    return input;
}

std::vector<Student> generateStudent(int size) {
    std::vector<std::string> names = extractArray("names.txt");
    std::vector<std::string> surnames = extractArray("surnames.txt");
    std::vector<std::string> city = extractArray("cityNames.txt");
    std::vector<std::string> country = extractArray("countryNames.txt");
    std::vector<std::string> mail;
    std::vector<std::string> birthDate;
    std::vector<std::string> phoneNumber;

    for(int i = 0; i < 100; i++) {
        mail.push_back(generateEmail(names[i], surnames[i]));
        birthDate.push_back(randomDate());
        phoneNumber.push_back(randomNumber(9));
    }

    std::vector<Student> temp;
    if(size > 100) {
        printText("Size too big. Generating 100 students.");
    }
    for(int i = 0; i < size && i < 100; i++) {
        Student s;
        s.setId(i + 1);
        s.setName(names[i] + " " + surnames[i]);
        s.setMail(generateEmail(names[i], surnames[i]));
        s.setBirthDate(randomDate());
        s.setEmso(randomEMSO(s.getBirthDate()));
        s.setCity(city[i]);
        s.setCountry(country[i]);
        s.setPhoneNumber(phoneNumber[i]);
        temp.push_back(s);
    }

    names.clear();
    surnames.clear();
    city.clear();
    country.clear();
    mail.clear();
    birthDate.clear();
    phoneNumber.clear();

    return temp;
}

std::vector<Subject> generateSubject(){
    std::vector<std::string> subjectNames = extractArray("subjects.txt");
    std::vector<std::string> teachers = extractArray("teachers.txt");
    std::vector<Subject> temp;
    for(int i = 0; i < subjectNames.size() && i < teachers.size(); i++) {
        Subject s;
        s.setId(i+1);
        s.setName(subjectNames[i]);
        s.setTeacher(teachers[i]);
        temp.push_back(s);
    }
    subjectNames.clear();
    teachers.clear();
    return temp;
}

bool findId(int id, std::vector<Subject> subjects) {
    for(auto it : subjects) {
        if(it.getId() == id) {
            return true;
        }
    }
    return false;
}

bool findId(int id, std::vector<Student> students) {
    for(auto it : students) {
        if(it.getId() == id) {
            return true;
        }
    }
    return false;
}

bool findId(int id, std::vector<Grade> grades) {
    for(auto it : grades) {
        if(it.getGradeID() == id) {
            return true;
        }
    }
    return false;
}

int firstAvaliableGradeId(std::vector<Grade> grades) {
    if(grades.empty()) return 1;
    return grades.back().getGradeID() + 1;
}

void printAllSubjects(std::vector<Subject> subjects) {
    printText("Choose a subject:");
    for(auto i : subjects) {
        std::string line = toString(i.getId()) + "\t" + i.getName();
        printText(line);
    }
    printText("");
    printText("0\tExit Program");
}

void printAllStudents(std::vector<Student> students) {
    printText("Choose a student:");
    for(auto i : students) {
        std::string line = toString(i.getId()) + "\t" + i.getName();
        printText(line);
    }
    printText("");
    printText("0\tExit Program");
}

void printAllGrades(std::vector<Grade> grades, std::vector<Subject> subjects) {
    printText("Grade ID\tGrade\tSubject");
    for(auto i : grades) {
        std::string line = toString(i.getGradeID()) + "\t\t" + toString(i.getGrade()) + "\t" + returnSubjectName(subjects, i.getSubjectID());
        printText(line);
    }
    printText("");
    printText("0\tExit Program");
}

std::string returnSubjectName(std::vector<Subject> subjects, int subjectId) {
    int index = 0;
    for(int i = 0; i < subjects.size(); i++) {
        if(subjects[i].getId() == subjectId) {
            index = i;
        }
    }
    return subjects[index].getName();
}

void printSubjectOptions() {
    printText("Choose between these options:");
    printText("1\tPrint Info");
    printText("2\tAdd Student");
    printText("3\tGet All Students");
    printText("4\tRemove Student");
}

void printAllAvailableStudents(std::vector<Student> students, Subject &selectedSubject) {
    std::vector<Student> studentsInSubject = selectedSubject.getStudents();
    bool printed = false;
    for (auto i : students) {
        int targetId = i.getId();
        auto it = std::find_if(studentsInSubject.begin(), studentsInSubject.end(), [targetId](Student s) { return s.getId() == targetId; });
        if (it == studentsInSubject.end()) {
            std::string line = toString(targetId) + "\t" + i.getName();
            printText(line);
            printed = true;
        }
    }
    if (!printed) {
        printText("All students are already in this subject.");
    }
}

Student& getStudent(int studentId, std::vector<Student> students) {
    for (Student& student : students) {
        if (student.getId() == studentId) {
            return student;
        }
    }
    // Handle the case where no matching student is found
    // You can throw an exception or return a sentinel value, as needed.
    // For example, throwing an exception:
    throw std::runtime_error("Student with ID " + std::to_string(studentId) + " not found.");
}

void printAllStudentsInSubject(std::vector<Student> students) {
    if(students.empty()) {
        printText("This subject does not possess any students.");
    }else {
        printText("Choose a student:");
        for(auto i : students) {
            std::string line = toString(i.getId()) + "\t" + i.getName();
            printText(line);
        }
    }
}

void printStudentOptions() {
    printText("1\tPrint Info");
    printText("2\tAdd Grade");
    printText("3\tRemove Grade");
}

int findIndexOfVector(int studentId, std::vector<Student> students) {
    for(int i = 0; i < students.size(); i++) {
        if(students[i].getId() == studentId) {
            return i;
        }
    }
    return -1;
}

int findIndexOfVector(int studentId, std::vector<Subject> subjects) {
    for(int i = 0; i < subjects.size(); i++) {
        if(subjects[i].getId() == studentId) {
            return i;
        }
    }
    return -1;
}

void printOptions(Student student, Subject subject) {
    printText("Choose an option:");
    printText(" \t" + student.getName() + "\t\t" + subject.getName() + "\n");
    printText("1\tPrint Info\t4\tPrint Info");
    printText("2\tAdd Grade\t5\tAdd Student");
    printText("3\tRemove Grade\t6\tGet All Students");
    printText("\t\t\t7\tRemove Student");
    printText("");
    printText("0\tExit Program");
}

std::vector<int> returnDistinctSubjectId(std::vector<Grade> grades) {
    std::vector<int> newGrades;
    std::set<int> distinctSubjectIds;
    for (Grade grade : grades) {
        int subjectId = grade.getSubjectID();
        if (distinctSubjectIds.find(subjectId) == distinctSubjectIds.end()) {
            distinctSubjectIds.insert(subjectId);
            newGrades.push_back(grade.getSubjectID());
        }
    }
    return newGrades;
}


void printAllSubjectGrades(std::vector<Grade> grades, std::vector<Subject> subjects, int subjectId) {
    std::string subjectName = returnSubjectName(subjects, subjectId);
    std::string line = subjectName + "\t";
    double sum = 0;
    int gradeSize = 0;
    double average = 0;
    for(int i = 0; i < grades.size(); i++) {
        if(grades[i].getSubjectID() == subjectId) {
            sum = sum + grades[i].getGrade();
            gradeSize = gradeSize + 1;
            line = line + toString(grades[i].getGrade()) + ", ";
        }
    }
    line = line.substr(0, line.length() - 2);
    average = sum / gradeSize;
    printText(line);
    std::cout << "  Avg.: " << average << "\n\n";
}

void printInfo(Student student, std::vector<Subject> subjects) {
    printText("ID: " + toString(student.getId()));
    printText("Mail: " + student.getMail());
    printText("Name: " + student.getName());
    printText("Birth Date: " + student.getBirthDate());
    printText("EMSO: " + student.getEmso());
    printText("City: " + student.getCity());
    printText("Country: " + student.getCountry());
    printText("Phone Number: " + student.getPhoneNumber());
    printText("Grades:");
    if(!student.getGrades().empty()){
        std::vector<int> temp = returnDistinctSubjectId(student.getGrades());
        for(auto i : temp) {
            printAllSubjectGrades(student.getGrades(), subjects, i);
        }
    }else {
        printText(student.getName() + " currently has no grades.");
    }
    std::cout << "\n";
}
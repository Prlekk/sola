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
    if(filename == "names.txt" || filename == "surnames.txt") {
        std::sort(temp.begin(), temp.end());
        return temp;
    }
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

    return day + "-" + month + "-" + year;
}

std::string randomNumber(int length) {
    std::string temp = "";
    for(int i = 0; i < length; i++) {
        temp += char(rand() % 10 + 48);
    }
    return temp;
}

std::string randomEMSO(std::string date) {
    size_t firstHyphen = date.find('-');
    size_t secondHyphen = date.find('-', firstHyphen + 1);

    if (firstHyphen != std::string::npos && secondHyphen != std::string::npos) {
        std::string day = date.substr(0, firstHyphen);
        std::string month = date.substr(firstHyphen + 1, secondHyphen - firstHyphen - 1);
        std::string year = date.substr(secondHyphen + 2);

        return day + month + year;
    } else {
        return "Invalid date format";
    }
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
        std::cout << "Size too big. Generating 100 students.\n";
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
        s.setId(i);
        s.setName(subjectNames[i]);
        s.setTeacher(teachers[i]);
        temp.push_back(s);
    }
    subjectNames.clear();
    teachers.clear();
    return temp;
}

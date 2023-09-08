#include "Student.h"

Student::Student() : id(0), mail("undefined"), name("undefined"), gender("undefined"),
                     birthDate("undefined"), streetName("undefined"), houseNumber("undefined"),
                     city("undefined"), country("undefined"), phoneNumber("undefined")
{
}

Student::Student(int id, std::string m, std::string n, std::string g,
                 std::string b, std::string street,
                 std::string h, std::string c,
                 std::string co, std::string phone)
    : id(id), mail(m), name(n), gender(g), birthDate(b),
     streetName(street), houseNumber(h), city(c), country(co), phoneNumber(phone)
{
}


void Student::setId(int i) { id = i; }
void Student::setMail(std::string m) { mail = m; }
void Student::setName(std::string n) { name = n; }
void Student::setGender(std::string g) { gender = g; }
void Student::setBirthDate(std::string b) { birthDate = b; }
void Student::setStreetName(std::string s) { streetName = s; }
void Student::setHouseNumber(std::string h) { houseNumber = h; }
void Student::setCity(std::string c) { city = c; }
void Student::setCountry(std::string c) { country = c; }
void Student::setPhoneNumber(std::string p) { phoneNumber = p; }

int Student::getId() { return id; }
std::string Student::getMail() { return mail; }
std::string Student::getName() { return name; }
std::string Student::getGender() {return gender; }
std::string Student::getBirthDate() { return birthDate; }
std::string Student::getStreetName() { return streetName; }
std::string Student::getHouseNumber() { return houseNumber; }
std::string Student::getCity() { return city; }
std::string Student::getCountry() { return country; }
std::string Student::getPhoneNumber() { return phoneNumber; }
std::vector<Grades> Student::getGrades() { return grades; }

void Student::printInfo() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Mail: " << mail << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Birth Date: " << birthDate << std::endl;
    std::cout << "Street Name: " << streetName << std::endl;
    std::cout << "House Number: " << houseNumber << std::endl;
    std::cout << "City: " << city << std::endl;
    std::cout << "Country: " << country << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}

void Student::addGrade(Grades grade)
{
    grades.push_back(grade);
}

std::vector<Grades> Student::getGradesFromSpecificSubject(int subjectId)
{
    std::vector<Grades> temp;
    for(auto i : grades) {
        if(i.getSubjectId() == subjectId) {
            temp.push_back(i);
        }
    }
    return temp;
}

std::string generateEmail(std::string name, std::string surname)
{
    return toLowerCase(name) + toLowerCase(surname) + "@gmail.com";
}

std::vector<Student> generateStudent()
{
    std::vector<std::string> emails;
    std::vector<std::string> genders;
    std::vector<std::string> birthDates;
    std::vector<std::string> socialNums;
    std::vector<std::string> davcneNums;
    std::vector<std::string> houseNums;
    std::vector<std::string> postNums;
    std::vector<std::string> phoneNums;
    std::vector<std::string> names = extractArray("names.txt");
    std::vector<std::string> surnames = extractArray("surnames.txt");
    std::vector<std::string> roles = extractArray("roles.txt");
    std::vector<std::string> streetNames = extractArray("streetNames.txt");
    std::vector<std::string> postNames = extractArray("postNames.txt");
    std::vector<std::string> cityNames = extractArray("cityNames.txt");
    std::vector<std::string> countryNames = extractArray("countryNames.txt");

    int minSize = std::min({names.size(), surnames.size(), roles.size(), streetNames.size(),
                        postNames.size(), cityNames.size(), countryNames.size()});

    for(int i = 0; i < minSize; i++) {
        emails.push_back(generateEmail(names[i], surnames[i]));
        if(names[i][names[i].length()-1] == 'a' || names[i][names[i].length()-1] == 'e') {
            genders.push_back("Female");
        }else {
            genders.push_back("Male");
        }
        birthDates.push_back(randomDate());
        socialNums.push_back(randomNumber(13));
        davcneNums.push_back(randomNumber(8));
        houseNums.push_back(randomNumber(3));
        postNums.push_back(randomNumber(4));
        phoneNums.push_back(randomNumber(9));
    }

    minSize = std::min({names.size(), surnames.size(), roles.size(), genders.size(), birthDates.size(), socialNums.size(),
                        davcneNums.size(), streetNames.size(), houseNums.size(), postNums.size(), postNames.size(),
                        cityNames.size(), countryNames.size(), phoneNums.size()});   

    std::vector<Student> students;
    try {
        for(int i = 0; i < minSize; i++) {
            Student temp(i+1, emails[i], surnames[i] + " " + names[i], genders[i], birthDates[i], streetNames[i], houseNums[i], cityNames[i], countryNames[i], phoneNums[i]);
            students.push_back(temp);
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation error: " << e.what() << std::endl;
    }

    return students;
}

double averageGrade(std::vector<Grades> grades)
{
    double average = 0;
    for(auto i : grades) {
        average += i.getGrade();
    }
    return TwoDecimals(average/grades.size());
}

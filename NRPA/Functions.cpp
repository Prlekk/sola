#include "Functions.h"

int countWords(std::string str) {
    std::stringstream ss(str);
    std::string word;
    int count = 0;
    
    while (ss >> word) {
        count++;
    }
    
    return count;
}

std::string toLowerCase(std::string str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    return str;
}

std::string randomDate() {
    int d = rand() % 31 + 1;
    int m = rand() % 12 + 1;
    int y = 2005;

    std::string day = toString(d);
    std::string month = toString(m);
    std::string year = toString(y);

    return day + "-" + month + "-" + year;
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

std::string randomNumber(int length) {
    std::string temp = "";
    for(int i = 0; i < length; i++) {
        temp += char(rand() % 10 + 48);
    }
    return temp;
}

std::vector<std::string> extractArray(std::string filename)
{   
    std::ifstream file(filename);
    std::vector<std::string> temp;
    std::string data;
    if(!file.is_open()) {
        std::cout << "Error opening file " << filename << std::endl;
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

double TwoDecimals(double value)
{
    return round(value * 100.0) / 100.0;
}

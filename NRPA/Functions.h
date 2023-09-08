#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <cmath>

int countWords(std::string str);
std::string toLowerCase(std::string str);
std::string randomDate();
std::string toString(int num);
std::string randomNumber(int length);
std::vector<std::string> extractArray(std::string filename);
double TwoDecimals(double value);

#endif
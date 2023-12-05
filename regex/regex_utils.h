#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include <regex>

// Declare global variable
extern std::regex idRegex;
extern std::regex integerRegex;
extern std::regex floatRegex;
extern std::regex noSpecialCharsRegex;

bool validateID(const std::string &input);
bool validateInt(const std::string &input);
bool validateFloat(const std::string &input);
bool validateStr(const std::string &input);

// Boolean functions
bool boolStr(const std::string &input, bool id = false);

// Functions
std::string validateStrInput(std::string &strValor, bool id = false);
int funcInt(int &intNum);
float funcFloat(float &floatNum);

#endif // REGEX_UTILS_H
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

#endif // REGEX_UTILS_H
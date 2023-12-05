#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include <regex>

// Declare global variable
extern std::regex idRegex;

bool validateID(const std::string &input);

#endif // REGEX_UTILS_H
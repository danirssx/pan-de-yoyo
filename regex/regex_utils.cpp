#include "regex_utils.h"

// Define it
std::regex idRegex("[A-Z][0-9]{4}");
std::regex integerRegex("[-+]?[0-9]+");
std::regex floatRegex("[-+]?[0-9]*\\.?[0-9]+");
std::regex noSpecialCharsRegex("[A-Za-z0-9 ]+");

// Function to validate
bool validateID(const std::string &input)
{
    return std::regex_match(input, idRegex);
};

bool validateInt(const std::string &input)
{
    return std::regex_match(input, integerRegex);
};

bool validateFloat(const std::string &input)
{
    return std::regex_match(input, floatRegex);
};

bool validateStr(const std::string &input)
{
    return std::regex_match(input, noSpecialCharsRegex);
};
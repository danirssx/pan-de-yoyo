#include "regex_utils.h"

// Define it
std::regex idRegex("[A-Z][0-9]{4}");

// Function to validate
bool validateID(const std::string &input)
{
    return std::regex_match(input, idRegex);
}

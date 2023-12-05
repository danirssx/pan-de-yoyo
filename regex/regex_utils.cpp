#include "regex_utils.h"
#include <iostream>
#include <string>

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

// Functions to make the validation
std::string validateStrInput(std::string &strValor, bool id)
{
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);

        if (id ? std::regex_match(input, idRegex) : std::regex_match(input, noSpecialCharsRegex))
        {
            strValor = input;
            break;
        }
        else
        {
            std::cout << "Ingresa bien los datos! \n";
            std::cout << "\nVuelve a intentarlo: ";
        }
    }

    return strValor; // Return the validated string
};

// Functions to make the validation
int funcInt(int &intNum)
{
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);

        if (std::regex_match(input, integerRegex))
        {
            intNum = stoi(input);
            break;
        }
        else
        {
            std::cout << "Ingresa bien el numero! \n";
            std::cout << "\nVuelve a intentarlo: ";
        }
    }

    return intNum; // Return the validated string
};

// Functions to make the validation
float funcFloat(float &floatNum)
{
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);

        if (std::regex_match(input, floatRegex))
        {
            floatNum = stof(input);
            break;
        }
        else
        {
            std::cout << "Ingresa bien el numero! \n";
            std::cout << "\nVuelve a intentarlo: ";
        }
    }

    return floatNum; // Return the validated string
};

#include "regex_utils.h"
#include <iostream>
#include <string>

// Define the regex Regexs

std::regex idRegex("[A-Z][0-9]{4}");
std::regex nombreRegex("[a-zA-Z]{1,25}");
std::regex apellidoRegex("[a-zA-Z]{1,25}");
std::regex cedulaRegex("[0-9]{7,8}");
std::regex direccionRegex(".{1,75}");
std::regex telefonoRegex("[0-9]{11}");

// Function to validate
bool validateID(const std::string &input)
{
    return std::regex_match(input, idRegex);
}

// * (Cliente)
bool validateNombre(const std::string &input)
{
    return std::regex_match(input, nombreRegex);
}

bool validateApellido(const std::string &input)
{
    return std::regex_match(input, apellidoRegex);
}

bool validateCedula(long int input)
{
    // Convertir el valor a string antes de llamar a la función de validación
    return std::regex_match(std::to_string(input), cedulaRegex);
}

bool validateDireccion(const std::string &input)
{
    return std::regex_match(input, direccionRegex);
}
bool validateTelefono(long int input)
{
    // Convertir el valor a string antes de llamar a la función de validación
    return std::regex_match(std::to_string(input), telefonoRegex);
}

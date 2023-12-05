#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include <regex>

// Declare global variable
extern std::regex idRegex;
extern std::regex nombreRegex;
extern std::regex apellidoRegex;
extern std::regex cedulaRegex;
extern std::regex direccionRegex;
extern std::regex telefonoRegex;

bool validateID(const std::string &input);
bool validateNombre(const std::string &input);
bool validateApellido(const std::string &input);
bool validateCedula(const std::string &input);
bool validateDireccion(const std::string &input);
bool validateTelefono(const std::string &input);

#endif // REGEX_UTILS_H
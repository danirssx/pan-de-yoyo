// vendedores.h

#ifndef VENDEDORES_H
#define VENDEDORES_H

#include <iostream>
#include <fstream>
#include <string>

#include "../helpers/helpers.h"

struct typedef NombreYApellido
{
    std::string Nombre;
    std::string Apellido;
}
, NyA;

struct Fecha
{
    int dia;
    int mes;
    int ano;
};

struct Vendedores
{
    long int cedula;
    NyA nombre;
    Fecha fecha;
    short int porcentaje;
};

Vendedores crear_vendedores();

#endif // VENDEDORES_H

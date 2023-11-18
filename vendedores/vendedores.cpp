#include <iostream>
#include <fstream>
#include <string>

// Include library
#include "vendedores.h"

using namespace std;

// Crear articulo con data dada por el usuario
Vendedores crear_vendedores(void)
{

    Vendedores nuevo_vendedores; // Crear un objeto para el nuevo artículo

    // Crear id dinámicamente en base a la categoría del producto
    // Lógica para asignar ID automáticamente ...

    // FALTA VALIDAR DATOS
    cout << "Cedula del vendedores: ";
    cin >> nuevo_vendedores.cedula;

    cout << "Nombre del vendedores: ";
    cin >> nuevo_vendedores.nombre;
    // ! OJO
    cin.ignore(); // Ignore any previous newline character in the buffer
    getline(cin, nuevo_vendedores.nombre);

    cout << "Fecha del vendedores: ";
    cin >> nuevo_vendedores.fecha;

    cout << "Porcentaje del vendedores: ";
    cin >> nuevo_vendedores.porcentaje;

    return nuevo_vendedores;
}
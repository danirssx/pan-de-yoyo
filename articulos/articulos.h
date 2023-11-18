// articulos.h

#ifndef ARTICULOS_H
#define ARTICULOS_H

#include <iostream>
#include <fstream>
#include <string>

#include "../helpers/helpers.h"

struct Articulo
{
    std::string id;
    std::string nombre;
    int cantidad;
    float precio;
};

Articulo crear_articulo();
void agregar_articulo_lista(Node<Articulo> **headRef, Articulo articulo);
void agregar_articulo_archivo(Articulo nuevo_articulo);

#endif // ARTICULOS_H
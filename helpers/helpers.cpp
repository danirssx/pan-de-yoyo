#include <iostream>
#include <string>

// Include library
#include "helpers.h"
#include "../articulos/articulos.h"
#include "../vendedores/vendedores.h"

using namespace std;

template <typename T>
Node<T> *crear_nodo(const T &data)
{

    Node<T> *new_node = new Node<T>;

    if (new_node)
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    else
    {
        cerr << "Error creating new node." << endl;
    }

    return new_node;
}

// Declaracion de los posibles casos
template Node<Articulo> *crear_nodo(const Articulo &data);
template Node<Vendedores> *crear_nodo(const Vendedores &data);
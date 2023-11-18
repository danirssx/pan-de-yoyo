// helpers.h

#ifndef HELPERS_H
#define HELPERS_H

// Node structure global
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

// Funcion template para crear un nodo para un especifico tipo T
template <typename T>
Node<T> *crear_nodo(const T &data);

#endif // HELPERS_H
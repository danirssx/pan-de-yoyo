#include <iostream>
#include <fstream>
#include <string>

// Include library
#include "articulos.h"

using namespace std;

// Crear articulo con data dada por el usuario
Articulo crear_articulo(void)
{

    Articulo nuevo_articulo; // Crear un objeto para el nuevo artículo

    // Crear id dinámicamente en base a la categoría del producto
    // Lógica para asignar ID automáticamente ...

    // FALTA VALIDAR DATOS
    cout << "ID del articulo: ";
    cin >> nuevo_articulo.id;

    cout << "Nombre del articulo: ";
    cin >> nuevo_articulo.nombre;
    // ! OJO
    cin.ignore(); // Ignore any previous newline character in the buffer
    getline(cin, nuevo_articulo.nombre);

    cout << "Precio del articulo: ";
    cin >> nuevo_articulo.precio;

    cout << "Cantidad del articulo: ";
    cin >> nuevo_articulo.cantidad;

    return nuevo_articulo;
}

// Add to list end
void agregar_articulo_lista(Node<Articulo> **headRef, Articulo articulo)
{
    Node<Articulo> *current = *headRef;
    Node<Articulo> *new_node = crear_nodo(articulo);

    // If list is empty
    if (current == NULL)
    {
        *headRef = new_node;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Add new article as the last element
        current->next = new_node;
    }
}

// FALTA CARGAR LA LISTA CON EL ARCHIVO

void agregar_articulo_archivo(Articulo nuevo_articulo)
{
    ofstream file("articulos.txt", ios::app);

    if (file.is_open())
    {
        file << nuevo_articulo.id << endl;
        file << nuevo_articulo.nombre << endl;
        file << nuevo_articulo.precio << endl;
        file << nuevo_articulo.cantidad << endl;

        file.close();
        cout << "Articulo agregado exitosamente.\n";
    }
    else
    {
        cerr << "Error opening the file." << endl;
    }
};
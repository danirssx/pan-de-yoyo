#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class articulo // objeto que va en la posicion de DATA del nodo
{
public:
    string id, nombre;
    float precio;
    long int cantidad;
    // falta por agregar receta;
    // builder
    void llenar(string id, string nombre, float precio, long int cantidad)
    {
        this->id = id;
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    };
};

class nodoa
{
public:
    articulo data;
    nodoa *prox = NULL;
    nodoa(string id, string nombre, float precio, long int cantidad)
    {
        this->data.llenar(id, nombre, precio, cantidad);
    }
};

class Larticulo
{
public:
    nodoa *cabeza = NULL;
    // builder
    agregar(string id, string nombre, float precio, long int cantidad)
    {

        if (this->cabeza == NULL)
            this->cabeza = new nodoa(id, nombre, precio, cantidad);
        else
        {
            nodoa *actual = this->cabeza;
            while (actual->prox != NULL) // hasta ser el ultimo nodo de la lista
            {
                actual = actual->prox;
            }
            actual->prox = new nodoa(id, nombre, precio, cantidad);
        }
    }
};

int main(int argc, char const *argv[])
{
    articulo *harina = new articulo("ujuuuu", "harina", 4.2, 15);
    /* code */
    cout << harina->;

    return 0;
}

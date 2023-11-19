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
    void agregar(string id, string nombre, float precio, long int cantidad)
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
    Larticulo *Productos = new Larticulo;
    Productos->agregar("A0001", "Donas Sabrosssas", 4.2, 66);

    cout << "Datos del primer nodo de lista productos:" << endl;
    cout << "Id: " << Productos->cabeza->data.id << endl;
    cout << "nombre: " << Productos->cabeza->data.nombre << endl;
    cout << "Precio: " << Productos->cabeza->data.precio << endl;
    cout << "Cantidad: " << Productos->cabeza->data.cantidad << endl;

    return 0;
}

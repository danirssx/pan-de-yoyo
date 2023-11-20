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
    // METODO
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
    // builder
    nodoa(string id, string nombre, float precio, long int cantidad)
    {
        this->data.llenar(id, nombre, precio, cantidad);
    }
};

class Larticulo
{
public:
    nodoa *cabeza = NULL;
    // metodo
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
    };
    void imprimir()
    { // no se va a tomar caso lista vacia, se supone que se imprime con algo

        nodoa *actual = this->cabeza;
        cout << "Articulos de la lista : " << endl;
        while (actual != NULL)
        {

            cout << "Id: " << this->cabeza->data.id;
            cout << " nombre: " << this->cabeza->data.nombre;
            cout << " Precio: " << this->cabeza->data.precio;
            cout << " Cantidad: " << this->cabeza->data.cantidad << endl;
            actual = actual->prox;
        }
    };
};

class Fecha
{
    short int dia, mes, ano;
    // builder
    void llenar(short int dia, short int mes, short int ano)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }
};
class NyA // Nombre y Apellido
{
    string nombre, apellido;
    void llenar(string nombre, string apellido)
    {
        this->nombre = nombre;
        this->apellido = apellido;
    };
};

class vendedor // objeto que va en la posicion de DATA del nodo
{

public:
    long int cedula = 0;
    string nombre = "";
    Fecha Fecha_ingreso;
    short int p_comision;
    int score = 0;
    // falta por agregar receta;
    // METODO
    void llenar(long int cedula, string nombre, Fecha fecha, short int p_comision)
    {
        this->cedula = cedula;
        this->nombre = nombre;
        this->Fecha_ingreso = fecha;
        this->p_comision = p_comision;
    };
};

int main(int argc, char const *argv[])
{
    Larticulo *Productos = new Larticulo;
    Productos->agregar("A0001", "Donas Sabrosssas", 4.2, 66);
    Productos->imprimir();

    return 0;
}

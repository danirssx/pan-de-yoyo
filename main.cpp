#include <iostream>
#include <fstream>
#include <string>

// Para manejar el uso de los key arrows
#include <conio.h>

using namespace std;

// Estructurar las clases
//
//
class Articulo // objeto que va en la posicion de DATA del nodo
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
    Articulo articulo;
    nodoa *prox = NULL;
    // builder
    nodoa(string id, string nombre, float precio, long int cantidad)
    {
        this->articulo.llenar(id, nombre, precio, cantidad);
    }
};

class Larticulo
{
public:
    nodoa *cabeza = NULL;
    // Llenado del usuario
    void pedirDatos()
    {
        string id, nombre;
        float precio;
        long int cantidad;

        system("cls");

        cout << "Ingresa el ID: ";
        cin >> id;

        cout << "Ingresa el Nombre: ";
        cin >> nombre;

        cout << "Ingresa el precio: ";
        cin >> precio;

        cout << "Ingresa la cantidad de elementos: ";
        cin >> cantidad;

        // Es momento de agregar los datos del producto:
        agregar(id, nombre, precio, cantidad);
    };

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

        system("cls");

        nodoa *actual = this->cabeza;
        cout << "\nArticulos de la lista : " << endl;
        cout << "\n";

        while (actual != NULL)
        {

            cout << "Id: " << actual->articulo.id;
            cout << " nombre: " << actual->articulo.nombre;
            cout << " Precio: " << actual->articulo.precio;
            cout << " Cantidad: " << actual->articulo.cantidad << endl;
            actual = actual->prox;
        }
    };

    // Desturctor para liberar la memoria
    ~Larticulo()
    {
        nodoa *actual = this->cabeza;
        while (actual != NULL)
        {
            nodoa *temp = actual;
            actual = actual->prox;
            delete temp;
        }
        this->cabeza = NULL; // Establecer cabeza como NULL
    }
};

// Estructura de los vendedores:

struct Fecha
{
    short int dia, mes, ano;
    // builder
};
struct NyA // Nombre y Apellido
{
    string nombre, apellido;
};

class Vendedor // objeto que va en la posicion de DATA del nodo
{

public:
    long int cedula = 0;
    NyA *nombre = NULL;
    Fecha *Fecha_ingreso;
    short int p_comision;
    int score = 0;
    // falta por agregar receta;
    // METODO
    void llenar(long int cedula, NyA *nombre, Fecha *fecha, short int p_comision, int score)
    {
        this->cedula = cedula;
        this->nombre = nombre;
        this->Fecha_ingreso = fecha;
        this->p_comision = p_comision;
        this->score = score;
    };
};

class nodov
{
public:
    Vendedor vendedor;
    nodov *prox = NULL;
    // builder

    nodov(long int cedula, NyA *nombre, Fecha *fecha, short int p_comision, int score)
    {
        this->vendedor.llenar(cedula, nombre, fecha, p_comision, score);
    };
};

class Lvendedor
{

public:
    nodov *cabeza = NULL;
    // metodo
    void agregar(long int cedula, NyA *nombre, Fecha *fecha, short int p_comision, int score)
    {

        if (this->cabeza == NULL)
            this->cabeza = new nodov(cedula, nombre, fecha, p_comision, score);
        else
        {
            nodov *actual = this->cabeza;
            while (actual->prox != NULL) // hasta ser el ultimo nodo de la lista
            {
                actual = actual->prox;
            }
            actual->prox = new nodov(cedula, nombre, fecha, p_comision, score);
        }
    };
    void imprimir()
    { // no se va a tomar caso lista vacia, se supone que se imprime con algo

        nodov *actual = this->cabeza;
        cout << "Articulos de la lista : " << endl;
        while (actual != NULL)
        {

            cout << "Cedula: " << this->cabeza->vendedor.cedula;
            cout << " nombre: " << this->cabeza->vendedor.nombre->nombre << this->cabeza->vendedor.nombre->apellido;
            cout << " Fecha de ingreso:" << this->cabeza->vendedor.Fecha_ingreso->dia << '/';
            cout << this->cabeza->vendedor.Fecha_ingreso->mes << '/' << this->cabeza->vendedor.Fecha_ingreso->mes << endl;
            cout << " Score de ventas: " << this->cabeza->vendedor.score << endl;
            actual = actual->prox;
        }
    };
};

void imprimirMenu()
{
    system("cls"); // Limpia la consola

    cout << "Bienvenido a Pan de Yoyo" << endl;
    cout << "\n";
    cout << "\t1. Agrega un articulo" << endl;
    cout << "\t2. Imprime la lista de articulos" << endl;
    cout << "\t3. Salir" << endl;
    return;
}

int main(int argc, char const *argv[])
{
    // Declaracion
    Larticulo *Productos = new Larticulo;
    Productos->agregar("A0001", "Donas Sabrosssas", 4.2, 66);

    // datos
    int opcion = -1;
    char tecla;

    // Menu
    while (opcion != 3)
    {
        imprimirMenu();
        cout << "\nIngresa la opcion: ";
        cin >> opcion;

        if (opcion >= 0 & opcion <= 3)
        {
            switch (opcion)
            {
            case 1:
                // Agregar un articulo
                cout << "Ingresa la data del articulo: " << endl;
                Productos->pedirDatos();

                Productos->imprimir();

                cout << "\nPresiona cualquier tecla para continuar...";

                tecla = _getch(); // Tiene que presionar una tecla para continuar
                break;

            case 2:
                // Lista
                cout << "Lista de articulos" << endl;
                Productos->imprimir();

                cout << "\nPresiona cualquier tecla para continuar...";

                tecla = _getch(); // Tiene que presionar una tecla para continuar

            default:
                break;
            }
        }
    }

    return 0;
}

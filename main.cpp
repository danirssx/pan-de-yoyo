#include <iostream>
#include <fstream>
#include <string>
#include <map> //NUEVA LIBRERIA
// Para manejar el uso de los key arrows
#include <conio.h>

using namespace std;
// MANEJO DE DIRECCIONES DE LA BASE DE DATOS

map<string, string> directorio;

void cargar_direcciones(string direccion)
{
    fstream archivo;
    string linea;
    string lista[5] = {"clientes", "vendedores", "productos", "materia_prima", "recetas"};
    archivo.open(direccion, std::ios::in);
    if (archivo.is_open())
    {
        int i = 0;
        while (getline(archivo, linea))
        {
            directorio[lista[i]] = linea;
            i++;
        }
        archivo.close();
    }
};
//////////////////////////////////////////////
// Estructurar las clases
////// ARTICULO
/////////////////////////////////////////////
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
        this->refrescar();
    };

    // Editar
    template <typename T>
    void editarDato(T valor, int editar, int seleccion)
    {

        // Me aseguro de que el valor es valido:
        // static_assert(is_same<T, int>::value || is_same<T, string>::value || is_same<T, float>::value, "Tipo de dato no compatible");

        int iterador = 1;
        nodoa *actual = this->cabeza;

        while (actual != NULL)
        {
            if (iterador == seleccion)
            {
                // Casos posibles para editar el valor
                switch (editar)
                {
                case 1:
                    if constexpr (is_same<T, string>::value)
                    {
                        actual->articulo.id = valor;
                    }
                    break;

                case 2:
                    if constexpr (is_same<T, string>::value)
                    {
                        actual->articulo.nombre = valor;
                    }
                    break;

                case 3:
                    if constexpr (is_same<T, float>::value)
                    {
                        actual->articulo.precio = valor;
                    }
                    break;

                case 4:
                    if constexpr (is_same<T, int>::value)
                    {
                        actual->articulo.cantidad = valor;
                    }
                    break;

                default:
                    break;
                }
            }

            actual = actual->prox;
            iterador++;
        }
    }

    void imprimir()
    { // no se va a tomar caso lista vacia, se supone que se imprime con algo
        int iterador = 1;

        system("cls");

        nodoa *actual = this->cabeza;
        cout << "\nArticulos de la lista : " << endl;
        cout << "\n";

        while (actual != NULL)
        {
            cout << iterador << " |- ";

            cout << "Id: " << actual->articulo.id;
            cout << " | nombre: " << actual->articulo.nombre;
            cout << " | Precio: " << actual->articulo.precio;
            cout << " | Cantidad: " << actual->articulo.cantidad << endl;
            actual = actual->prox;

            iterador++;
        }
    };
    /// Constructor, va a leer el ,txt y va a llenar la lista
    string direccion = "";
    Larticulo(string dir)
    {
        direccion = dir;
        fstream archivo;
        string linea;
        string id;
        string nombre;
        float precio;
        long int cantidad;
        archivo.open(direccion, std::ios::in);
        if (archivo.is_open())
        {
            while (getline(archivo, linea)) // primera linea buscada
            {
                id = linea;
                getline(archivo, linea);
                nombre = linea;
                getline(archivo, linea);

                try // control de errores
                {
                    precio = stof(linea); // cast de libreria string
                    getline(archivo, linea);
                    cantidad = stoi(linea);
                }
                catch (const std::invalid_argument &e)
                {
                    precio = ////okosokoodkfokeok
                }

                this->agregar(id, nombre, precio, cantidad);
            }
        };
    };

    void refrescar()
    { // actualiza toda la base de datos.txt(productos.txt)
        nodoa *actual = this->cabeza;
        fstream archivo;
        archivo.open(direccion, std::ios::out | std::ios::trunc);
        if (!archivo.is_open())
            std::cout << "Error al abrir el archivo\n";
        else
        {
            while (actual != NULL)
            {
                archivo << actual->articulo.id << "\n";
                archivo << actual->articulo.nombre << "\n";
                archivo << actual->articulo.precio << "\n";
                archivo << actual->articulo.cantidad << "\n";
                actual = actual->prox;
            }
            archivo.close();
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
// VENDEDORES
//
// ///////////////////////////////////////
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

// Crear el dato tipo template
template <typename T>
T inputValor()
{
    T valor;
    return cin >> valor;
};

void editarFuncion(Larticulo *Productos)
{
    int intValor, editar, seleccion;
    float floatValor;
    string strValor;

    // Menu funcionalidades
    cout << "\nCual articulo desea modificar: ";
    cin >> seleccion;

    cout << "\nQue desea modificar? " << endl;
    cout << "1 |- El ID" << endl;
    cout << "2 |- El Nombre" << endl;
    cout << "3 |- El Precio" << endl;
    cout << "4 |- Su Cantidad" << endl;
    cout << "\n";
    cout << "Presione la opcion correcta: ";
    cin >> editar;

    cout << "\n Ingrese el valor a introducir: ";

    // Introducir el valor
    switch (editar)
    {
    //  El ID
    case 1:
        cin >> strValor;
        Productos->editarDato(strValor, editar, seleccion);
        break;

    case 2:
        cin >> strValor;
        Productos->editarDato(strValor, editar, seleccion);
        break;

    case 3:
        cin >> floatValor;
        Productos->editarDato(floatValor, editar, seleccion);

        break;

    case 4:
        cin >> intValor;
        Productos->editarDato(intValor, editar, seleccion);
        break;

    default:
        break;
    };
}

// MENU
//
////////////////
void imprimirMenu()
{
    system("cls"); // Limpia la consola

    cout << "Bienvenido a Pan de Yoyo" << endl;
    cout << "\n";
    cout << "\t1. Agrega un articulo" << endl;
    cout << "\t2. Imprime la lista de articulos" << endl;
    cout << "\t3. Edita un articulo de la lista" << endl;
    cout << "\t4. Salir" << endl;
    return;
}

// MAIN
//
// ///////////////////
int main(int argc, char const *argv[])
{ // guarda las direcciones en diccionario
    cargar_direcciones("base_datos\\directorio.txt");
    // Declaracion
    Larticulo *Productos = new Larticulo(directorio["productos"]);

    // Productos base para juguetear
    Productos->agregar("A0001", "Donas con Chocolate", 4.2, 66);
    Productos->agregar("A0002", "Tartaleta de Manzana", 6, 45);
    Productos->agregar("A0003", "Quesillo", 3, 12);
    Productos->agregar("A0004", "Galletas de Avena", 2, 124);

    // datos
    int opcion = -1;
    char tecla;

    // Menu
    while (opcion != 4)
    {
        imprimirMenu();
        cout << "\nIngresa la opcion: ";
        cin >> opcion;

        if (opcion >= 0 & opcion <= 4)
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
                break;

            case 3:
                // Lista
                cout << "Lista de articulos" << endl;
                Productos->imprimir();

                editarFuncion(Productos);

                // Opciones distintas

                tecla = _getch(); // Tiene que presionar una tecla para continuar
                break;

            default:
                break;
            }
        }
    }

    return 0;
}
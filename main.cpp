#include <iostream>
#include <fstream>
#include <string>
#include <map>   //NUEVA LIBRERIA
#include <regex> // Para validar
// Para manejar el uso de los key arrows
#include <conio.h>

// Include other files
#include "regex/regex_utils.h"

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
    };

    // EDICION
    //
    //

    // EditarFuncion
    void editarFuncion()
    {
        {
            int numNodo = 0;
            int intBuscar, intValor, opcion, editarValor;
            float floatBuscar, floatValor;
            string strBuscar, strValor;

            // Menu funcionalidades
            cout << "\nCual modalidad de busqueda deseas aplicar?";
            cout << "\n\n";
            cout << "1 |- Por indice" << endl;
            cout << "2 |- Por ID" << endl;
            cout << "3 |- Por Nombre" << endl;
            cout << "4 |- Por Precios" << endl;
            cout << "5 |- Por Cantidades" << endl;
            cout << "\n";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                cout << "\nCual articulo desea modificar: ";
                cin >> numNodo;
                break;
            case 2:
                cout << "\nIngresa el ID a buscar: ";
                cin >> strBuscar;
                buscarDato(strBuscar, opcion, numNodo);
                break;
            case 3:
                cout << "\nIngresa el nombre a buscar: ";
                cin >> strBuscar;
                buscarDato(strBuscar, opcion, numNodo);
                break;
            case 4:
                cout << "\nIngresa el precio a buscar: ";
                cin >> floatBuscar;
                buscarDato(floatBuscar, opcion, numNodo);
                break;
            case 5:
                cout << "\nIngresa la cantidad especifica a buscar: ";
                cin >> intBuscar;
                buscarDato(intBuscar, opcion, numNodo);
                break;

            default:
                break;
            }

            imprimir(numNodo);

            if (numNodo != 0)
            {
                cout << "\nQue desea modificar? " << endl;
                cout << "1 |- El ID" << endl;
                cout << "2 |- El Nombre" << endl;
                cout << "3 |- El Precio" << endl;
                cout << "4 |- Su Cantidad" << endl;
                cout << "\n";
                cout << "Presione la opcion correcta: ";
                cin >> editarValor;

                cout << "\n Ingrese el valor a introducir: ";

                // Introducir el valor
                switch (editarValor)
                {
                //  El ID
                case 1:
                    cin >> strValor;
                    editarDato(strValor, editarValor, numNodo);
                    break;

                case 2:
                    cin >> strValor;
                    editarDato(strValor, editarValor, numNodo);
                    break;

                case 3:
                    cin >> floatValor;
                    editarDato(floatValor, editarValor, numNodo);

                    break;

                case 4:
                    cin >> intValor;
                    editarDato(intValor, editarValor, numNodo);
                    break;

                default:
                    break;
                };
            }
            else
            {
                cout << "\nNo se consiguio ningun producto con esas caracteristicas..." << endl;
                _getch(); // Tiene que presionar una tecla para continuar
            }
        }
    }

    // BuscarHelper
    template <typename T>
    void buscarDato(T valor, int opcion, int &numNodo)
    {
        nodoa *actual = this->cabeza;
        bool encontrado = false;

        if (opcion > 1 && opcion <= 5)
        {
            while (actual != NULL && !encontrado)
            {
                // Encontrado por id o por nombre
                if constexpr (is_same<T, string>::value)
                {
                    if (actual->articulo.id == valor || actual->articulo.nombre == valor)
                    {
                        encontrado = true;
                    }
                }

                // Encontrado por precio
                if constexpr (is_same<T, float>::value)
                {
                    if (actual->articulo.precio == valor)
                    {
                        encontrado = true;
                    }
                }

                // Encontrado por cantidad
                if constexpr (is_same<T, int>::value)
                {
                    if (actual->articulo.cantidad == valor)
                    {
                        encontrado = true;
                    }
                }

                actual = actual->prox;
                numNodo++;
            }

            // En caso de no encontrar nada
            if (!encontrado)
            {
                numNodo = 0;
            }
            else
            {
                cout << "\nValor encontrado!! " << endl;
                _getch(); // Tiene que presionar una tecla para continuar
            }
        }
    }

    // EditarHelper
    template <typename T>
    void editarDato(T valor, int editar, int &numNodo)
    {

        // Me aseguro de que el valor es valido:
        // static_assert(is_same<T, int>::value || is_same<T, string>::value || is_same<T, float>::value, "Tipo de dato no compatible");

        int iterador = 1;
        nodoa *actual = this->cabeza;

        while (actual != NULL)
        {
            if (iterador == numNodo)
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

    // Sumar y Restar
    //
    //
    void operacion(int select, bool sumar = true)
    {

        int iterador = 1;
        nodoa *actual = this->cabeza;

        while (actual != NULL)
        {
            if (iterador == select)
            {
                sumar ? actual->articulo.cantidad++ : actual->articulo.cantidad--;
            }
            actual = actual->prox;
            iterador++;
        }
    }

    // HELPERS
    //
    //

    void imprimir(int personalizado = 0)
    {
        int iterador = 1;

        system("cls");

        nodoa *actual = this->cabeza;
        cout << "\nArticulos de la lista : " << endl;
        cout << "\n";

        if (personalizado == 0)
        {
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
        }
        else
        {
            while (actual != NULL)
            {
                if (personalizado == iterador)
                {
                    cout << iterador << " |- ";

                    cout << "Id: " << actual->articulo.id;
                    cout << " | nombre: " << actual->articulo.nombre;
                    cout << " | Precio: " << actual->articulo.precio;
                    cout << " | Cantidad: " << actual->articulo.cantidad << endl;
                }
                actual = actual->prox;
                iterador++;
            }
        }
    };

    // LECTURA DE DATOS
    //
    //
    /// Constructor, va a leer el ,txt y va a llenar la lista
    Larticulo(string direccion)
    {
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
                precio = stof(linea); // cast de libreria string
                getline(archivo, linea);
                cantidad = stoi(linea);
                this->agregar(id, nombre, precio, cantidad);
            }
        };
    };

    // LIBERACION MEMORIA
    //
    //
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

// * ESTRUCTURA CLIENTES

class Cliente // Objeto que tiene cada nodo de cliente
{

public:
    long int cedula = 0;
    long int telefono = 0;
    string nombre, apellido, direccion;

    void llenar(string nombre, string apellido, long int cedula, long int telefono, string direccion)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->cedula = cedula;
        this->telefono = telefono;
        this->direccion = direccion;
    };
};

class nodoc
{
public:
    Cliente cliente;
    nodoc *prox = NULL;

    // builder
    nodoc(string nombre, string apellido, long int cedula, long int telefono, string direccion)
    {
        this->cliente.llenar(nombre, apellido, cedula, telefono, direccion);
    };
};

class Lclientes
{
public:
    nodoc *cabeza = NULL;

    void pedirDatos()
    {
        long int cedula, telefono;
        string nombre, apellido, direccion;

        system("cls"); // Limpiar terminal

        cout << "Ingrese la cedula del cliente: ";
        cin >> cedula;

        cout << "Ingrese el nombre del cliente: ";
        cin >> nombre;

        cout << "Ingrese el apellido del cliente: ";
        cin >> apellido;

        cout << "Ingrese la direccion del cliente: ";
        cin >> direccion;

        cout << "Ingrese el telefono del cliente: ";
        cin >> telefono;
    };

    void agregar(string nombre, string apellido, long int cedula, long int telefono, string direccion)
    {

        nodoc *nuevo_nodo = new nodoc(nombre, apellido, cedula, telefono, direccion);
        // Chequear si la lista está vacía
        if (this->cabeza == NULL)
        {
            this->cabeza = nuevo_nodo;
        }
        else
        {
            nodoc *actual = this->cabeza;

            while (actual->prox != NULL)
            {

                actual = actual->prox;
            }

            actual->prox = nuevo_nodo;
        }
    };
    // Eliminar por id (cedula)
    void eliminar(long int cedula)
    {

        // Chequear si la lista está vacía
        if (this->cabeza == NULL)
        {
            return;
        }
        else
        {
            nodoc *actual = this->cabeza;
            nodoc *anterior = NULL;

            while (actual != NULL)
            {
                if (actual->cliente.cedula == cedula)
                {
                    if (anterior == NULL)
                    {
                        // Si el nodo a eliminar es la cabeza de la lista
                        this->cabeza = actual->prox;
                    }
                    else
                    {
                        anterior->prox = actual->prox;
                    }
                    delete actual;
                    return;
                }
                anterior = actual;
                actual = actual->prox;
            }
        }
    };

    // Buscar cliente (Retorna el nodo del cliente) por ej si hay más de un cliente con el mismo nombre o apellido devuelve el primero
    template <typename T>
    nodoc *buscarCliente(T valor)
    {
        nodoc *actual = this->cabeza;

        while (actual != NULL)
        {
            // Chequear si el valor es igual a la cedula o al telefono o al nombre/apellido
            if constexpr (is_same<T, long int>::value)
            {
                if (actual->cliente.cedula == valor || actual->cliente.telefono == valor)
                {
                    return actual;
                }
            }
            else if constexpr (is_same<T, string>::value)
            {
                if (actual->cliente.nombre == valor || actual->cliente.apellido == valor)
                {
                    return actual;
                }
            }

            actual = actual->prox;
        }

        // In case no client is found
        return NULL;
    }

    void editarCliente(long int cedula)
    {
        long int cedulaBuscar, longValor;
        string strValor;
        int opcion;

        // Menu funcionalidades
        cout << "\nIngrese la cedula del cliente que desea modificar: ";
        cin >> cedulaBuscar;

        nodoc *clienteNodo = buscarCliente(cedulaBuscar);

        if (clienteNodo != NULL)
        {
            cout << "\nQue desea modificar? " << endl;
            cout << "1 |- El nombre" << endl;
            cout << "2 |- El apellido" << endl;
            cout << "3 |- La cedula" << endl;
            cout << "4 |- La direccion" << endl;
            cout << "5 |- El telefono" << endl;
            cout << "\n";
            cin >> opcion;

            switch (opcion)
            {
            case 1: // Nombre
                cout << "\nIngrese el nuevo nombre: ";
                cin >> strValor;
                editarDato(strValor, opcion, cedulaBuscar);
                break;
            case 2: // Apellido
                cout << "\nIngrese el nuevo apellido: ";
                cin >> strValor;
                editarDato(strValor, opcion, cedulaBuscar);
                break;
            case 3: // Cedula
                cout << "\nIngrese la nueva cedula: ";
                cin >> longValor;
                editarDato(longValor, opcion, cedulaBuscar);
                break;
            case 4: // Direccion
                cout << "\nIngrese la nueva direccion: ";
                cin >> strValor;
                editarDato(strValor, opcion, cedulaBuscar);
                break;
            case 5: // Telefono
                cout << "\nIngrese el nuevo telefono: ";
                cin >> longValor;
                editarDato(longValor, opcion, cedulaBuscar);
                break;
            default:
                cout << "Opcion no valida!!" << endl;
                break;
            }
        }
        else
        {
            cout << "Cliente no encontrado!!" << endl;
        }
    }

    // * Helpers

    template <typename T>
    void editarDato(T valor, int opcion, long int cedula)
    {
        // Encontrar al cliente
        nodoc *clienteNodo = buscarCliente(cedula);

        if (clienteNodo != NULL)
        {

            switch (opcion)
            {
            case 1: // Nombre

                if constexpr (is_same<T, string>::value)
                {
                    clienteNodo->cliente.nombre = valor;
                }
                break;
            case 2: // Apellido
                if constexpr (is_same<T, string>::value)
                {
                    clienteNodo->cliente.apellido = valor;
                }
                break;
            case 3: // Cedula
                if constexpr (is_same<T, long int>::value)
                {
                    clienteNodo->cliente.cedula = valor;
                }

                break;
            case 4: // Direccion
                if constexpr (is_same<T, string>::value)
                {
                    clienteNodo->cliente.direccion = valor;
                }

                break;
            case 5: // Telefono
                if constexpr (is_same<T, long int>::value)
                {
                    clienteNodo->cliente.telefono = valor;
                }
                break;
            default:
                cout << "Opcion no valida!!" << endl;
                break;
            }
        }
        else
        {
            cout << "Cliente no encontrado!!" << endl;
        }
    }

    void imprimir()
    {
        system("cls");

        nodoc *actual = this->cabeza;
        cout << "\nClientes : " << endl;
        cout << "\n";

        while (actual != NULL)
        {
            cout << "Nombre: " << actual->cliente.nombre << " ";
            cout << "Apellido: " << actual->cliente.apellido << " ";
            cout << "Cedula: " << actual->cliente.cedula << " ";
            cout << "Telefono: " << actual->cliente.telefono << " ";
            cout << "Direccion: " << actual->cliente.direccion << " ";

            actual = actual->prox;
        }
    }

    // * CONSTRUCTOR (lee el .txt y llena la lista)
    Lclientes(string direccion)
    {
        fstream archivo;
        string linea;
        string nombre, apellido, direccion;
        long int cedula, telefono;
        archivo.open(direccion, std::ios::in);
        if (archivo.is_open())
        {
            while (getline(archivo, linea))
            {
                nombre = linea;
                getline(archivo, linea);
                apellido = linea;
                getline(archivo, linea);
                cedula = stol(linea);
                getline(archivo, linea);
                telefono = stol(linea);
                getline(archivo, linea);
                direccion = linea;
                this->agregar(nombre, apellido, cedula, telefono, direccion);
            }
        }
    }

    // * Liberacion de memoria (Destructor)
    ~Lclientes()
    {
        nodoc *actual = this->cabeza;
        while (actual != NULL)
        {
            nodoc *temp = actual;
            actual = actual->prox;
            delete temp;
        }

        this->cabeza = NULL; // Establecer cabeza como NULL
    }
};

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
    cout << "\t4. Sumar o Restar un producto de la lista" << endl;
    cout << "\t5. Salir" << endl;
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

    // datos
    int opcion = -1;
    char tecla;

    // Menu
    while (opcion != 5)
    {
        imprimirMenu();
        cout << "\nIngresa la opcion: ";
        cin >> opcion;

        if (opcion >= 0 & opcion <= 5)
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

                Productos->editarFuncion();

                // Opciones distintas

                tecla = _getch(); // Tiene que presionar una tecla para continuar
                break;

            case 4:
                // Lista
                cout << "Lista de articulos" << endl;
                Productos->imprimir();

                int editarNodo, opcionOperacion;

                cout << "\nCual Nodo deseas modificar: ";
                cin >> editarNodo;

                cout << "\nDeseas restar o sumar?";
                cout << "\n1. |- Sumar";
                cout << "\n2. |- Restar";

                cout << "\nIngresa el valor: ";
                cin >> opcionOperacion;

                if (opcionOperacion == 1)
                {
                    Productos->operacion(editarNodo);
                };

                if (opcionOperacion == 2)
                {
                    Productos->operacion(editarNodo, false);
                }

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
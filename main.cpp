#include <iostream>
#include <fstream>
#include <string>
#include <map>   //NUEVA LIBRERIA
#include <regex> // Para validar
// Para manejar el uso de los key arrows
#include <conio.h>

// Include other files
#include "regex/regex_utils.h"

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
        string input, id, nombre;
        bool temporal;
        float precio;
        int cantidad;

        system("cls");

        // Validation made it
        // ID VALIDATION
        cin.ignore();
        cout << "\nIngresa el ID, formato(A0000): ";

        validateStrInput(id, true);

        system("cls");

        // INPUT VALIDATIONS
        //
        input.clear();
        cout << "\nIngresa el nombre del articulo: ";

        validateStrInput(nombre);

        // Precio validation
        system("cls");

        input.clear();
        cout << "\nIngresa el precio del producto: ";

        funcFloat(precio);

        system("cls");

        input.clear();
        cout << "\nIngresa la cantidad de elementos: ";

        funcInt(cantidad);

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
            string input, strBuscar, strValor;

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
                cin.ignore();
                validateStrInput(strBuscar, true);
                buscarDato(strBuscar, opcion, numNodo);
                break;
            case 3:
                cout << "\nIngresa el nombre a buscar: ";
                cin.ignore();
                validateStrInput(strBuscar);
                buscarDato(strBuscar, opcion, numNodo);
                break;
            case 4:
                cout << "\nIngresa el precio a buscar: ";
                funcFloat(floatBuscar);
                buscarDato(floatBuscar, opcion, numNodo);
                break;
            case 5:
                cout << "\nIngresa la cantidad especifica a buscar: ";
                funcInt(intBuscar);
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
                    // Validation made it
                    validateStrInput(strValor, true);
                    editarDato(strValor, editarValor, numNodo);
                    break;

                case 2:
                    validateStrInput(strValor);
                    editarDato(strValor, editarValor, numNodo);
                    break;

                case 3:
                    funcFloat(floatValor);
                    editarDato(floatValor, editarValor, numNodo);

                    break;

                case 4:
                    funcInt(intValor);
                    editarDato(intValor, editarValor, numNodo);
                    break;

                default:
                    break;
                };
            }
            else
            {
                cout << "\nNo se consiguio ningun producto con esas caracteristicas...\n\n"
                     << endl;
                // Seguir
                cout << "Presiona cualquier tecla para continuar...";
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
    string direccion = "";
    Larticulo(string dir) // Llena la lista a partir del archivo .txt
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
                id = linea; /// Falta verificar que tenga un codigo valido IMPORTANTEEEE
                getline(archivo, linea);
                nombre = linea;
                getline(archivo, linea);

                try // control de errores
                {
                    precio = stof(linea);
                } // cast de libreria string
                catch (const std::invalid_argument &e)
                {
                    getline(archivo, linea);
                    continue;
                }

                try
                {
                    getline(archivo, linea);
                    cantidad = stoi(linea);
                }
                catch (const std::invalid_argument &e)
                {
                    continue;
                }
                this->agregar(id, nombre, precio, cantidad);
            }
        };
    };

    void refrescar() /// COPIA TODO LO QUE ESTA EN LA LISTA EN SU BASE DE DATOS CORRESPONDIENTE
    {                // actualiza toda la base de datos.txt(productos.txt)
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

    // LIBERACION MEMORIA
    //

    ~Larticulo() // Destructor para liberar la memoria
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
// int dia, mes, ano;///////////////
struct Fecha
{
    short int dia, mes, ano;
    // builder
};
struct NyA // Nombre y Apellido
{
    string nombre, apellido;
};
/*
long int cedula = 0;
NyA *nombre = NULL;
Fecha *Fecha_ingreso;
int p_comision;
int score = 0; */
class Vendedor // objeto que va en la posicion de DATA del nodo
{

public:
    long int cedula = 0;
    NyA *nombre = NULL;
    Fecha *Fecha_ingreso;
    int p_comision;
    int score = 0;
    // falta por agregar receta;
    // METODO
    void llenar(long int cedula, NyA *nombre, Fecha *fecha, int p_comision, int score)
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

    nodov(long int cedula, NyA *nombre, Fecha *fecha, int p_comision, int score)
    {
        this->vendedor.llenar(cedula, nombre, fecha, p_comision, score);
    };
};

class Lvendedor
{

public:
    nodov *cabeza = NULL;
    string direccion;
    int comision_default = 10;
    // metodo
    void agregar(long int cedula, NyA *nombre, Fecha *fecha, int p_comision, int score)
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
        cout << "Vendedores de la lista : " << endl;
        while (actual != NULL)
        {

            cout << "Cedula: " << actual->vendedor.cedula;
            cout << " nombre: " << actual->vendedor.nombre->nombre << ' ' << actual->vendedor.nombre->apellido;
            cout << " Fecha de ingreso:" << actual->vendedor.Fecha_ingreso->dia << '/';
            cout << actual->vendedor.Fecha_ingreso->mes << '/' << actual->vendedor.Fecha_ingreso->ano << endl;
            cout << " Score de ventas: " << actual->vendedor.score << endl;
            actual = actual->prox;
        }
    };

    Lvendedor(string dir) // Llena la lista a partir del archivo .txt
    {                     /// 8 lineas de txt por vendedor
        direccion = dir;
        fstream archivo;
        string linea;
        long int cedula;
        NyA *nombre = new NyA;
        Fecha *F_ingreso = new Fecha;
        int p_comision;
        int score;
        archivo.open(direccion, std::ios::in);
        if (archivo.is_open())
        {
            while ((getline(archivo, linea))) // primera linea buscada
            {

                validateInt(linea) ? cedula = stol(linea) : cedula = 0;
                getline(archivo, linea);

                validateStr(linea) ? nombre->nombre = linea : nombre->nombre = "";
                getline(archivo, linea);

                validateStr(linea) ? nombre->apellido = linea : nombre->apellido = "";
                getline(archivo, linea);

                validateInt(linea) ? F_ingreso->dia = stoi(linea) : F_ingreso->dia = 0;
                getline(archivo, linea);

                validateInt(linea) ? F_ingreso->mes = stoi(linea) : F_ingreso->mes = 0;
                getline(archivo, linea);

                validateInt(linea) ? F_ingreso->ano = stoi(linea) : F_ingreso->ano = 0;
                getline(archivo, linea);

                validateInt(linea) ? p_comision = stoi(linea) : p_comision = comision_default;
                getline(archivo, linea);

                validateInt(linea) ? score = stoi(linea) : score = 0;
                cout << cedula << ' ' << p_comision << endl;
                _getch();
                this->agregar(cedula, nombre, F_ingreso, p_comision, score);
                nombre = new NyA;
                F_ingreso = new Fecha;
            }
        };
        archivo.close();
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

bool esNumero(const string &str)
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

class Cliente // Objeto que tiene cada nodo de cliente
{

public:
    long int cedula = 0;
    long long telefono = 0;
    string nombre, apellido, direccion;

    void llenar(string nombre, string apellido, long int cedula, long long telefono, string direccion)
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
    nodoc(string nombre, string apellido, long int cedula, long long telefono, string direccion)
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
        long int cedula;
        long long telefono;
        string nombre, apellido, direccion, cedula_str, telefono_str;

        system("cls"); // Limpiar terminal

        // Pedir la cédula y validar
        cout << "Ingrese la cedula del cliente (entre 7 y 8 digitos): ";
        cin >> cedula_str;

        while (!esNumero(cedula_str) || cedula_str.length() < 7 || cedula_str.length() > 8)
        {
            cout << "Cedula invalida. Ingrese nuevamente (entre 7 y 8 digitos): ";
            cin >> cedula_str;
        }

        cedula = stol(cedula_str); // Convertir la cadena a long int

        cout << "Ingrese el nombre del cliente: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Ingrese el apellido del cliente: ";
        cin.ignore();
        getline(cin, apellido);

        cout << "Ingrese la direccion del cliente: ";
        cin.ignore();
        getline(cin, direccion);

        cout << "Ingrese el telefono del cliente: ";
        cin >> telefono_str;

        // Validar que el teléfono tenga exactamente 11 digitos
        while (telefono_str.length() != 11)
        {
            cout << "Debe tener exactamente 11 digitos. Ingrese nuevamente: ";
            cin >> telefono_str;
        }

        // Validar que todos los caracteres sean dígitos
        for (char c : telefono_str)
        {
            if (!isdigit(c))
            {
                cout << "Numero de telefono invalido. Ingreselo nuevamente: ";
                cin >> telefono_str;
                break;
            }
        }

        telefono = stoll(telefono_str); // Convertir la cadena a long long

        agregar(nombre, apellido, cedula, telefono, direccion);
    };

    void agregar(string nombre, string apellido, long int cedula, long long telefono, string direccion)
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
    void eliminar()
    {

        long int cedula;
        cout << "Ingrese la cedula del cliente que quiere eliminar: ";
        cin >> cedula;

        // Chequear si la lista está vacía
        if (this->cabeza == NULL || !cedula)
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
                    cout << "Cliente eliminado!";
                    nodoc *temp = actual;
                    delete temp;
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
                string nombreCliente = toUpper(actual->cliente.nombre);
                string apellidoCliente = toUpper(actual->cliente.apellido);

                if (nombreCliente == valor || apellidoCliente == valor)
                {
                    return actual;
                }
            }

            actual = actual->prox;
        }

        // In case no client is found
        return NULL;
    }

    void buscarClienteMenu()
    {
        int opcion;
        long int cedulaBuscar;
        long long telefonoBuscar;
        string nombreBuscar;

        cout << "\nIngrese la opcin de busqueda: " << endl;
        cout << "1 |- Buscar por cedula" << endl;
        cout << "2 |- Buscar por nombre" << endl;
        cout << "3 |- Buscar por telefono" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        { // Buscar por cédula
            cout << "\nIngrese la cedula del cliente: ";
            cin >> cedulaBuscar;
            nodoc *clienteNodoCedula = buscarCliente(cedulaBuscar);
            if (clienteNodoCedula != NULL)
            {
                cout << "Cliente encontrado: " << clienteNodoCedula->cliente.nombre << endl;
            }
            else
            {
                cout << "Cliente no encontrado" << endl;
            }
            break;
        }
        case 2:
        { // Buscar por nombre
            cout << "\nIngrese el nombre del cliente: ";
            cin >> nombreBuscar;

            nombreBuscar = toUpper(nombreBuscar);
            nodoc *clienteNodoNombre = buscarCliente(nombreBuscar);
            if (clienteNodoNombre != NULL)
            {
                cout << "Cliente encontrado: " << clienteNodoNombre->cliente.nombre << endl;
            }
            else
            {
                cout << "Cliente no encontrado" << endl;
            }
            break;
        }
        case 3:
        { // Buscar por telefono
            cout << "\nIngrese el telefono del cliente: ";
            cin >> telefonoBuscar;

            nodoc *clienteNodoTelefono = buscarCliente(telefonoBuscar);
            if (clienteNodoTelefono != NULL)
            {
                cout << "Cliente encontrado: " << clienteNodoTelefono->cliente.nombre << endl;
            }
            else
            {
                cout << "Cliente no encontrado" << endl;
            }
            break;
        }
        default:
            cout << "Opción no valida" << endl;
            break;
        }
    }

    void editarCliente()
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

    string toUpper(const string &s)
    {
        string upperStr = s;
        for (char &c : upperStr)
        {
            c = toupper(c);
        }
        return upperStr;
    }

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
            cout << "Direccion: " << actual->cliente.direccion << endl;

            cout << endl;

            actual = actual->prox;
        }
    }

    // * CONSTRUCTOR (lee el .txt y llena la lista)
    Lclientes(string direccion)
    {
        fstream archivo;
        string linea;
        string nombre, apellido, direccion_cliente;
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
                telefono = stoll(linea);
                getline(archivo, linea);
                direccion_cliente = linea;
                this->agregar(nombre, apellido, cedula, telefono, direccion_cliente);
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

void imprimirMenu(int opcion = 0)
{
    system("cls"); // Limpia la consola

    switch (opcion)
    {
    case 0:
        cout << "Bienvenido a Pan de Yoyo" << endl;
        cout << "\n";
        cout << "\t1. Articulos" << endl;
        cout << "\t2. Vendedores" << endl;
        cout << "\t3. Clientes" << endl;
        cout << "\t4. Salir" << endl;
        break;

    case 1:

        cout << "Bienvenido a Pan de Yoyo" << endl;
        cout << "\n";
        cout << "\t1. Agrega un articulo" << endl;
        cout << "\t2. Imprime la lista de articulos" << endl;
        cout << "\t3. Edita un articulo de la lista" << endl;
        cout << "\t4. Sumar o Restar un producto de la lista" << endl;
        cout << "\t5. Volver" << endl;
        break;

    case 2:

        cout << "Bienvenido a Pan de Yoyo" << endl;
        cout << "\n";
        cout << "\t1. Agrega a vendedores" << endl;
        cout << "\t2. Imprime la lista de vendedores" << endl;
        cout << "\t3. Edita un vendedor de la lista" << endl;
        cout << "\t4. Sumar o Restar un producto de la lista" << endl;
        cout << "\t5. Volver" << endl;
        break;

    case 3:

        cout << "Bienvenido a Pan de Yoyo" << endl;
        cout << "\n";
        cout << "\t1. Agrega un cliente" << endl;
        cout << "\t2. Imprime la lista de clientes" << endl;
        cout << "\t3. Edita un cliente de la lista" << endl;
        cout << "\t4. Buscar un cliente en la base de datos" << endl;
        cout << "\t5. Eliminar un cliente de la base de datos" << endl;
        cout << "\t6. Volver" << endl;
        break;

    default:
        break;
    }
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
    Lvendedor *Vendedores = new Lvendedor(directorio["vendedores"]);
    Vendedores->imprimir();

    int u;
    cin >> u;

    // cout << Productos;
    // cout << C

    // datos
    int opcion = -1;
    int intMenu = -1;
    char tecla;

    // Menu
    while (intMenu != 4)
    {
        imprimirMenu();
        cout << "\nIngresa la opcion: ";
        cin >> intMenu;
        opcion = -1;

        switch (intMenu)
        {
        case 1:
            while (opcion != 5)
            {
                imprimirMenu(1);
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

            break;

        case 2:
            while (opcion != 5)
            {
                imprimirMenu(2);
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
            break;
        case 3:
            while (opcion != 6)
            {
                imprimirMenu(3);
                cout << "\nIngresa la opcion: ";
                cin >> opcion;

                if (opcion >= 0 & opcion <= 5)
                {
                    switch (opcion)
                    {
                    case 1:

                        // Agregar un cliente
                        cout << "Ingresa la data del cliente: " << endl;
                        Clientes->pedirDatos();

                        Clientes->imprimir();

                        cout << "\nPresiona cualquier tecla para continuar...";

                        tecla = _getch(); // Tiene que presionar una tecla para continuar
                        break;

                    case 2:
                        // Lista
                        cout << "Lista de clientes" << endl;
                        Clientes->imprimir();

                        cout << "\nPresiona cualquier tecla para continuar...";

                        tecla = _getch(); // Tiene que presionar una tecla para continuar
                        break;

                    case 3:
                        // Lista
                        cout << "Editar cliente :)" << endl;
                        Clientes->imprimir();

                        Clientes->editarCliente();

                        // Opciones distintas

                        tecla = _getch(); // Tiene que presionar una tecla para continuar
                        break;

                    case 4:

                        system("cls");
                        // Lista
                        Clientes->buscarClienteMenu();
                        // Opciones distintas

                        tecla = _getch(); // Tiene que presionar una tecla para continuar
                        break;
                    case 5:

                        system("cls");
                        // Lista
                        Clientes->eliminar();
                        // Opciones distintas

                        tecla = _getch(); // Tiene que presionar una tecla para continuar
                        break;

                    default:
                        break;
                    }
                }
            }

        default:
            break;
        }
    }

    delete Productos;
    delete Clientes;
    return 0;
}
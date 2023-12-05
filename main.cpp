#include <iostream>
#include <fstream>
#include <string>
#include <map> //NUEVA LIBRERIA
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
        string input, id, nombre;
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
                getline(cin, strBuscar);
                buscarDato(strBuscar, opcion, numNodo);
                break;
            case 3:
                cout << "\nIngresa el nombre a buscar: ";
                cin.ignore();
                getline(cin, strBuscar);
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
                    // Validation made it
                    cin.ignore();
                    while (!validateID(input))
                    {
                        getline(cin, input);
                        if (validateID(input))
                        {
                            strValor = input;
                            break;
                        }
                        else
                        {
                            cout << "Ingresa un ID valido! \n";
                            cout << "\nVuelve a intentarlo: ";
                        }
                    };
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
            while (getline(archivo, linea)) // primera linea buscada
            {
                try
                {
                    cedula = stof(linea);
                }
                catch (const std::invalid_argument &e)
                {
                    cout << "ERROR EN CEDULA";
                    for (int i = 1; i <= 7; i++)
                        getline(archivo, linea);
                    continue;
                }
                getline(archivo, linea);
                nombre->nombre = linea;
                getline(archivo, linea);
                nombre->apellido = linea;
                try
                {
                    F_ingreso->dia = stof(linea);
                }
                catch (const std::invalid_argument &e)
                {
                    for (int i = 1; i <= 4; i++)
                        getline(archivo, linea);
                    continue;
                }
                try
                {
                    F_ingreso->mes = stof(linea);
                }
                catch (const std::invalid_argument &e)
                {
                    for (int i = 1; i <= 3; i++)
                        getline(archivo, linea);
                    continue;
                }
                try
                {
                    F_ingreso->ano = stof(linea);
                }
                catch (const std::invalid_argument &e)
                {
                    for (int i = 1; i <= 2; i++)
                        getline(archivo, linea);
                    continue;
                }
                try
                {
                    p_comision = stof(linea);
                }
                catch (const std::invalid_argument &e)
                {
                    getline(archivo, linea);
                    continue;
                }
                try
                {
                    score = stof(linea);
                }
                catch (const std::invalid_argument &e)
                {
                    continue;
                }

                this->agregar(cedula, nombre, F_ingreso, p_comision, score);
            }
        };
    };
};

// Crear el dato tipo template
template <typename T>
T inputValor()
{
    T valor;
    return cin >> valor;
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
        cout << "\t3. Salir" << endl;
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

    cout << Productos;

    // datos
    int opcion = -1;
    int intMenu = -1;
    char tecla;

    // Menu
    while (intMenu != 3)
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

        default:
            break;
        }
    }

    delete Productos;
    return 0;
}
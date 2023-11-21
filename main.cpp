#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Articulo
{
    string id;
    string nombre;
    int cantidad;
    float precio;
};

struct Node
{
    // int id;
    Articulo articulo;
    Node *next;
};

Node *crear_nodo_articulo(Articulo articulo)
{

    Node *new_node = new Node;

    if (new_node)
    {
        new_node->articulo = articulo;
        new_node->next = NULL;
    }
    else
    {
        cerr << "Error creating new node." << endl;
    }

    return new_node;
}

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
void agregar_articulo_lista(Node **headRef, Articulo articulo)
{
    Node *current = *headRef;
    Node *new_node = crear_nodo_articulo(articulo);

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
}

void print_list(Node *head)
{

    Node *current = head;

    while (current != NULL)
    {
        cout << "ID: " << current->articulo.id << endl;
        cout << "Nombre: " << current->articulo.nombre << endl;
        cout << "Precio: " << current->articulo.precio << endl;
        cout << "Cantidad: " << current->articulo.cantidad << endl;
        cout << "----------------------" << endl;

        current = current->next;
    }
}

void printMenu()
{
    cout << "Bienvenido a Pan de Yoyo" << endl;
    cout << "\t1. Agrega un articulo" << endl;
    cout << "\t2. Imprime la lista de articulos" << endl;
    cout << "\t3. Salir" << endl;
    return;
}

int main(int argc, char **argv)
{
    Node *head = NULL;
    int option = -1;
    Articulo articulo;

    while (option != 3)
    {
        printMenu();
        int num_received = scanf("%d", &option);

        if (num_received == 1 && option > 0 && option <= 3)
        {
            switch (option)
            {
            case 1:
                // Agregar articulo
                cout << "Ingresa la data del articulo" << endl;
                articulo = crear_articulo();
                agregar_articulo_lista(&head, articulo);
                agregar_articulo_archivo(articulo);
                break;

            case 2:
                cout << "Lista de articulos" << endl;
                print_list(head);
                break;

            default:
                break;
            }
        }
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
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

            cout << "Id: " << this->cabeza->articulo.id;
            cout << " nombre: " << this->cabeza->articulo.nombre;
            cout << " Precio: " << this->cabeza->articulo.precio;
            cout << " Cantidad: " << this->cabeza->articulo.cantidad << endl;
            actual = actual->prox;
        }
    };
};

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

int main(int argc, char const *argv[])
{
    Larticulo *Productos = new Larticulo;
    Productos->agregar("A0001", "Donas Sabrosssas", 4.2, 66);
    Productos->imprimir();

    return 0;
}

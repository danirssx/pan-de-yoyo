#include <iostream>
#include <fstream>
#include <string>
#include <map> //NUEVA LIBRERIA

using namespace std;

map<string, string> direccion;

void cargar_direcciones(string directorio)
{
    fstream archivo;
    string linea;
    string lista[5] = {"clientes", "vendedores", "productos", "materia_prima", "recetas"};
    archivo.open(directorio, std::ios::in);
    if (archivo.is_open())
    {
        int i = 0;
        while (getline(archivo, linea))
        {
            direccion[lista[i]] = linea;
            i++;
        }
        archivo.close();
    }
};

int main(int argc, char const *argv[])
{
    cargar_direcciones("base_datos\\directorio.txt");
    cout << direccion["recetas"];
    return 0;
}

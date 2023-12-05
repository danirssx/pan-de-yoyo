// MENU EN CONSTRUCCION

// Submenus completos
enum class M
{
    Entrada,
    Venta,
    Inventario,
    Ginventario,
    Gclientes,
    Gvendedores,
};

void mostrarMenu(M actual)
{
    system("cls"); // Procede a limpiar la pantalla

    switch (actual)
    {
    case M::Entrada:

        cout << "Bienvenido a Pan de Yoyo" << endl;
        cout << "\t1. Ingresar Venta" << endl;
        cout << "\t2. Acceso al Inventario" << endl;
        break;

    case M::Venta:
        cout << "¿Qué vendedor hace la venta?" << endl;
        break;

    case M::Inventario:
        cout << "Gestión Inventario" << endl;
        cout << "Gestión Clientes" << endl;
        cout << "Gestión Vendedores" << endl;
        break;

    case M::GInventario:
        cout << "Ingresa Datos:" << endl;
        break;

    case M::Gclientes:
        cout << "Ingresa Datos:" << endl;
        break;

    case M::Gvendedores:
        cout << "Ingresa Datos:" << endl;
        break;

    default:
        break;
    }
}

void menu()
{
    M opcionActual = M::Entrada;
    char key;
    bool activo = true;

    while (activo)
    {
        // Impresion Principal
        displayMenu(opcionActual);

        key = _getch(); // Funcion para agarrar el caracter

        switch (key)
        {
        case 72: // Flecha hacia arriba
            /* code */
            break;

        default:
            break;
        }
    }
};

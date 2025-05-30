#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Compra {
    string tipoProducto;
    float precioUnitario;
    int cantidad;
    string proveedor;
    string fecha;
};

struct Venta {
    int codigoCliente;
    string tipoCliente;
    string nombreCliente;
    float precioUnitario;
    string fecha;
};

Compra compras[MAX];
int totalCompras = 0;

Venta ventas[MAX];
int totalVentas = 0;

//prototipo
void mostrarMenuPrincipal();
void menuRegistros();
void registrarCompras();
void registrarVentas();
void mostrarReportes();

int main() {
    int opcion;

    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuRegistros();
                break;
            case 2:
                mostrarReportes();
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "\n*****************Opcion invalida. Intente de nuevo.*****************" << endl;
        }
    } while (opcion != 3);

    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n............MENU PRINCIPAL............" << endl;
    cout << "1. Registros " << endl;
    cout << "2. Reportes" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void menuRegistros() {
    int opcion;

    do {
        cout << "\n............MENU DE REGISTROS............" << endl;
        cout << "1. Registrar Compras" << endl;
        cout << "2. Registrar Ventas" << endl;
        cout << "3. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        

        switch (opcion) {
            case 1:
                registrarCompras();
                break;
            case 2:
                registrarVentas();
                break;
            case 3:
                break;
            default:
                cout << "\n*****************Opcion invalida. Intente de nuevo.*****************" << endl;
        }
    } while (opcion != 3);
}


void registrarCompras() {
    Compra compra;

    cout << "\n............Registro de Compras............" << endl;
    cout << "Tipo de producto: ";
    cin >> compra.tipoProducto;
    cout << "Precio unitario: ";
    cin >> compra.precioUnitario;
    cout << "Cantidad: ";
    cin >> compra.cantidad;
    cout << "Nombre del proveedor: ";
    cin >> compra.proveedor;
    cout << "Fecha (dd/mm/aaaa): ";
    cin >> compra.fecha;
	compras[totalCompras] = compra;
	totalCompras++;
    cout << "\nCompra registrada exitosamente.\n";
    cout << "1. Realizar nuevo registro\n2. Regresar al menu\nOpcion: ";
    int opcion;
    cin >> opcion;
    if (opcion == 1) registrarCompras();
}

void registrarVentas() {
    Venta venta;

    cout << "\n............Registro de Ventas............" << endl;
    cout << "Codigo del cliente: ";
    cin >> venta.codigoCliente;
    cout << "Tipo de cliente (particular, mayorista): ";
    cin >> venta.tipoCliente;
    cout << "Nombre del cliente: ";
    cin >> venta.nombreCliente;
    cout << "Precio unitario: ";
    cin >> venta.precioUnitario;
    cout << "Fecha (dd/mm/aaaa): ";
    cin >> venta.fecha;
	ventas[totalVentas] = venta;
	totalVentas++;
    cout << "\nVenta registrada exitosamente.\n";
    cout << "1. Realizar nuevo registro\n2. Regresar al menu\nOpcion: ";
    int opcion;
    cin >> opcion;
    if (opcion == 1) registrarVentas();
}

void mostrarReportes() {
    int opcion;
    
    do {
        cout << "\n............MENU REPORTES............" << endl;
		cout << "1. Movimiento de compras" << endl;
		cout << "2. Movimiento de ventas" << endl;
		cout << "3. Buscar cliente por código" << endl;
		cout << "4. Clientes mayoristas o especiales" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout <<"Ingrese una opcion"<< endl;
        cin >> opcion;
         switch (opcion) {
        case 1:
            cout << "\n............Movimiento de Compras............" << endl;
            for (int i = 0; i < totalCompras; i++) {
                cout << "Producto: " << compras[i].tipoProducto
                     << ", Precio: " << compras[i].precioUnitario
                     << ", Cantidad: " << compras[i].cantidad
                     << ", Proveedor: " << compras[i].proveedor
                     << ", Fecha: " << compras[i].fecha << endl;
            }
            break;
        case 2:
            cout << "\n............Movimiento de Ventas............" << endl;
            for (int i = 0; i < totalVentas; i++) {
                cout << "Codigo Cliente: " << ventas[i].codigoCliente
                     << ", Tipo: " << ventas[i].tipoCliente
                     << ", Nombre: " << ventas[i].nombreCliente
                     << ", Precio: " << ventas[i].precioUnitario
                     << ", Fecha: " << ventas[i].fecha << endl;
            }
            break;
        case 3:{
        int codigo;
        bool encontrado = false;
        cout << "\nIngrese el codigo del cliente a buscar: ";
        cin >> codigo;

        for (int i = 0; i < totalVentas; i++) {
            if (ventas[i].codigoCliente == codigo) {
                cout << "\nCliente encontrado:\n";
                cout << "Codigo: " << ventas[i].codigoCliente
                     << ", Nombre: " << ventas[i].nombreCliente
                     << ", Tipo: " << ventas[i].tipoCliente
                     << ", Precio: " << ventas[i].precioUnitario
                     << ", Fecha: " << ventas[i].fecha << endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "\nCliente no encontrado.\n";
        }
        break;
    }
        	
        case 4: {
        bool hayEspeciales = false;
        cout << "\nClientes mayoristas o casos especiales:\n";

        for (int i = 0; i < totalVentas; i++) {
            if (ventas[i].tipoCliente == "mayorista" || ventas[i].tipoCliente == "especial") {
                cout << "Codigo: " << ventas[i].codigoCliente
                     << ", Nombre: " << ventas[i].nombreCliente
                     << ", Tipo: " << ventas[i].tipoCliente
                     << ", Fecha: " << ventas[i].fecha << endl;
                hayEspeciales = true;
            }
        }

        if (!hayEspeciales) {
            cout << "\nNo hay clientes mayoristas o especiales registrados.\n";
        }
        break;
    }
            
        default:
            cout << "\n*****************Opcion invalida. Intente de nuevo.*****************" << endl;
    }
        
    } while(opcion != 5);
}


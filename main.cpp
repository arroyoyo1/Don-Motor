#include <iostream> 
#include "Negocio.h"

using namespace std;

int main() {
    
    // Si yo pusiera una agencia de car rental totalmente le pondría Don Motor

    Negocio DonMotor;
    int opcion;

    do {
        cout << "Sistema de Alquiler de Vehiculos\n";
        cout << "1. Agregar Vehiculo\n";
        cout << "2. Mostrar Vehiculos\n";
        cout << "3. Agregar Cliente\n";
        cout << "4. Mostrar Clientes\n";
        cout << "5. Alquilar Vehiculo\n";
        cout << "6. Devolver Vehiculo\n";
        cout << "7. Mostrar Alquileres\n";
        cout << "8. Salir\n";
        cout << "Ingresa tu eleccion: ";
        cin >> opcion;
		cout << endl;

        switch (opcion) {
            case 1:
                DonMotor.agregarVehiculo(); 
                break;
            case 2:
                DonMotor.mostrarVehiculos(); 
                break;
            case 3:
                DonMotor.agregarCliente();
                break;
            case 4:
                DonMotor.mostrarClientes();  
                break;
            case 5:
                DonMotor.alquilarVehiculo(); 
                break;
            case 6:
                DonMotor.devolverVehiculo();  
                break;
            case 7:
                DonMotor.mostrarAlquileres();  
                break;
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Eleccion invalida. Por favor intenta de nuevo.\n";
        }

        cout << endl;
    } while (opcion != 8);

}




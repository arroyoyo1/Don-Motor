/*
* Estas directivas evitan la inclusión múltiple del mismo header file en varios source files y ayudan 
* a prevenir errores de compilación debido a la redefinición de clases y funciones.
*/

#ifndef ALQUILER_H
#define ALQUILER_H

/*
* Incluyo los header files de Cliente y Vehiculo ya que esta clase Alquiler tiene atributos que contienen 
* punteros a estos tipos de objetos 
*/

#include "Cliente.h"
#include "Vehiculo.h"

/*
Incluyo las bibliotecas necesarias para el funcionamiento del programa: <iostream> para inputs y outputs
estándar, <string> para manejo de este tipo de dato 
*/

#include <iostream>
#include <string>

using namespace std;

// Esta clase está pensada como un concepto (rentar un vehiculo), más que como un objeto tangible

class Alquiler {

// Atributos de la clase (contiene punteros que apuntan a objetos tipom Vehiculo y Cliente)

private:

    Vehiculo* vehiculo;
    Cliente* cliente;
    string fechaAlquiler;
    string fechaDevolucion;

public:

    // Constructor con la información necesaria para una renta en la vida real

    Alquiler(Vehiculo* vehiculo, Cliente* cliente, string fechaAlquiler, string fechaDevolucion)
    : vehiculo(vehiculo), cliente(cliente), fechaAlquiler(fechaAlquiler), fechaDevolucion(fechaDevolucion) {}

    // Métodos de la clase

    void mostrarInfoAlquiler();

    Vehiculo* getVehiculo(){
        return vehiculo;
    }
};

/*
* Esta función imprime la información del cliente, la del vehículo (sobreescrita dependiendo el tipo) y la duración
* del alquiler
*/

void Alquiler::mostrarInfoAlquiler(){
        cout << "\n-Alquiler-\n";
        cliente->mostrarInfoCliente();
        vehiculo->mostrarInfo();
        cout << "\n-Duración-\n";
        cout << "Fecha de Alquiler: " << fechaAlquiler << "\nFecha de Devolucion: " << fechaDevolucion << endl;
    }

#endif

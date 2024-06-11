/*
* Estas directivas evitan la inclusión múltiple del mismo header file en varios source files y ayudan 
* a prevenir errores de compilación debido a la redefinición de clases y funciones.
*/

#ifndef CLIENTE_H
#define CLIENTE_H

/*
Incluyo las bibliotecas necesarias para el funcionamiento del programa: <iostream> para inputs y outputs
estándar y <string> para manejo de este tipo de dato
*/

#include <iostream>
#include <string>

using namespace std;

class Cliente {

// Atributos de la clase

private:

    string nombre;
    string numeroLicencia;

public:

    /*
    * Aquí solo defino un constructor ya que no tendría sentido tener un cliente que quiera rentar un 
    * vehiculo sin tener una licencia
    */

    Cliente(string nombre, string numeroLicencia) : nombre(nombre), numeroLicencia(numeroLicencia) {}

    // Métodos de la clase

    void mostrarInfoCliente();

    string getNumeroLicencia(){
        return numeroLicencia;
    }
};

// Implementación de un método

void Cliente::mostrarInfoCliente(){
        cout << "\n-Cliente-" << "\nNombre: " << nombre << "\nNumero de Licencia: " << numeroLicencia << endl;
    }

#endif

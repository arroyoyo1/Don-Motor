/*
* Estas directivas evitan la inclusión múltiple del mismo header file en varios source files y ayudan 
* a prevenir errores de compilación debido a la redefinición de clases y funciones.
*/

#ifndef VEHICULO_H
#define VEHICULO_H

/*
Incluyo las bibliotecas necesarias para el funcionamiento del programa: <iostream> para inputs y outputs
estándar y <string> para manejo de este tipo de dato
*/

#include <iostream>
#include <string>

using namespace std;

class Vehiculo {

/*
* Como Vehiculo es una clase de la que heredan 3 clases, sus atributos deben ser protegidos para que 
* sus clases derivadas puedan acceder a ellos.
*/

protected:

    string marca;
    string modelo;
    bool disponible;

public:

    // Creo dos constructores, uno vacío y el otro con parámetros para denotar sobrecarga

    Vehiculo() : marca(""), modelo("") {};
    Vehiculo(string marca, string modelo) : marca(marca), modelo(modelo), disponible(true) {};

    /*
    * Al incluir una función virtual pura, la clase Vehiculo se convierte automáticamente en clase asbtracta
    * Esta función posteriormente se sobreescribirá en las clases derivadas de Vehiculo ya que de momento no
    * tiene una implementación definida en esta clase
    */ 

    virtual void mostrarInfo() = 0;

    bool getDisponibilidad(){
        return disponible;
    }

    void setDisponibilidad(bool disponibilidad) {
        disponible = disponibilidad;
    }

    /*
    * Declaro un destructor virtual para garantizar que se llame al destructor correcto cuando se borren objetos 
    * derivados a través de un puntero a objetos heredados de Vehiculo
    */

    virtual ~Vehiculo() {}
};


class Auto : public Vehiculo {

// Al ser Auto una clase que hereda de Vehiculo, se denota esta relación mediante el ": public Vehiculo"

private:

    int numPuertas;

public:

    // Constructores con y sin parámetros para objetos tipo Auto

    Auto() : Vehiculo ("",""), numPuertas(0) {};
    Auto(string marca, string modelo, int numPuertas) : Vehiculo(marca, modelo), numPuertas(numPuertas) {}

    // Métodos de la clase

    void mostrarInfo();

};

/*
* Este método sobrescribe el método virtual puro mostrarInfo() de la clase base Vehiculo. Lo que hace es 
* que imprime en la terminal la marca, el modelo, el número de puertas y disponibilidad del coche, este 
* último utilizando un operador ternario para evitar utilizar una estructura condicional.
*/

void Auto::mostrarInfo() {
        cout << "\n-Auto-" << "\nMarca: " << marca << "\nModelo: " << modelo << "\nPuertas: " << numPuertas
        << "\nDisponible: " << (disponible ? "Si" : "No") << endl;
    }


class Motocicleta : public Vehiculo {

// Del mismo modo, esta clase hereda de Vehiculo, por lo cual podrá acceder a sus métodos y atributos

private:

    bool tieneSidecar;

public:

    // Constructores con y sin parámetros para objetos tipo Motocicleta

    Motocicleta() : Vehiculo ("",""), tieneSidecar(false) {};
    Motocicleta(string marca, string modelo, bool tieneSidecar) : Vehiculo(marca, modelo), tieneSidecar(tieneSidecar) {}

    // Método de la clase

    void mostrarInfo();

};

// De igual manera que en la clase Auto, se sobreescribe el método virtual puro de Vehiculo

void Motocicleta::mostrarInfo(){
        cout << "\n-Motocicleta-" << "\nMarca: " << marca << "\nModelo: " << modelo << "\nTiene Sidecar: " 
        << (tieneSidecar ? "Si" : "No") << "\nDisponible: " << (disponible ? "Si" : "No") << endl;
    }

class Camion : public Vehiculo {

// Camion hereda de Vehiculo

private:

    float capacidadCarga;

public:

    // Constructores con y sin parámetros para objetos tipo Camion

    Camion() : Vehiculo ("",""), capacidadCarga(0.0) {};
    Camion(string marca, string modelo, float capacidadCarga) : Vehiculo(marca, modelo), capacidadCarga(capacidadCarga) {}

    // Se sobreescribe la función virtual pura de Vehiculo

    void mostrarInfo();
};

// Implementación del método que se sobreescribe

void Camion::mostrarInfo(){
        cout << "\n-Camion-" << "\nMarca: " << marca << "\nModelo: " << modelo << "\nCapacidad de Carga: " 
        << capacidadCarga << " toneladas" << "\nDisponible: " << (disponible ? "Si" : "No") << endl;
    }

#endif






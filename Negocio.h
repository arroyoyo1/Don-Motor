/*
* Estas directivas evitan la inclusión múltiple del mismo header file en varios source files y ayudan 
* a prevenir errores de compilación debido a la redefinición de clases y funciones.
*/

#ifndef NEGOCIO_H
#define NEGOCIO_H

/*
* Incluyo el header file de Alquiler porque esa clase contiene un vector de objetos tipo Alquiler
*/

#include "Alquiler.h"

/*
Incluyo las bibliotecas necesarias para el funcionamiento del programa: <iostream> para inputs y outputs
estándar, <string> para manejo de este tipo de dato y <vector> para usar vectores 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Negocio{

// Atributos de la clase

private:

    // Vector que almacena los vehículos disponibles para alquilar
    vector<Vehiculo*> vehiculos; 

    // Vector que almacena los clientes registrados en el negocio
    vector<Cliente*> clientes; 

    // Vector que almacena los alquileres activos
    vector<Alquiler*> alquileres; 

public:

    // Métodos para administrar vehículos
    void agregarVehiculo();
    void mostrarVehiculos() const;

    // Métodos para administrar clientes
    void agregarCliente();
    void mostrarClientes() const;

    // Métodos para administrar alquileres
    void alquilarVehiculo();
    void devolverVehiculo();
    void mostrarAlquileres() const;

    // Destructor para liberar memoria
    ~Negocio();
};

/*
* En esta función primero se presenta al usuario un menú de 3 opciones para agregar un tipo de vehículo dependiendo
* de qué quiera agregar (auto, moto o camión) y esa elección se guarda en una variable homónima. Después se pide
* la marca, modelo y dependiendo de la opción elegida, una característica única de cada tipo de vehículo con lo cual
* ya se tendrían todos los elementos para aplicar el constructor de cada tipo de objeto. Al final este nuevo objeto
* guardado en el heap, se guarda en el vector vehículos que contiene puros pointers de objetos tipo Vehiculo. Si no se
* selecciona una opción posible, el programa simplemente te dice que la elección no es válida.
*/

void Negocio::agregarVehiculo() {
    int eleccion;
    cout << "Elige el tipo de vehiculo:\n1. Coche\n2. Motocicleta\n3. Camion\n";
    cin >> eleccion;

    string marca, modelo;
    cout << "Ingresa la Marca: ";
    cin >> marca;
    cout << "Ingresa el Modelo: ";
    cin >> modelo;

    if (eleccion == 1) {
        int numPuertas;
        cout << "Ingresa el numero de puertas: ";
        cin >> numPuertas;
        vehiculos.push_back(new Auto(marca, modelo, numPuertas));
    } else if (eleccion == 2) {
        bool tieneSidecar;
        cout << "Tiene sidecar? (1 para Si, 0 para No): ";
        cin >> tieneSidecar;
        vehiculos.push_back(new Motocicleta(marca, modelo, tieneSidecar));
    } else if (eleccion == 3) {
        double capacidadCarga;
        cout << "Ingresa la capacidad de carga (en toneladas): ";
        cin >> capacidadCarga;
        vehiculos.push_back(new Camion(marca, modelo, capacidadCarga));
    } else {
        cout << "Eleccion invalida.\n";
    }
}

/*
* Esta función lo que hace es que itera sobre el vector de vehiculos y muestra dependiendo del índice en el que se 
* encuentra la variable i, la información del objeto que se encuentra en esa posición mediante la función mostrarInfo
* la cual se sobreescribe de diferente manera según sea un auto, moto o camión.
*/

void Negocio::mostrarVehiculos() const {
    for (int i = 0; i < vehiculos.size(); i++) {
        vehiculos[i]->mostrarInfo();
    }
}

/*
* Análogamente, la función agregarCliente funciona de manera similar a la función agregarVehiculo en el sentido de que
* recolecta la información necesaria para aplicar un constructor de objetos tipo Cliente, solo que antes de eso, hago
* uso de la función cin.ignore (que ya es parte de la biblioteca iostream) y la razón por la que lo hago es para evitar
* problemas con caracteres residuales como saltos de linea o espacios y asegurar de que agarre bien la siguiente línea
* que es la de getline que permite obtener múltiples caracteres del input proporcionado por el usuario. Una vez recolec-
* tados los datos necesarios para crera un cliente, se mete a un vector que contiene pointers a objetos de tipo Cliente
*/

void Negocio::agregarCliente() {
    string nombre, numeroLicencia;
    cout << "Ingresa el nombre del cliente: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingresa el numero de licencia: ";
    cin >> numeroLicencia;

    clientes.push_back(new Cliente(nombre, numeroLicencia));
}

/*
* Del mismo modo, este vector clientes se puede iterar para mostrar cada objeto guardado en él mediante un ciclo for donde
* a cada índice se le muestra su información mediante la función mostrarInfoCliente
*/

void Negocio::mostrarClientes() const {
    for (int i = 0; i < clientes.size(); i++) {
        clientes[i]->mostrarInfoCliente();
    }
}

/*
* En esta función primeramente se pide al usuario que de un número de licencia, esta info se guarda en la variable
* numeroLicencia y depués empieza la búsqueda del cliente cuando se crea un pointer a un objeto tipo Cliente y se 
* inicializa como un null pointer, lo que significa que inicialmente, no apunta a ningún objeto tipo Cliente, esto 
* es importante porque hasta que se encuentre al cliente con el numero de licencia inputeado, no hay ningún cliente
* al que se adjudique el alquiler. En el ciclo for se itera cliente como una variable (aunque en realidad es un 
* pointer a un objeto tipo Cliente). Se podría decir que simplemente es un alias. Otra cosa importante a denotar es 
* que se agrega la palabra auto para darle al compilador la tarea de deducir el tipo de la variable (que ya dijimos
* que es un pointer a un objeto tipo Cliente) y el ampersand se agrega para decir que el paso es por referencia, y 
* que básicamente no haga una copia. EL ciclo itera sobre el vector de clientes y la condición es que si esta variable
* cliente al obtener su número de licencia, es igual a la que introdujo el usuario, entonces el clienteAlquilando es
* igual al pointer de Cliente que está en la posición en la que encontró el match, si no, entonces el clienteAlquilando
* sigue siendo un null pointer y se avisa que no se encontró al cliente. En cuanto al vehículo que se alquilará, es 
* bastante similar. Se inicializa una variable que es el índice del vehículo, al cual le pongo 3 condiciones para alqui-
* lar, que son 1. El índice debe ser 0 o positivo, 2. El índice debe ser menor que el tamaño del vector de vehiculos y 
* 3. El vehículo debe estar disponible. Si no cumple esas 3 condiciones, entonces no te dejará alquilar el vehículo.
* fLuego, te pregunta la fecha de alquilado y la fecha de de devolución y la guarda en sus respectivas variables. Y
* para finalizar, pone el estatus del vehículo como no disponible y guarda toda la información anterior en el vector de
* alquileres que contiene todos los alquileres activos.
*/

void Negocio::alquilarVehiculo() {
    string numeroLicencia;
    cout << "Ingresa el numero de licencia del cliente: ";
    cin >> numeroLicencia;

    Cliente* clienteAlquilando = nullptr;
    for (auto& cliente : clientes) {
        if (cliente->getNumeroLicencia() == numeroLicencia) {
            clienteAlquilando = cliente;
            break;
        }
    }

    if (clienteAlquilando == nullptr) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    int indiceVehiculo;
    cout << "Ingresa el indice del vehiculo a alquilar (Ten en cuenta que el primer vehiculo tiene indice 0): ";
    cin >> indiceVehiculo;

    if (indiceVehiculo < 0 || indiceVehiculo >= vehiculos.size() || !vehiculos[indiceVehiculo]->getDisponibilidad()) {
        cout << "Vehiculo invalido o no disponible.\n";
        return;
    }

    string fechaAlquiler, fechaDevolucion;
    cout << "Ingresa la fecha de alquiler (AAAA-MM-DD): ";
    cin >> fechaAlquiler;
    cout << "Ingresa la fecha de devolucion (AAAA-MM-DD): ";
    cin >> fechaDevolucion;

    vehiculos[indiceVehiculo]->setDisponibilidad(false);
    alquileres.push_back(new Alquiler(vehiculos[indiceVehiculo], clienteAlquilando, fechaAlquiler, fechaDevolucion));
}

/*
* Esta función pregunta el índice del alquier en el vector alquileres (tienes que tener muy buena memoria para esto btw)
* y pongo dos condiciones de que si el índice que inputeas es negativo y mayor o igual al tamaño del vector de alquileres,
* entonces manda un mensaje de invalidez. En caso contrario, si el índice cumple con las concidiones, primero, pone la 
* disponibilidad del vehículo comp true, depués, te muestra la información del alquiler, con el estatus actualizado, pos-
* teriormente, libera memoria y borra el pointer tipo Alquiler que está en ese indice del vector de alquileres usando la
* función erase donde se mete cómo parámetro la suma del inicio del vector (la posición 0) y el índice, lo cual hará que 
* llegue hasta la posición del índice (si fuera índiceAlquler = 2, entonces se desplaza 8 bytes) y te manda un mensaje de
* confirmación que el vehículo indeed, se devolvió.
*/

void Negocio::devolverVehiculo() {
    int indiceAlquiler;
    cout << "Ingresa el indice del alquiler a devolver: ";
    cin >> indiceAlquiler;

    if (indiceAlquiler < 0 || indiceAlquiler >= alquileres.size()) {
        cout << "Indice de alquiler invalido.\n";
        return;
    }

    alquileres[indiceAlquiler]->getVehiculo()->setDisponibilidad(true);
    alquileres[indiceAlquiler]->mostrarInfoAlquiler();
    delete alquileres[indiceAlquiler];
    alquileres.erase(alquileres.begin() + indiceAlquiler);
    cout << "Vehiculo devuelto.\n";
}

/*
* Esta función como las demás funciones que muestran cosas, itera sobre el vector de alquileres y muestra la 
* información contenida en cada posición. 
*/

void Negocio::mostrarAlquileres() const {
    for (int i = 0; i < alquileres.size(); i++) {
        alquileres[i]->mostrarInfoAlquiler();
    }
}

/*
* El destructor es importante porque todos los objetos se crearon con dinámicamente, por lo que se tiene
* que liberar la memoria que ocupan dichos objetos usando la palabra delete. Dentro hay 3 ciclos for que
* recorren los vectores correspondienetes donde la palabra en singular (vehiculo, cliente, alquiler) es 
* una copia de cada elemento.
*/

Negocio::~Negocio() {
    for (auto vehiculo : vehiculos) {
        delete vehiculo;
    }
    for (auto cliente : clientes) {
        delete cliente;
    }
    for (auto alquiler : alquileres) {
        delete alquiler;
    }
}

#endif

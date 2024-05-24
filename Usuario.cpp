// Incluye el archivo de encabezado "Usuario.h", que contiene la definición de la clase Usuario.
#include "Usuario.h"

// Definición de métodos
void Usuario::setUserName(std::string nombre)
{
    this->username = nombre;
}

std::string Usuario::getUserName()const
{
    return this->username;
}

void Usuario::setEmail(std::string email)
{
    this->email = email;
}

std::string Usuario::getEmail()const
{
    return this->email;
}

void Usuario::setClave(std::string clave)
{
    this->clave = clave;
}

std::string Usuario::getClave()const
{
    return this->clave;
}

/* Este método recibe un puntero a un objeto PlayList como argumento.
this->ptrPlayList se refiere al puntero miembro ptrPlayList de la instancia 
actual de la clase Usuario, que apunta a un vector dinámico de punteros a PlayList.
push_back(lista) agrega el puntero lista al final del vector ptrPlayList. 
Esto significa que el vector ptrPlayList ahora apunta a una lista de reproducción 
adicional, la cual es proporcionada como argumento al método.*/

void Usuario::crearPlayList(PlayList* lista)
{
    this->ptrPlayList->push_back(lista);
}

/*Este método devuelve un puntero al vector ptrPlayList del objeto Usuario.
this->ptrPlayList es el puntero miembro ptrPlayList de la instancia actual de 
la clase Usuario, que apunta a un vector dinámico de punteros a PlayList.
Al devolver this->ptrPlayList, se proporciona acceso al vector que contiene 
las listas de reproducción del usuario.*/

std::vector<PlayList*>* Usuario::mostrarPlayList()const
{
    return this->ptrPlayList;
}

// Constructor
Usuario::Usuario(std::string user)
{

    this->username = user;
    this->ptrPlayList = new std::vector<PlayList*>(3);
}

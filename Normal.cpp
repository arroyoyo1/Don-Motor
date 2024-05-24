// Incluye el archivo de Normal.h, que contiene la declaración de la clase Normal.
#include "Normal.h"

// 
void Normal::suscripcion(std::string email, std::string clave)
{
    this->email = email;
    this->clave = clave;
}

Normal::Normal(std::string user):Usuario(user)
{

}


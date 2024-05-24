// Incluye la defincion de la clase Premium
#include "Premium.h"

// IMplementación del método y constructor
void Premium::suscripcion(std::string email, std::string clave)
{
    this->email = email;
    this->clave = clave;
    /*Esta línea redimensiona el vector de punteros a PlayList (ptrPlayList) a un tamaño de 10. Esto garantiza que
    un usuario premium tenga espacio para 10 listas de reproducción.*/
    this->ptrPlayList->resize(10);
}

// Constructor
Premium::Premium(std::string user):Usuario(user)
{

}

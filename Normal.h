// Te aseguras que el contenido del archivo solo se incluya una vez durante la compilación.
#ifndef NORMAL_H
#define NORMAL_H
#include "Usuario.h"

// Define una clase llamada Normal que hereda públicamente de la clase Usuario.
class Normal: public Usuario
{
public:
    // Constructor y mpetodos
    Normal(std::string);
    /*La adición de virtual y override en esta línea tiene que ver con la herencia y la 
    capacidad de sobrescribir funciones en clases hijas. */
    virtual void suscripcion(std::string,std::string) override;
    int getMaxPlaylists();
};

#endif // NORMAL_H

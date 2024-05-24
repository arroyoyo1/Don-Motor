#ifndef PREMIUM_H
#define PREMIUM_H
// Incluye el archivo Usuario.h ya que es herencia de esa clase
#include "Usuario.h"

class Premium:public Usuario
{
public:
    // Constructor
    Premium(std::string);
    // Métodos
    /*La adición de virtual y override en esta línea tiene que ver con la herencia y la 
    capacidad de sobrescribir funciones en clases hijas.*/
    virtual void suscripcion(std::string,std::string) override;
    void setCantidadListas(int);
    int getCantidadListas()const;

private:
    // Atributo
    int cantidadListas = 10;
};

#endif // PREMIUM_H


//Usuario* ptrUser1 = new Usuario("mau"); error pq usuario es una clase abstracta

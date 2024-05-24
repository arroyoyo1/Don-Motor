// Incluye la implementación de la clase del archivo .h
#include "Artista.h"

// Se implementan los setters y getters
std::string Artista::getNombre()const
{
    return this->nombre;
}

void Artista::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

char Artista::getSexo()const{
    return this->sexo;
}

void Artista::setSexo(char sexo)
{
    if(sexo == 'm' || sexo == 'f')
        this->sexo = sexo;
}

// También los constructores
Artista::Artista(std::string nombre)
{
    this->nombre = nombre;
}

Artista::Artista(std::string nombre, char sexo)
{
    this->nombre = nombre;
    this->setSexo(sexo);
}







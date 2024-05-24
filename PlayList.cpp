// Incluye la información de la implementación de la clase PLaylist
#include "PlayList.h"

// Implementación de métodos
void PlayList::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

std::string PlayList::getNombre()const
{
    return this->nombre;
}

// Este método agrega una canción a la lista de reproducción. 
// Toma un puntero a un objeto Cancion y lo añade al vector arrayCancion.
void PlayList::setCancion(Cancion* ptrObj)
{
    this->arrayCancion->push_back(ptrObj);
}

// Este método devuelve un puntero al vector de canciones.
std::vector<Cancion*>* PlayList::getCanciones()const
{
    return this->arrayCancion;
}

PlayList::PlayList(std::string nombre)
{
    this->arrayCancion = new std::vector<Cancion*>;
    this->nombre = nombre;
}

int PlayList::getCantCanciones()const
{
    return this->arrayCancion->size();
}

bool PlayList::borrarCancion(std::string tituloCancion)
{
    /*Se declara e inicializa una variable booleana validar a false. 
    Esta variable se utilizará para indicar si la canción fue encontrada y eliminada.*/
    bool validar = false;
    /*Este ciclo for recorre el vector arrayCancion desde el primer elemento hasta el último
    y compara el título de la canción actual con el título buscado.*/
    for(size_t i=0;i<this->arrayCancion->size();i++)
    {
        if(this->arrayCancion->at(i)->getTitulo()==tituloCancion)
        {
            //Borra cancion (todavía no sale bien)
            // this->arrayCancion->at(i)->erase(i);
            validar = true;
        }
    }
    return validar;
}

std::string PlayList::reproducir(std::string titulo)
{

    std::string cadena = "Reproduciendo ";
    /*Este ciclo for también recorre el vector arrayCancion desde el primer elemento hasta el último
    y compara el título de la canción actual con el título buscado.*/
    for(size_t i=0;i<this->arrayCancion->size();i++)
    {
        if(this->arrayCancion->at(i)->getTitulo()==titulo)
        {
            // Si se encuentra una canción cuyo título coincide con titulo, 
            // se añade el título de la canción al string, seguido de un salto de línea.
            cadena += arrayCancion->at(i)->getTitulo() + "\n";
        }
    }
    // Finalmente, se retorna el string que contiene el mensaje.
    return cadena;
}







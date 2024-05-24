/* Te aseguras que el contenido del archivo "PlayList.h" solo se incluya una vez durante la compilación. 
También incluye el archivo Cancion.h ya que está asociado (como lo muestra el diagrama UML).*/
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Cancion.h"

// Definición de la clase 
class PlayList
{
    // Métodos
public:
    void setNombre(std::string);
    std::string getNombre()const;
    int getCantCanciones()const;

    /*Este método toma como argumento un puntero a un objeto Cancion.
    Dentro de la implementación del método, este puntero (cancion) será utilizado para agregar la canción al 
    vector de canciones (arrayCancion) que pertenece a la lista de reproducción (PlayList).*/

    void setCancion(Cancion*);

    /*Se Indica que este método puede ser sobrescrito por clases derivadas.
    Contiene un puntero a un vector que contiene punteros a objetos Cancion, y
    devuelve un puntero al vector que contiene punteros a las canciones de la lista de reproducción.*/

    virtual std::vector<Cancion*>* getCanciones()const;
    bool borrarCancion(std::string);
    std::string reproducir(std::string);
     PlayList(std::string);
    ~PlayList()
     {
        delete this->arrayCancion;
    }
private:
    std::string nombre;
    int cantCanciones = 0;
    std::vector<Cancion*>* arrayCancion;
};

#endif // PLAYLIST_H

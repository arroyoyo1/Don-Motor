#ifndef CANCION_H
#define CANCION_H
// Se incluye el archivo de cabecera Artista.h para poder utilizar la clase Artista en la definición de la clase Cancion
// y otras bibliotecas necesarias para el correcto funcionamiento
#include "Artista.h"
#include <ctime>
#include <vector>

// Se declara la clase Cancion con su conjunto de atributos y métodos públicos y privados.
class Cancion
{
public:
    void setTitulo(std::string);
    std::string getTitulo()const;
    void setDuracion(std::time_t);
    std::time_t getDuracion() const;
    // Este método establece el artista asociado a una canción, tomando como argumento un puntero a un objeto de la clase Artista.
    void setArtista(Artista*);
    /*Este método devuelve un puntero constante a un vector que contiene punteros a objetos de la clase Artista, 
    permitiendo acceder a la lista de artistas asociados a una canción sin poder modificar el contenido del vector.*/
    std::vector<Artista*>* getArtistas()const;
    void setAlbum(std::string);
    std::string getAlbum()const;
    void setAnio(std::string);
    std::string getAnio()const;
    bool existeArtista(std::string)const;

    // Muchos constructores para diferentes tipos de inicialización de objetos Cancion
    Cancion();
    Cancion(std::string);
    Cancion(std::string,Artista*);
    Cancion(std::string, Artista*,std::string);
    Cancion(std::string, Artista*,std::string,std::string,std::time_t);
    ~Cancion()
    {
        delete this->ptrArtista;
    }
private:
    std::string titulo;
    std::time_t duracion;
    std::vector<Artista*>* ptrArtista;  //Apunta a un array de objetos tipo Artista
    std::string album;
    std::string anio;

};

#endif // CANCION_H

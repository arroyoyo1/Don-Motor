// Se incluye el archivo de cabecera Cancion.h
#include "Cancion.h"
#include <algorithm>

// Implementación de métodos
void Cancion::setAlbum(std::string album)
{
    this->album = album;
}

std::string Cancion::getAlbum() const
{
    return this->album;
}

void Cancion::setAnio(std::string anio)
{
    /// Falta validar con expresiones regulares
    this->anio = anio;
}

std::string Cancion::getAnio()const
{
    return this->anio;
}

void Cancion::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

std::string Cancion::getTitulo()const
{
    return this->titulo;
}

/*Este método recibe como argumento un puntero a un objeto de la clase Artista y lo agrega al final del vector 
de artistas asociados a la canción. Para agregar el artista al vector, se utiliza el método push_back() del vector,
que agrega el puntero del artista al final del vector.*/
void Cancion::setArtista(Artista* ptr)
{
    this->ptrArtista->push_back(ptr);
    //std::sort(this->ptrArtista->begin()->getNombre(),this->ptrArtista->end()->getNombre());

}

bool Cancion::existeArtista(std::string nombre)const
{
    bool validar = false;
    // falta implementación lógica del método
    return validar;
}
/*Este método devuelve un puntero a un vector que contiene punteros a objetos de la clase Artista.
Cuando se llama a este método, devuelve la dirección de memoria donde comienza el vector de artistas asociados a la canción.
Esto permite que el código que llama a este método acceda a la lista de artistas asociados a la canción y trabaje con ella, 
pero no puede modificar el contenido del vector.*/
std::vector<Artista*>* Cancion::getArtistas()const
{
    return this->ptrArtista;
}

void Cancion::setDuracion(std::time_t duracion)
{
    this->duracion = duracion;
}

std::time_t Cancion::getDuracion()const
{
    return this->duracion;
}

// Implementación de constructores
Cancion::Cancion()
{
    this->ptrArtista = new std::vector<Artista*>;
}

Cancion::Cancion(std::string titulo)
{
    this->ptrArtista = new std::vector<Artista*>;
    this->titulo = titulo;
}

Cancion::Cancion(std::string titulo, Artista * ptr)
{
    this->ptrArtista = new std::vector<Artista*>;
    this->titulo = titulo;
    this->setArtista(ptr);
}

Cancion::Cancion(std::string titulo , Artista * ptr, std::string album)
{
    this->ptrArtista = new std::vector<Artista*>;
    this->titulo = titulo;
    this->setArtista(ptr);
    this->album = album;
}

Cancion::Cancion(std::string titulo, Artista * ptr, std::string album, std::string anio, time_t duracion)
{
    this->ptrArtista = new std::vector<Artista*>;
    this->setTitulo(titulo);
    this->setArtista(ptr);
    this->setAlbum(album);
    this->setAnio(anio);
    this->setDuracion(duracion);
}









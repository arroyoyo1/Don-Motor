#ifndef ARTISTA_H
#define ARTISTA_H
// Se incluye la biblioteca string para poder utilizar el tipo de dato string (unexpected right?).
#include <string>

// Se declara la clase Artista con su conjunto de métodos públicos y constructores privados.
class Artista{
public:
    // Métodos públicos (setters y getters)
    std::string getNombre()const;
    void setNombre(std::string);
    char getSexo()const;
    void setSexo(char);

    /*Se definen dos constructores para permitir la creación de objetos Artista de diferentes maneras. 
    Uno de ellos solo especifica el nombre del artista, mientras que el otro especifica tanto el nombre 
    como el sexo del artista.*/
    Artista(std::string);
    Artista(std::string,char);
private:
    // Atributos privados del artista
    std::string nombre = "n/a";
    char sexo = 'm';
};

#endif // ARTISTA_H

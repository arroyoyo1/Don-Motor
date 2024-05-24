#ifndef USUARIO_H
#define USUARIO_H
// Incluye el archivo de encabezado "PlayList.h", lo que sugiere que la clase Usuario utiliza la clase PlayList.
#include "PlayList.h"

// Se inicia la definición de la clase Usuario
class Usuario
{
    // Métodos de la clase
public:
    std::string getUserName()const;
    std::string getEmail()const;
    std::string getClave()const;
    std::vector<PlayList*>* mostrarPlayList()const;
    void borrarPlaylist(PlayList*);
protected:
    void setUserName(std::string);
    void setEmail(std::string);
    void setClave(std::string);
    void crearPlayList(PlayList*);
    virtual void suscripcion(std::string,std::string)=0;
    Usuario(std::string);
    ~Usuario()
    {
        delete ptrPlayList;
    }
    // Atributos de la clase
protected:
    std::vector<PlayList*>* ptrPlayList;
    std::string email = "n/a";
    std::string clave = "n/a";
private:
    std::string username = "n/a";

};



#endif // USUARIO_H

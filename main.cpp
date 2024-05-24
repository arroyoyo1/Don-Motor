// Incluye los archivos necesarios
#include <iostream>
#include "Normal.h"
#include "Premium.h"
#include "Usuario.h"
#include "Cancion.h"
#include "Artista.h"

using namespace std;

int main()
{
    // Se crean tres objetos Artista dinámicamente
    Artista* ptrArtista1 = new Artista("Gustavo Cerati",'m');
    Artista* ptrArtista2 = new Artista("Luis Alberto Spinetta",'m');
    Artista* ptrArtista3 = new Artista("Dua Lipa",'f');
    // Se imprime el nombre y sexo de ptrArtista2
    cout << "Artista: " << ptrArtista2->getNombre() << " ," << ptrArtista2->getSexo() << endl;
    // Crear canciones
    Cancion* ptrCancion1 = new Cancion("Las Habladurias del Mundo",ptrArtista2,"Artaud");
    Cancion* ptrCancion2 = new Cancion("La Ciudad de la Furia",ptrArtista1,"Doble Vida");
    Cancion* ptrCancion3 = new Cancion("Houdini",ptrArtista3,"Radical Optimism");
    // Se obtienen los punteros a los vectores de artistas para cada canción
    vector<Artista*>* ptrArtistasCancion1 = ptrCancion1->getArtistas();
    vector<Artista*>* ptrArtistasCancion2 = ptrCancion2->getArtistas();
    vector<Artista*>* ptrArtistasCancion3 = ptrCancion3->getArtistas();
    // Se imprime el título de la primera canción y el nombre de su artista (aunque realmente podrían ser varios)
    cout << "-- Cancion --" << endl;
    cout << "Titulo: " << ptrCancion1->getTitulo() << endl;
    cout << ">> Artistas:" << endl;
    for(Artista* artista:*ptrArtistasCancion1){
        cout << artista->getNombre() << endl;
    }
    // Se crean dos listas de reproducción y se añaden canciones a ellas
    PlayList* ptrLista1 = new PlayList("Rock Latinoamericano");
    PlayList* ptrLista2 = new PlayList("Electro Pop");
    // Se imprime el nombre de la primera lista de reproducción y los detalles de cada canción en ella, incluyendo título, álbum y artistas
    ptrLista1->setCancion(ptrCancion1);
    ptrLista1->setCancion(ptrCancion2);
    ptrLista2->setCancion(ptrCancion3);
    cout << ">>>>> Lista: " << ptrLista1->getNombre() << endl;
    for(Cancion* cancion:*ptrLista1->getCanciones())
    {
        cout << "-- Cancion --" << endl;
        cout << "Titulo: " << cancion->getTitulo() << endl;
        cout << "Album: " << cancion->getAlbum() << endl;
        cout << "Artistas: " << endl;
        for(Artista* artista:*cancion->getArtistas())
        {
            cout << "Nombre: " << artista->getNombre() << " Sexo: " << artista->getSexo() << endl;
        }
    }

    // Se reproduce una canción específica de la lista de reproducción y se imprime el resultado
    std::string cancion_play = ptrLista1->reproducir("La Ciudad de la Furia");
    cout << "Play>>> " << cancion_play << endl;

    // Se crean dos usuarios, uno normal y uno premium, y se imprimen sus nombre
    Normal* ptrUser1 = new Normal("Mauricio Arroyo");
    Premium* ptrUser2 = new Premium("Sofia Garza");

    cout << "Usuario: " << ptrUser1->getUserName() << endl;
    cout << "Usuario: " << ptrUser2->getUserName() << endl;

    // Se libera la memoria asignada dinámicamente para los usuarios, listas de reproducción, vectores de artistas y canciones.
    delete ptrUser2;
    delete ptrUser1;
    delete ptrLista2;
    delete ptrLista1;
    delete ptrArtistasCancion3;
    delete ptrArtistasCancion2;
    delete ptrArtistasCancion1;
    delete ptrCancion3;
    delete ptrCancion2;
    delete ptrCancion1;
    delete ptrArtista1;
    delete ptrArtista2;
    delete ptrArtista3;
    return 0;
}

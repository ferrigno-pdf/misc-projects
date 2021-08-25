#ifndef Pelicula_h
#define Pelicula_h
#include "Video.h"

class Pelicula: public Video{
  // hereda de video y no tiene atributos porque son los mismos que video
  public:
  // constructores
    Pelicula();
    Pelicula(string, double, string, int, string);
    // esta vez se desarrolla mostrar dirigida hacia peliculas
    void mostrar();
};
// constructor vacio
Pelicula::Pelicula():Video() {

}

// constructor con argumentos, no se desarrolla nada adentro de las llaves porque ya se puso en video
Pelicula::Pelicula(string id, double calificacion, string nombre, int duracion, string genero):Video(id, calificacion, nombre, duracion, genero) {

}
// mostrar depiendiendo a la clase, polimorfismo
// si mostrar se llama con un episodio, el programa responde de acuerdo al objeto
void Pelicula::mostrar() {
  cout << "Nombre de pelicula: " << nombre << endl;
  cout << "ID: " << id << endl;
  cout << "Calificacion: " << calificacion << endl;
  cout << "Duracion: " << duracion << endl;
  cout << "Genero: " << genero << endl;
  cout << "\n" <<endl;

}
#endif
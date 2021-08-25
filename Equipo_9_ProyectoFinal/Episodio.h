#ifndef Episodio_h
#define Episodio_h

#include "Video.h"
#include "Serie.h"
// clase que hereda de video
class Episodio:public Video {
  private:
    string temporada, numEpisodio;
    // contiene composicion de la clase Serie
    // el nombre de serie
    Serie nomSerie;
    
  public:
    // constructores
    Episodio();
    Episodio(string, double, string, int, string, string, string, Serie);
    // getters y setters
    string getTemporada();
    void setTemporada(string);

    string getNumEpisodio();
    void setNumEpisodio(string);

    Serie getSerie();
    void setSerie(Serie);
    // mostrar como el de video pero responde de acuerdo al objeto
    void mostrar();
};
// constructor vacio
Episodio::Episodio():Video(){
  temporada = "";
  numEpisodio = "";
  nomSerie = Serie();
}
// constructor con argumentos
Episodio::Episodio(string Id, double calificacion, string nombre, int duracion, string genero, string temporada, string episodio, Serie nS):Video(Id, calificacion, nombre, duracion, genero){
  this -> temporada = temporada;
  numEpisodio = episodio;
  nomSerie = nS;

}
// mostrar de episodio
void Episodio::mostrar(){
  cout << "Numero de temporada: " << temporada << endl;
  cout << "Nombre de Episodio: " << nombre << endl;
  cout << "ID: " << id << endl;
  cout << "Calificacion: " << calificacion << endl;
  cout << "Duracion: " << duracion << endl;
  cout << "Genero: " << genero << endl;
  cout << '\n' <<endl;

}
// setters y getters
string Episodio::getTemporada(){
  return temporada;
}

void Episodio::setTemporada(string x){
  temporada = x;
}

string Episodio::getNumEpisodio(){
  return numEpisodio;
}

void Episodio::setNumEpisodio(string j){
  numEpisodio = j;
}

Serie Episodio::getSerie(){
  return nomSerie;
}

void Episodio::setSerie(Serie x){
  nomSerie = x;
}


#endif
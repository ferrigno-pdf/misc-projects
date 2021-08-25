#ifndef Video_h
#define Video_h


class Video{
  protected:
    // atributos protegidos porque se heredan
    string id;
    double calificacion;
    string nombre;
    int duracion;
    string genero;
  public:
    // constructores
    Video();
    Video(string, double, string, int, string);
    // getters
    string getId();
    double getCalificacion();
    string getNombre();
    int getDuracion();
    string getGenero();
    // setters
    void setId(string);
    void setCalificacion(double);
    void setGenero(string);
    void setDuracion(int);
    void setNombre(string);
    
    // clase abstracta de la cual heredan episodio y pelicula
    virtual void mostrar()=0;
};

// constructor vacio
Video::Video(){
  id = "";
  calificacion = 0;
  nombre = "";
  genero = "";
  duracion = 0;
}
// constructor con argumentos
Video::Video(string id, double calificacion, string nombre, int duracion, string genero){

  this-> id = id;
  this-> calificacion = calificacion;
  this-> nombre = nombre;
  this-> duracion = duracion;
  this-> genero = genero;

}

// getters y setters
string Video::getId(){
  return id;
}

double Video::getCalificacion(){
  return calificacion;
}

string Video::getNombre(){
  return nombre;
}

int Video::getDuracion(){
  return duracion;
}

string Video::getGenero(){
  return genero;
}


void Video::setId(string x){
  id = x;
}

void Video::setCalificacion(double x){
  calificacion = x;
}

void Video::setGenero(string x){
  genero = x;
}

void Video::setDuracion(int x){
  duracion = x;
}

void Video::setNombre(string x){
  nombre = x;
}

#endif
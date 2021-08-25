#ifndef Serie_h
#define Serie_h

// clase que no hereda de ningun lado, que sera parte de episodio
class Serie {
  private:
  // atributos de la serie
    int cantidadEpisodios;
    string id;
    string nombre;
    


  public:
  // constructores
    Serie();
    Serie(string str, int, string);
  // getters y setters
    void setNombre(string);
    string getNombre();
    int getCantidadEpisodio();
    void setCantidadEpisodio(int);
    void cantidadEpisodiosmasuno();

    void setId(string);
    string getId();
    // mostrar para imprimir la serie
    void mostrar();
};
// constructor vacio
Serie::Serie() {
  cantidadEpisodios = 0;
  nombre = "";
  id = "";
  
}
// constructor con argumentos
Serie::Serie(string str, int ce, string iidd) {
  nombre = str;
  cantidadEpisodios = ce;
  id = iidd;
  
}
// muestra la serie con sus atributos
void Serie::mostrar(){
  cout << "Nombre de la serie: " << nombre << endl;
  cout << "ID: " << id << endl;
  cout << "Cantidad Episodios: " << cantidadEpisodios <<endl;
  cout << "\n" <<endl;
}

// getters y setters
void Serie::setCantidadEpisodio(int x){
  cantidadEpisodios = x;
}

int Serie::getCantidadEpisodio(){
  return cantidadEpisodios;
}

void Serie::setId(string x){
  id = x;
}
string Serie::getId(){
  return id;
}

void Serie::setNombre(string nombre) {
  this-> nombre = nombre;
}

string Serie::getNombre() {
  return nombre;
}
// metodo para agregarle 1 a la cantidad de episodios
void Serie::cantidadEpisodiosmasuno(){
  cantidadEpisodios++;
}

#endif
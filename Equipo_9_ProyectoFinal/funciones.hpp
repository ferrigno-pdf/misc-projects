//Proyecto Final

//A01721371 Gerardo Carlos Ferrigno Califa

//A01194283 Marcelo Hernández Almada


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"


// funcion para leer los archivos datosVideos y datosSeries
// toma referencias para que los numeros vayan incrementando conforme se corre el codigo
void leerArchivo(int &cantidadVideos, int &cantidadSeries, Video *arrVideo[], Serie *arrSeries){
  string idArch; 
  string nombreSerieArch;
  char eleccion;
  string generoArch;
  double calificacionArch;
  string tituloSerieArch;
  string numEpisodioArch, numTemporadaArch;
  string nombreVideoArch;
  string idVideos;
  int duracionArch;
  int cantidadPeliculas = 0;
  int cantidadEpisodios = 0;
  
  

  // archivo de series
  ifstream archSeries("datosSeries.txt");
  // en un arreglo de series se dan de alta las series en el archivo, con todos los atributos en la posicion cantidad series, que va incrementando por renglon
  while(archSeries >> idArch >> nombreSerieArch) {
    arrSeries[cantidadSeries] =  Serie(nombreSerieArch, 0, idArch);
    cantidadSeries++;
  }
  // ahora se lee el archivo de videos
  ifstream archVideos("datosVideos.txt");
  while(archVideos >> eleccion){
    // si es p, como lo dice el archivo, entonces es una pelicula, crea un objeto de pelicula si este es el caso.
    if (eleccion == 'p'){
      archVideos >> idVideos >> nombreVideoArch >> generoArch >> duracionArch >> calificacionArch;
      // crea objeto dinamico con la informacion del archivo
      arrVideo[cantidadVideos] = new Pelicula(idVideos, calificacionArch, nombreVideoArch, duracionArch, generoArch);
      cantidadPeliculas++;
    }
    if (eleccion == 'e'){ 
      // si es un episodio carga la info a estos variables
      archVideos >> idVideos >> nombreVideoArch >> generoArch >> duracionArch >> calificacionArch >> tituloSerieArch >> numEpisodioArch >> numTemporadaArch; 
     
      // ciclo for que termina hasta la cantidad de series en el arreglo de series
      for(int i = 0; i < cantidadSeries; i++){
        // si el nombre de la serie en el arreglo es el mismo que cualquiera en el archivo, se crea un objeto dinamico de episodio en el arreglo de videos.
        if (arrSeries[i].getNombre() == tituloSerieArch){
          arrVideo[cantidadVideos] = new Episodio(idVideos, calificacionArch, nombreVideoArch, duracionArch, generoArch, numTemporadaArch, numEpisodioArch, arrSeries[i]);
          // se le agrega uno al atributo cantidad de episodios en serie
          arrSeries[i].cantidadEpisodiosmasuno();
        }
      }
      cantidadEpisodios++;
    } 
    cantidadVideos++;
  }
  // se le agrega uno a cada cantidad para imprimir la siguiente informacion
  cout << "\n" <<endl;
  cout << "Cantidad Videos: " << cantidadVideos <<endl;
  cout << "Cantidad Episodios: " << cantidadEpisodios << endl;
  cout <<  "Cantidad Pelicalas: " << cantidadPeliculas << endl;
  cout << "Cantidad Series: " << cantidadSeries << endl;
  cout << "\n" <<endl;
}


void mostrarSeries(int cantidadSeries, Serie *arrSeries){
  // muestra las series que hay en el arreglo de series

  for (int i=0; i < cantidadSeries; i++) {
    arrSeries[i].mostrar();
  }

}

void mostrarTodo(int cantidadVideos, Video *arrVideo[]){
  // muestra todos los videos en el arreglo
   for (int i=0; i < cantidadVideos; i++) {

    if (typeid(arrVideo[i]) == typeid(Episodio)){
      Episodio *miEpisodio = (Episodio *)arrVideo[i];
      miEpisodio -> getSerie().mostrar();
      arrVideo[i] -> mostrar();
    }
    
    if (typeid(*arrVideo[i]) == typeid(Pelicula)){
      Pelicula *miPelicula = (Pelicula *)arrVideo[i];
      arrVideo[i] -> mostrar();
    }
    
  }
}

void mostrarPeliculas(int cantidadVideos, Video *arrVideo[]){
  // muestra todas las peliculas en el arreglo de videos
  for (int i=0; i < cantidadVideos; i++) {
    // si el objeto en el arreglo de videos es una pelicula, la muestra
    if (typeid(*arrVideo[i]) == typeid(Pelicula)){
      Pelicula *miPelicula = (Pelicula *)arrVideo[i];
      arrVideo[i] -> mostrar(); 
    }
  }
}

void mostrarVideosCal(double calificacion, Video *arrVideo[], int cantidadVideos){
  
  int i, cont = 0;
  // ciclo hasta la cantidad de videos disponibles
  for (i=0; i < cantidadVideos; i++) {
  // si la calificacion del video es la misma que la que da el usuario, se imprime
    if (arrVideo[i] -> getCalificacion() == calificacion) {
      arrVideo[i] -> mostrar();
      cont++;
    }
    
  }
  // el contador sirve para verificar cuantos videos se encontraron, si fueron 0, entonces se imprime el mensaje
  if (cont == 0) {
      cout << "No se encontraron videos con calificacion " << calificacion << '\n';
    }
  else {
    // si no, dice cuantos videos se encontraron
    cout << "Se encontraron " << cont << " videos" << '\n' << endl;
  }
  
  
}
// muestra videos de acuerdo al genero que pide el usuario
void mostrarVideosGen(string genero, Video *arrVideo[], int cantidadVideos){
  
  int i, cont = 0;
  // mismo ciclo que la funcion pasada
  for (i=0; i < cantidadVideos; i++) {
  // ahora en vez de verificar la calificacion, verifica el genero
    if (arrVideo[i] -> getGenero() == genero) {
      arrVideo[i] -> mostrar();
      cont++;
    }
  }
// sucede lo mismo que en el metodo pasado pero con genero
  if (cont == 0) {
      cout << "No se encontraron videos de genero " << genero << '\n';
    }
  else {
    cout << "Se encontraron " << cont << " videos" << '\n' << endl;
  }
  
}
// mustra episodios con su calificacion
void mostrarEpCal(string nombreSerie, Video *arrVideo[], int cantidadVideos){
  
  int i, cont = 0;
  // mismo ciclo pero ahora adentro de este verifica el tipo en el arreglo de videos
  for (i=0; i < cantidadVideos; i++) {
    // si es un episodio crea un apuntador de tipo episodio para poder accesar sus metodos
    if (typeid(*arrVideo[i]) == typeid(Episodio)){
      Episodio *miEpisodio = (Episodio *)arrVideo[i];
      // este apunta a la serie y luego al nombre de esta y verifica que sea el mismo que el que pone el usuario
      if (miEpisodio -> getSerie().getNombre() == nombreSerie){
        // mustra la serie
        arrVideo[i] -> mostrar();
        cont++;
      }
    }
  }
  // responde si no se encuentra nada
  if (cont == 0) {
      cout << "No se encontro nada sobre la serie " << nombreSerie << '\n';
    }
  else {
    // se muestran la cantidad de episodios
    cout << "Se encontraron " << cont << " episodios" << '\n' << endl;
  } 
  
}
// mustra peliculas con cierta calificacion
void mostrarPelCal(double calificacion, Video *arrVideo[], int cantidadVideos){
  int i, cont = 0;
  // mismo ciclo con la cantidad de videos
  for (i=0; i < cantidadVideos; i++) {
    // si es de tipo pelicula
    if (typeid(*arrVideo[i]) == typeid(Pelicula)) {
      // y si la calificacion es la misma que la que proporciona el usuario
      if (arrVideo[i] -> getCalificacion() == calificacion) {
      // se muestra la pelicula 
      arrVideo[i] -> mostrar();
      cont++;
      }  
    }
  }
  // si no hay peliculas con la calificacion del usuario, se despliega el mensaje
  if (cont == 0) {
      cout << "No se encontro ninguna pelicula con calificacion " << calificacion << '\n';
    }
  else {
    // muestra la cantidad de peliculas con la calificacion que ingreso el usuario
    cout << "Se encontraron " << cont << " peliculas" << endl;
  } 
  
}


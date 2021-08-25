#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Pelicula.h"
#include "Episodio.h"
#include "funciones.hpp"


int main() {
  // archivo 1 
  int cantidadSeries = 0;
  string nombreSerieArch;
  Serie arrSeries[100];

  // archivo 2
  string idVideos; 
  int cantidadVideos = 0;
  Video *arrVideo[100];
  
  //menu
  // opcion del usuario
  int op = 0;
  //Case 4 y 7
  // calificacion que se le va a pedir al usuario
  double cali;
  //Case 5
  // genero que se le pide al usuario
  string genero;
  //Case 6
  // eleccion de serie
  string serieel;

  

  while (op != 8){//loop del menu principal
    //Mensaje del opciones
    cout << " 1: Cargar archivo de datos: \n 2: Mostrar la lista de películas: \n 3: Mostrar la lista de series: \n 4: Mostrar los videos en general con una cierta calificación: \n 5: Mostrar los videos en general de un cierto género: \n 6: Mostrar los episodios de una determinada serie con sus calificaciones: \n 7: Mostrar las películas con cierta calificación: \n 8: Salir\n" << endl;
    cin >> op;
    if (cin.fail()) {
      cout << "Esa opcion no existe" << endl;
      break;
    }


    switch (op){
      case 1:{//1: Cargar archivo de datos:
        // llama la funcion para leer archivos
        leerArchivo(cantidadVideos, cantidadSeries, arrVideo, arrSeries);
        break;
      }

      case 2:{//2: Mostrar la lista de películas:
        // llama la funcion para mostrar las peliculas
        mostrarPeliculas(cantidadVideos, arrVideo);
        break;
      }

      case 3:{//3: Mostrar la lista de series:
        // llama la funcion para mostrar las series
        mostrarSeries(cantidadSeries, arrSeries);
        break;
      }

      case 4:{//4: Mostrar los videos en general con una cierta calificación:
        // pide al usuario la calificacion que quiere
        // y lo utiliza como argumento para la funcion
        cout << "Sobre cual calificacion deseas buscar?" << '\n';
        cin >> cali;
        mostrarVideosCal(cali, arrVideo, cantidadVideos);
        break;
      }

      case 5:{//5: Mostrar los videos en general de un cierto género:
      // sucede lo mismo que en el caso 4 pero ahora con un genero
        cout << "Sobre que genero deseas buscar? (Primera laetra en mayuscula)" << '\n';
        cin >> genero;
        mostrarVideosGen(genero, arrVideo, cantidadVideos);
        break;
      }

      case 6:{// 6: Mostrar los episodios de una determinada serie con sus calificaciones:
      // pide al usuario la serie, tal como esta escrita en el archivo
      // sucede lo mismo que en el caso 4 y 5
        cout << "Que serie deseas buscar? (Primera letra en mayuscula y los espacios con guion bajo por favor)" << '\n';
        cin >> serieel;
        mostrarEpCal(serieel, arrVideo, cantidadVideos);
        break;
      }

      case 7:{// 7: Mostrar las películas con cierta calificación:
      // sucede lo mismo que en el caso 4 pero ahora con peliculas
        cout << "Que calificacion de pelicula deseas buscar?" << '\n';
        cin >> cali;
        mostrarPelCal(cali, arrVideo, cantidadVideos);
        break;
      }
    }
  }
}
  
  
  

#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream>
#include <sstream>
#include <string> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

int menu()
{
  int opcion;

  system("clear");
  cout << "  0. Salir................................\n";
  cout << "  1. Cargar grafo desde fichero...........\n";
  cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

  cout << "Introduzca opcion...:";
  cin >> opcion;

  return opcion;
}

template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
{
  string ficheroMatriz, ficheroEtiquetas;
  int numeroNodos = 0;
  string line;
  G_Nodo auxNodo;
  G_Lado auxLado;

  cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;

  cout << "Fichero de las etiquetas: ";
  cin >> ficheroEtiquetas;

  ifstream Matriz;
  ifstream Etiquetas;

  Matriz.open(ficheroMatriz.c_str());
  Etiquetas.open(ficheroEtiquetas.c_str());

  while (getline(Etiquetas, line)){
    numeroNodos++;
  }
  Etiquetas.close();
  g->setNumeroNodos(numeroNodos);

  ifstream Etiquetas2(ficheroEtiquetas.c_str());

  for(int i=0; i<numeroNodos; i++){
    getline(Etiquetas2, line);
    std::stringstream convert(line.c_str());
    convert >> auxNodo;
    g->setNodo(i, auxNodo);

    for(int j=0; j<numeroNodos-1; j++){
      getline(Matriz, line, ' ');
      std::stringstream convert(line.c_str());
      convert >> auxLado;
      g->setLado(i, j, auxLado);
    }
    getline(Matriz, line, '\n');
    std::stringstream convert2(line.c_str());
    convert2 >> auxLado;
    g->setLado(i, numeroNodos-1, auxLado);

  }

  Etiquetas2.close();
  Matriz.close();
  
  return true;
}

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
  AlgoritmosGrafos<string, int> algoritmo(g.getNumeroNodos(), g);

  algoritmo.Floyd(g);
  algoritmo.imprimeMatrices();

}

#endif

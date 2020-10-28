#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include "grafo.hpp"
#include "conjunto.hpp"
#include "nodo.hpp"
using namespace std;

class automata {
  private:
    grafo Grafo;
    conjunto conjuntoL;
    conjunto conjuntoE;
    string nombreNodoInicial;
    stack <string> pila;
  public:
  automata(){
  }
  automata(string nombre_fichero) {
    bool error = false;
    string aux;
    ifstream fichero(nombre_fichero);
    bool esComentario;
    do {
      esComentario = false;
      getline(fichero, aux);
      for (int i = 0; i < aux.size(); i++) {
        if (aux[i] == '#')
          esComentario = true;
      }
    } while (esComentario);
    vector<string> vectorNombreNodos;
    for (int i = 0; i < aux.size(); i++) {
      string nombre_auxiliar;
      while (aux[i] != ' ' && i < aux.size() && aux[i] != '\0') {
        nombre_auxiliar += aux[i];
        i++;
      }
      if (nombre_auxiliar.size() != 0)
        vectorNombreNodos.push_back(nombre_auxiliar);
    }
    Grafo.insertar_nodos(vectorNombreNodos);

    getline(fichero, aux);
    vector <string> vectorNombreL;
    for (int i = 0; i < aux.size(); i++) {
      string nombre_auxiliar;
      while (aux[i] != ' ' && i < aux.size()) {
        nombre_auxiliar += aux[i];
        i++;
      }
      if (nombre_auxiliar.size() != 0)
        vectorNombreL.push_back(nombre_auxiliar);
    }
    conjuntoE.insertar_alfabeto(vectorNombreL);

    getline(fichero, aux);
    vector <string> vectorNombreE;
    for (int i = 0; i < aux.size(); i++) {
      string nombre_auxiliar;
      while (aux[i] != ' ' && i < aux.size()) {
        nombre_auxiliar += aux[i];
        i++;
      }
      if (nombre_auxiliar.size() != 0) {
        vectorNombreE.push_back(nombre_auxiliar);
      }
      
    }
    conjuntoL.insertar_alfabeto(vectorNombreE);

    getline(fichero, aux);
    nombreNodoInicial = aux;

    getline(fichero, aux);
    pila.push("auxiliar");
    pila.push(aux);

    getline(fichero, aux);
    while(fichero) {

      vector <string> vTransicionAux;
      for (int i = 0; i < aux.size(); i++) {
        string aux_;
      while (aux[i] != ' ' && i < aux.size()) {
        aux_ += aux[i];
        i++;
      }
        vTransicionAux.push_back(aux_);
      }
      for (int i = 0; i < vTransicionAux.size(); i++) {
        if (!conjuntoE.buscar_letra(vTransicionAux[i]) && !conjuntoL.buscar_letra(vTransicionAux[i]) && !vTransicionAux[i].compare("."))
          error = true;
      }
      Grafo.set_transicion(vTransicionAux);
      getline(fichero, aux);

    }
  }
  ~automata() { 
  }
  grafo get_grafo();
  bool comprobar_automata();
  bool compConjuntoL(string letra);
  bool compConjuntoE(string letra);
  void popStack();
  void pushStack(string letra);
  string pilaTop();
  string get_nombre_nodo_inicial();
  bool ejecucion(string letras, bool modoTraza);
  bool vaciado(string letras, stack <string> pila, string nombreNodoActual);
  bool vaciado_traza(string letras, stack <string> pila, string nombreNodoActual);
};
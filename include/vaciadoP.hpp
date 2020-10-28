#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include "grafo.hpp"
#include "conjunto.hpp"
#include "nodo.hpp"
#include "automata.hpp"
using namespace std;

class vaciadoP {
  private:
  automata Automata;
  vector <automata> vPosibilidades;
  public:
  vaciadoP(string nombre_fichero) : Automata(nombre_fichero) {
   
  }
  ~vaciadoP() { 
  }
 // void ejecucion(vector <string> gramatica);
  void ejecucion(string nombre_fichero);
  bool vaciado(automata Automata, vector <string> gramatica);
};
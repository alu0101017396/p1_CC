#include "../include/vaciadoP.hpp"
/*
void vaciadoP::ejecucion(vector <string> gramatica) {
  string nombreNodoActual = ;
  for (int i = 0; i < gramatica.size(); i++) {
    for (int j = 0; j < Grafo.size(); j++) {
      if (!nombreNodoActual.compare(Grafo[j].get_nombre())) {
        for (int k = 0; k < Grafo[j].size(); k++) {
          if (pila.top().compare(Grafo[j][k].get_salidaL()) == 0 && gramatica[i].compare(Grafo[j][k].get_salidaE()) == 0)
            
        }
      }
    }
  }
}*/
/*
void vaciadoP::ejecucion(string nombre_fichero) {
  automata Automata_(nombre_fichero);
  string gramatica_;
  string nodoInicial = Automata_.get_nombre_nodo_inicial();
  bool aceptada = false;
  vaciado(nombre_fichero, gramatica_, nodoInicial, aceptada);
}

bool vaciadoP::vaciado(automata Automata, string gramatica, string nodoActual, bool aceptada) {
  if (gramatica.size() > 0) {
    char letraAux = gramatica[0];
    string letra(1, letraAux);
    gramatica.erase(gramatica.begin());
    if (!aceptada) {
      for (int i = 0; i < Automata.get_grafo().size(); i++) {
        if (!Automata.get_grafo()[i].get_nombre().compare(nodoActual)) {
          for (int j = 0; j < Automata.get_grafo()[i].size(); j++) {
            if (!Automata.get_grafo()[i][j].get_salidaE().compare(letra) && 
                 !Automata.get_grafo()[i][j].get_salidaL().compare(Automata.pilaTop())) {
              
            }
          }
        }
      }
    }
  }
}*/


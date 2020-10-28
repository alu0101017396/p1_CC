#include "../include/automata.hpp"

grafo automata::get_grafo() {
  return Grafo;
}

bool automata::compConjuntoL(string letra) {
  return conjuntoL.buscar_letra(letra); 
}

bool automata::compConjuntoE(string letra) {
  return conjuntoE.buscar_letra(letra); 
}

void automata::popStack() {
  pila.pop();
}
void automata::pushStack(string letra) {
  pila.push(letra);
}
string automata::pilaTop() {
  return pila.top();
}
string automata::get_nombre_nodo_inicial() {
  return nombreNodoInicial;
}
bool automata::comprobar_automata() {
  if (Grafo.existe_nodo(nombreNodoInicial) && conjuntoL.buscar_letra(pila.top())) {
    return true;
  }
  return false;
}

bool automata::ejecucion(string letras, bool modoTraza) {
  stack <string> pila_ = pila;
  if (modoTraza) {
    return vaciado_traza(letras, pila_, nombreNodoInicial);
  } else {
    return vaciado(letras, pila_, nombreNodoInicial);
  }
}

bool automata::vaciado(string letras, stack <string> pila_, string nombreNodoActual) {
  if (letras.size() == 0 && pila_.size() == 1) {
      return true;
  }
  string letra(1, letras[0]);
  int pos_nodo = Grafo.buscar_posicion_nodo(nombreNodoActual);

  for (int i = 0; i < Grafo[pos_nodo].buscarTransPosibles(letra, pila_.top()).size(); i++) {
    int numeroTransicion = Grafo[pos_nodo].buscarTransPosibles(letra, pila_.top())[i];
    for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
    }
    if (!Grafo[pos_nodo][numeroTransicion].get_salidaE().compare(".")) {
      if (!Grafo[pos_nodo][numeroTransicion].get_salidaL().compare(".")) {
        stack <string> pilaAux = pila_;
        if (Grafo[pos_nodo][numeroTransicion].get_entradaL()[0].compare(".")) {
          for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
            pilaAux.push(Grafo[pos_nodo][numeroTransicion].get_entradaL()[j]);
          }
        }
        if (vaciado(letras, pilaAux, Grafo[pos_nodo][numeroTransicion].get_nombreNodoLlegada())) {
          return true;
        }
      } else if (pila_.size() > 1) {

        if(!Grafo[pos_nodo][numeroTransicion].get_salidaL().compare(pila_.top())){
          stack <string> pilaAux = pila_;
          pilaAux.pop();
          if (Grafo[pos_nodo][numeroTransicion].get_entradaL()[0].compare(".")) {
            for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
              pilaAux.push(Grafo[pos_nodo][numeroTransicion].get_entradaL()[j]);
            }
          }
          if (vaciado(letras, pilaAux, Grafo[pos_nodo][numeroTransicion].get_nombreNodoLlegada())) {
            return true;
          }
        }
      }
    } else if (!Grafo[pos_nodo][numeroTransicion].get_salidaE().compare(letra)){
      if (!Grafo[pos_nodo][numeroTransicion].get_salidaL().compare(".")) {
        stack <string> pilaAux = pila_;
        if (Grafo[pos_nodo][numeroTransicion].get_entradaL()[0].compare(".")) {
          for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
            pilaAux.push(Grafo[pos_nodo][numeroTransicion].get_entradaL()[j]);
          }
        }
        string letrasAux = letras;
        letrasAux.erase(letrasAux.begin());
        if (vaciado(letrasAux, pilaAux, Grafo[pos_nodo][numeroTransicion].get_nombreNodoLlegada())) {
          return true;
        }
      } else if (pila_.size() > 1) {
         if (!Grafo[pos_nodo][numeroTransicion].get_salidaL().compare(pila_.top())){
          string letrasAux = letras;
          letrasAux.erase(letrasAux.begin());
          stack <string> pilaAux = pila_;
          pilaAux.pop();
        if (Grafo[pos_nodo][numeroTransicion].get_entradaL()[0].compare(".")) {
          for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
            pilaAux.push(Grafo[pos_nodo][numeroTransicion].get_entradaL()[j]);
          }
        }
        
          if (vaciado(letrasAux, pilaAux, Grafo[pos_nodo][numeroTransicion].get_nombreNodoLlegada())) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool automata::vaciado_traza(string letras, stack <string> pila_, string nombreNodoActual) {
  cout << "Nodo Actual: " << nombreNodoActual << endl;
  stack <string> pilaCout = pila_;
  cout << "Pila: ";
  while (pilaCout.size() > 1) {
    cout << pilaCout.top() << " ";
    pilaCout.pop();
  }
  cout << endl;
  cout << "Palabra por analizar: " << letras << endl;
  cout << endl;
  if (letras.size() == 0 && pila_.size() == 1) {
      return true;
  }
  string letra(1, letras[0]);
  int pos_nodo = Grafo.buscar_posicion_nodo(nombreNodoActual);

  for (int i = 0; i < Grafo[pos_nodo].buscarTransPosibles(letra, pila_.top()).size(); i++) {
    int numeroTransicion = Grafo[pos_nodo].buscarTransPosibles(letra, pila_.top())[i];
    for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
    }
    if (!Grafo[pos_nodo][numeroTransicion].get_salidaE().compare(".")) {
      if (!Grafo[pos_nodo][numeroTransicion].get_salidaL().compare(".")) {
        stack <string> pilaAux = pila_;
        if (Grafo[pos_nodo][numeroTransicion].get_entradaL()[0].compare(".")) {
          for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
            pilaAux.push(Grafo[pos_nodo][numeroTransicion].get_entradaL()[j]);
          }
        }
        if (vaciado_traza(letras, pilaAux, Grafo[pos_nodo][numeroTransicion].get_nombreNodoLlegada())) {
          return true;
        }
      } else if (pila_.size() > 1) {

        if(!Grafo[pos_nodo][numeroTransicion].get_salidaL().compare(pila_.top())){
          stack <string> pilaAux = pila_;
          pilaAux.pop();
          if (Grafo[pos_nodo][numeroTransicion].get_entradaL()[0].compare(".")) {
            for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
              pilaAux.push(Grafo[pos_nodo][numeroTransicion].get_entradaL()[j]);
            }
          }
          if (vaciado_traza(letras, pilaAux, Grafo[pos_nodo][numeroTransicion].get_nombreNodoLlegada())) {
            return true;
          }
        }
      }
    } else if (!Grafo[pos_nodo][numeroTransicion].get_salidaE().compare(letra)){
      if (!Grafo[pos_nodo][numeroTransicion].get_salidaL().compare(".")) {
        stack <string> pilaAux = pila_;
        if (Grafo[pos_nodo][numeroTransicion].get_entradaL()[0].compare(".")) {
          for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
            pilaAux.push(Grafo[pos_nodo][numeroTransicion].get_entradaL()[j]);
          }
        }
        string letrasAux = letras;
        letrasAux.erase(letrasAux.begin());
        if (vaciado_traza(letrasAux, pilaAux, Grafo[pos_nodo][numeroTransicion].get_nombreNodoLlegada())) {
          return true;
        }
      } else if (pila_.size() > 1) {
         if (!Grafo[pos_nodo][numeroTransicion].get_salidaL().compare(pila_.top())){
          string letrasAux = letras;
          letrasAux.erase(letrasAux.begin());
          stack <string> pilaAux = pila_;
          pilaAux.pop();
        if (Grafo[pos_nodo][numeroTransicion].get_entradaL()[0].compare(".")) {
          for (int j = Grafo[pos_nodo][numeroTransicion].get_entradaL().size() - 1; j >= 0 ; j--) {
            pilaAux.push(Grafo[pos_nodo][numeroTransicion].get_entradaL()[j]);
          }
        }
        
          if (vaciado_traza(letrasAux, pilaAux, Grafo[pos_nodo][numeroTransicion].get_nombreNodoLlegada())) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

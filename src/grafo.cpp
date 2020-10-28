#include "../include/grafo.hpp"

void grafo::insertar_nodos(vector <string> vectorDeNombres) {
  for (int i = 0; i < vectorDeNombres.size(); i++) {
    nodo nodoAux(vectorDeNombres[i]);
    vNodos.push_back(nodoAux);
  }
} 

nodo& grafo::operator[](int pos){
  return vNodos[pos];
}

void grafo::set_transicion(vector <string> vectorDeTransiciones_) {
  for (int i = 0; i < vNodos.size(); i++) {
    if (vNodos[i].comparar_nombre(vectorDeTransiciones_[0])) {
      vNodos[i].set_transicion(vectorDeTransiciones_);
      break;
    }
  }
}

ostream& operator <<(ostream& os, grafo& grafo_) {
  for (int i = 0; i < grafo_.vNodos.size(); i++) {
    os << grafo_.vNodos[i] << endl;
  }
  return os;
}

int grafo::size() {
  return vNodos.size();
}

int grafo::buscar_posicion_nodo(string nombre_) {
  for (int i = 0; i < vNodos.size(); i++) {
    if (vNodos[i].comparar_nombre(nombre_))
      return i;
  }
}

bool grafo::existe_nodo(string nombre_) {
  for (int i = 0; i < vNodos.size(); i++) {
    if (vNodos[i].comparar_nombre(nombre_))
      return true;
  }
  return false;
}

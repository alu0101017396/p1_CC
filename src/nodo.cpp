#include "../include/nodo.hpp"

void nodo::insertar_nombre(string nombre_) {
  nombre = nombre_;
}

bool nodo::comparar_nombre(string nombre_) {
  if (!nombre.compare(nombre_)) {
    return true;
  }
  return false;
}

void nodo::set_transicion(vector <string> vTransiciones) {
  if (comparar_nombre(vTransiciones[0])) {
    transicion transicionAux(vTransiciones);
    Transiciones.push_back(transicionAux);
  }
}

ostream& operator<< (ostream& os, const nodo& nodo_) {
  os << nodo_.nombre << " :\n";
  for (int i = 0; i < nodo_.Transiciones.size(); i++) {
    os << nodo_.Transiciones[i] << " ";
  }
  return os;
}

nodo& nodo::operator=(const nodo& newNodo) {
  nombre = newNodo.nombre;
  Transiciones.resize(newNodo.Transiciones.size());
  for (int i = 0; i < Transiciones.size(); i++) {
    Transiciones[i] = newNodo.Transiciones[i];
  }
  return *this;
}

string nodo::get_nombre() {
  return nombre;
}

int nodo::size() {
  return Transiciones.size();
}

transicion& nodo::operator[](int pos){
  return Transiciones[pos];
}

vector <int> nodo::buscarTransPosibles(string salidaE_, string salidaL_) {
  vector <int> auxIteradores;
  for (int i = 0; i < Transiciones.size(); i++) {
    if (Transiciones[i].comprobar_posibilidad(salidaE_, salidaL_)) {
      auxIteradores.push_back(i);
    }
  }
  return auxIteradores;
}

#include "../include/transicion.hpp"

ostream& operator <<(ostream& os, const transicion& transicion_) {
  os << transicion_.salidaE << " " << transicion_.salidaL << " " 
     << transicion_.nombreNodoLlegada << " ";
  for (int i = 0; i < transicion_.entradaL.size(); i++) {
    os << transicion_.entradaL[i] << " ";
  }
  return os;
}

string transicion::get_salidaE() {
  return salidaE;
}

string transicion::get_salidaL() {
  return salidaL;
}
transicion& transicion::operator=(const transicion& transicion_) {
  salidaE = transicion_.salidaE;
  salidaL = transicion_.salidaL;
  nombreNodoLlegada = transicion_.nombreNodoLlegada;
  entradaL.resize(transicion_.entradaL.size());
  for (int i = 0; i < transicion_.entradaL.size(); i++) {
    entradaL[i] = transicion_.entradaL[i];
  }
}

string transicion::get_nombreNodoLlegada() {
  return nombreNodoLlegada;
}
vector <string> transicion::get_entradaL() {
  return entradaL;
}

bool transicion::comprobar_posibilidad(string salidaE_, string salidaL_) {

  if (!salidaE.compare(salidaE_)) {
    if (!salidaL.compare(salidaL_)) {
      return true;
    } else if (!salidaL.compare(".")) {
      return true;
    }
  } else if (!salidaE.compare(".")) {
    if (!salidaL.compare(salidaL_)) {
      return true;
    } else if (!salidaL.compare(".")) {
      return true;
    }
  }
  return false;
}

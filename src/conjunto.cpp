#include "../include/conjunto.hpp"

void conjunto::insertar_alfabeto(vector <string> vNombres) {
  for (int i = 0; i < vNombres.size(); i++) {
    string aux(vNombres[i]);
    alfabeto.push_back(aux);
  }
}

bool conjunto::buscar_letra(string letra_) {
  for (int i = 0; i < alfabeto.size(); i++) {
    if (alfabeto[i].compare(letra_) == 0) {
      return true;
    }
  }
  return false;
}

void conjunto::write() {
  for (int i = 0; i < alfabeto.size(); i++) { 
    cout << alfabeto[i] << endl;
  }
  cout << endl;
}
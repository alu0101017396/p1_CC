#include <iostream>
#include <vector>
#include <string>
#pragma once
using namespace std;

class transicion {
  private:
    string salidaE;
    string salidaL;
    string nombreNodoLlegada;
    vector <string> entradaL;
  public:
    transicion() {
    }
    transicion(vector <string> vectorTransiciones) {
      salidaE = vectorTransiciones[1];
      salidaL = vectorTransiciones[2];
      nombreNodoLlegada = vectorTransiciones[3];
      for (int i = 4; i < vectorTransiciones.size(); i++) {
        if (vectorTransiciones[i].compare(" ") || vectorTransiciones[i].compare("\0"))
          entradaL.push_back(vectorTransiciones[i]);
      }
    }
    ~transicion() {
    }
    void write() {
      cout << "E: " << salidaE << endl;
      cout << "L: " << salidaL << endl;
      cout << "NodoLlegada: " << nombreNodoLlegada << endl;
      for(int i = 0; i < entradaL.size(); i++) {
        cout << "EntradaL: " << entradaL[i] << endl;
      }
    }
    friend ostream& operator <<(ostream& os, const transicion& transicion_);
    string get_salidaE();
    string get_salidaL();
    string get_nombreNodoLlegada();
    vector <string> get_entradaL();
    transicion& operator=(const transicion& transicion_);
    bool comprobar_posibilidad(string salidaE_, string salidaL_);
};
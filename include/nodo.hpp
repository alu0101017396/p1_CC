#include <iostream>
#include <string>
#include <vector>
#include "transicion.hpp"

#pragma once
using namespace std;

class nodo {
  private:
    string nombre;
    vector <transicion> Transiciones;
  public:
    nodo() {
    }
    nodo(string nombre_) {
      nombre = nombre_;
    }
    ~nodo() {
    }
    void insertar_nombre(string nombre_);
    bool comparar_nombre(string nombre_);
    void set_transicion(vector <string> vTransiciones);
    nodo& operator=(const nodo& newNodo);
    friend ostream& operator<< (ostream& os, const nodo& nodo_);
    string get_nombre();
    int size();
    transicion& operator[](int pos);
    vector<int> buscarTransPosibles(string salidaE_, string salidaL_);
};
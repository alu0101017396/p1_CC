#include <iostream>
#include <vector>
#include <string>
#include "nodo.hpp"
#include "transicion.hpp"
#pragma once
using namespace std;

class grafo {
  private:
    vector <nodo> vNodos;
  public:
    grafo() { 
    }
    ~grafo() {  
    }
    void insertar_nodos(vector <string> vectorDeNombres);
    nodo& operator[](int pos);
    int size();
    void set_transicion(vector <string> vectorDeTransiciones_);
    friend ostream& operator <<(ostream& os, grafo& grafo_);
    int buscar_posicion_nodo(string nombre_);
    bool existe_nodo(string nombre_);
};
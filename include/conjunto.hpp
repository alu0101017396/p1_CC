#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

class conjunto {
  private:
    vector <string> alfabeto;
  public:
  conjunto():alfabeto(){
  }
  ~conjunto() {
  }
  void insertar_alfabeto(vector <string> vNombres);
  bool buscar_letra(string letra_);
  void write();
};
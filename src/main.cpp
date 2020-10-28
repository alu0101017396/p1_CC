#include "../include/automata.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Practica 1: Automata con vaciado por pila.\n";
  cout << "-----------------------------------------\n\n";
  automata vaciado_(argv[argc - 1]);
  if (vaciado_.comprobar_automata()) {
    int opcion;
    bool seguir = true;
    string palabra;
    bool modoTraza = false;
    do {
      if (modoTraza) {
      cout << "1. Salir de modo Traza.\n";
      cout << "2. Introducir palabra por consola.\n";
      cout << "3. Introducir palabra por fichero.\n";
      cout << "0. Salir.\n";
      } else {
      cout << "1. Entrar en modo Traza.\n";
      cout << "2. Introducir palabra por consola.\n";
      cout << "3. Introducir palabra por fichero.\n";
      cout << "0. Salir.\n";
      }
      
      cin >> opcion;
      switch(opcion) {
        case 0:
        {  seguir = false;
          break;
        }
        case 1:
        {
          modoTraza = !modoTraza;
          break;
        }
        case 2:
        {
          cout << "Indique la palabra que quiera comprobar: \n";
          cin >> palabra;
          if (modoTraza) {
            cout << "Traza: \n";
          }
          if(vaciado_.ejecucion(palabra, modoTraza)) {
            cout << "La palabra " << palabra << " pertenece al lenguaje" << endl;
          } else {
            cout << "La palabra " << palabra << " no pertenece al lenguaje" << endl;
          }
          break;
        }
        case 3:
        {
          cout << "Indique el nombre del fichero: \n";
          cin >> palabra;
          if (modoTraza) {
            cout << "Traza: \n";
          }
          ifstream fichero_palabra(palabra);
          getline(fichero_palabra, palabra);
          if(vaciado_.ejecucion(palabra, modoTraza)) {
            cout << "La palabra " << palabra << " pertenece al lenguaje" << endl;
          } else {
            cout << "La palabra " << palabra << " no pertenece al lenguaje" << endl;
          }
          break;
        }
        default:
          cout << "Opcion no valida" << endl;
          break;
     }
     cout << "\n";
    } while(seguir);
    
  } else {
    cout << "Error al leer el automata" << endl;
  }
}
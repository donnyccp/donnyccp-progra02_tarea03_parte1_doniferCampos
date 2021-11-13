#ifndef LECTORDEPRUEBA_H
#define LECTORDEPRUEBA_H

#include "libro.h"

#include <string>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class LectorDePrueba
{

ifstream archivoEntrada;

public:
LectorDePrueba();
ifstream AbrirArchivo(string nombreDeArchivo);
Libro ComprobarLibro(std::istream& archivoDeEntrada, int idDeLibro);
void Cerrar();


};

#endif
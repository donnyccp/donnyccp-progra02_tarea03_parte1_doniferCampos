#ifndef ESCRITORBINARIO_H
#define ESCRITORBINARIO_H

#include "libro.h"

#include <string>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class EscritorBinario
{
    int id;
    string nombre;
    string apellido;
    string correo;
    string lineaPersonas;
    string nombreParaArchivoBinario;
    ofstream archivoSalida;


public:

EscritorBinario();



void LectorArchivoTexto();
void AperturaArchivoBinario(string nombreLibro);
void CreadorLibro(int id, string nombrePersona, string apellidoPersona, string correoPersona);
void EscritorArchivoBinario(Libro &libro);
void Cerrar();


};





#endif
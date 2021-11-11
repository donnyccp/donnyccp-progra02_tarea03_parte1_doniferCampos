#ifndef ESCRITORBINARIO_H
#define ESCRITORBINARIO_H

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
     int contadorLibros;
    ofstream archivoSalida;


public:

EscritorBinario();


private:
void LectorArchivoTexto();
void EscritorArchivoBinario(int id, string nombrePersona, string apellidoPersona, string correoPersona);


};





#endif
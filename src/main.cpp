#ifndef UNIT_TEST
#include <iostream>
#include <fstream>
#include "libro.h"
#include "escritorBinario.h"

using namespace std;

int main()
{
    string nombreParaLibro = "personas.dat";
    string nombreDeArchivoTexto = "personas.txt";

    //Abrir, leer texto plano y escribir binario
    EscritorBinario escritorDeBinarios;
    escritorDeBinarios.EscritorDeArchivosBinario(nombreParaLibro);

    escritorDeBinarios.LectorArchivoTexto(nombreDeArchivoTexto);


    return 0;
}
#endif
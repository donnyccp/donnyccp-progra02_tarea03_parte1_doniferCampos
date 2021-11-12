#ifndef UNIT_TEST
#include <iostream>
#include <fstream>
#include "escritorBinario.h"
#include "lectorDePrueba.h" //eliminar

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
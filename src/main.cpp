#ifndef UNIT_TEST
#include <iostream>
#include <fstream>
#include "escritorBinario.h"

using namespace std;

int main()
{
    string nombreParaLibro="libroPersonas.dat";

    //Abrir, leer texto plano y escribir binario
    EscritorBinario escritorDeBinarios;
    escritorDeBinarios.EscritorDeArchivosBinario (nombreParaLibro);

    escritorDeBinarios.LectorArchivoTexto();
    
    return 0;
}
#endif
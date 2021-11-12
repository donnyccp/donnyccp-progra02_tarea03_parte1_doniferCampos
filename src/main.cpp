#ifndef UNIT_TEST
#include <iostream>
#include <fstream>
#include "escritorBinario.h"
#include "lectorDePrueba.h"//eliminar

using namespace std;

int main()
{
    /*string nombreParaLibro="libroPersonas.dat";
    string nombreDeArchivoTexto="personas.txt";

    //Abrir, leer texto plano y escribir binario
    EscritorBinario escritorDeBinarios;
    escritorDeBinarios.EscritorDeArchivosBinario (nombreParaLibro);


    escritorDeBinarios.LectorArchivoTexto(nombreDeArchivoTexto);*/

    Libro libroDePrueba2{1, "Jane", "Austen", "jane_austen@ucr.com"};
    string nombreArchivoPrueba = "pruebaDeLibro3.dat";
    EscritorBinario escrituraBinaria;
    escrituraBinaria.AperturaArchivoBinario(nombreArchivoPrueba);
    string nombreDeArchivoTexto="NoHayNombre.txt";
   // escrituraBinaria.LectorArchivoTexto(nombreDeArchivoTexto);
    escrituraBinaria.EscritorArchivoBinario(libroDePrueba2);
    escrituraBinaria.Cerrar();

    // Leer el libro de prueba
    LectorDePrueba lector{nombreArchivoPrueba};
    Libro libroLeido = lector.ComprobarLibro(1);
    lector.Cerrar();

    return 0;
}
#endif
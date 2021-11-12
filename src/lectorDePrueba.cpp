#include "lectorDePrueba.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "libro.h"
#include "./excepciones/excepcionNoSeAbreArchivoBinario.h"

using namespace std;

LectorDePrueba::LectorDePrueba(string nombreArchivo)
{
     AbrirArchivo(nombreArchivo);
}

void LectorDePrueba::AbrirArchivo(string nombreDeArchivo)
{
     ifstream archivoEntrada;
     archivoEntrada.open(nombreDeArchivo, ios::in | ios::binary);

     if (!archivoEntrada.is_open())
     {

          throw new ExcepcionNoSeAbreArchivoBinario();
     }
}

Libro LectorDePrueba::ComprobarLibro(int idLibro)
{
     Libro libroLeido;

     // Posición del libro número idLibro
     long posicionLibro = sizeof(Libro) * (idLibro);

    
    /* archivoEntrada.seekg(0, ios::end);
     long fileSize = archivoEntrada.tellg();

     if (posicionLibro > fileSize)
    {
        throw ExcepcionNoSeAbreArchivoBinario();
    }
    */

     archivoEntrada.seekg(posicionLibro);
     archivoEntrada.read((char *)&libroLeido, sizeof(Libro));
     
     
     return libroLeido;
}

void LectorDePrueba::Cerrar()
{
     archivoEntrada.close();
}
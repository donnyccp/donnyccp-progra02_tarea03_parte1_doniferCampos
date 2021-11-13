#include "lectorDePrueba.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "libro.h"
#include "./excepciones/excepcionNoSeAbreArchivoBinario.h"

using namespace std;

LectorDePrueba::LectorDePrueba()
{
     //Constructor vacio de la clase
}

ifstream LectorDePrueba::AbrirArchivo(string nombreDeArchivo)
{
     ifstream archivoEntrada;
     archivoEntrada.open(nombreDeArchivo, ios::in | ios::binary);

     if (!archivoEntrada.is_open())
     {

          throw new ExcepcionNoSeAbreArchivoBinario();
     }

     return archivoEntrada;

}

Libro LectorDePrueba::ComprobarLibro(std::istream& archivoEntrada, int idLibro)
{
     Libro libroLeido;

     // Posición del libro número idLibro
     long posicionLibro = sizeof(Libro) * (idLibro);

    
     archivoEntrada.seekg(0, ios::end);
     long fileSize = archivoEntrada.tellg();

     if (posicionLibro > fileSize)
    {
        throw ExcepcionNoSeAbreArchivoBinario();
    }
    

     archivoEntrada.seekg(posicionLibro);
     archivoEntrada.read((char *)&libroLeido, sizeof(Libro));
     
     
     return libroLeido;
}

void LectorDePrueba::Cerrar()
{
     archivoEntrada.close();
}
#include "lectorDePrueba.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "libro.h"
#include "./excepciones/excepcionNoSeAbreArchivoBinario.h"


using namespace std;

LectorDePrueba::LectorDePrueba (string nombreArchivo)
{
 AbrirArchivo(nombreArchivo);


}

void LectorDePrueba::AbrirArchivo(string nombreDeArchivo){
    ifstream archivoEntrada;
    archivoEntrada.open(nombreDeArchivo, ios::in|ios::binary);

    if (!archivoEntrada.is_open())
    {
         cout<<"aqui"<<endl;
         throw new ExcepcionNoSeAbreArchivoBinario();
    }

}

Libro LectorDePrueba::ComprobarLibro(int idLibro){
     Libro libroLeidoDeBinario;

    // Posición del libro número idLibro
    long posicionLibro = sizeof(Libro) * (idLibro);

    archivoEntrada.seekg(0, ios::end);
    long fileSize = archivoEntrada.tellg();

    archivoEntrada.seekg(posicionLibro);
    archivoEntrada.read((char *) &libroLeidoDeBinario, sizeof(Libro));

    return libroLeidoDeBinario;
}

void LectorDePrueba::Cerrar(){
     archivoEntrada.close();
}
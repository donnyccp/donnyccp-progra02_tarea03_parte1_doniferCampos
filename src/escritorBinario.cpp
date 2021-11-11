#include "escritorBinario.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "libro.h"
#include "./excepciones/excepcionNoSeAbreArchivoBinario.h"
#include "./excepciones/excepcionNoSeAbreArchivoTexto.h"

using namespace std;

EscritorBinario::EscritorBinario()
{
    id = 0;
    nombre = "";
    apellido = "";
    correo = "";
    lineaPersonas = "";

    contadorLibros = 0;

    LectorArchivoTexto();
}

void EscritorBinario::LectorArchivoTexto()
{

    //Abrir archivo personas

    std::ifstream ifsPersonas("personas.txt", std::ifstream::in);
    if (!ifsPersonas.is_open())
    {
        throw new excepcionNoSeAbreArchivoTexto();
    }

    while (std::getline(ifsPersonas, lineaPersonas))
    {

        id = 0;
        nombre = "";
        apellido = "";
        correo = "";

        std::istringstream ss(lineaPersonas);
        ss >> id >> nombre >> apellido >> correo;

        EscritorArchivoBinario(id, nombre, apellido, correo);
    }

    ifsPersonas.close();
}

void EscritorBinario::EscritorArchivoBinario(int id, string nombrePersona, string apellidoPersona, string correoPersona)
{
    ofstream archivoSalida;

    archivoSalida.open("libros.dat", ios::out | ios::binary);

    if (!archivoSalida.is_open())
    {
       throw new excepcionNoSeAbreArchivoBinario();
    }

    Libro libro1{id, nombrePersona, apellidoPersona, correoPersona};

    //long pos = archivoSalida.tellp();
   // archivoSalida.seekp(pos+100); //No sirve agrega antes pero se sobre escribe
    archivoSalida.write((char *)&libro1, sizeof(Libro));

    archivoSalida.close();
}

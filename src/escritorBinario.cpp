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
    nombreParaArchivoBinario ="";
}

void EscritorBinario::EscritorDeArchivosBinario(string nombreParaLibro)
{
    
    nombreParaArchivoBinario = nombreParaLibro;
    //ofstream archivoSalida;

    AperturaArchivoBinario(nombreParaArchivoBinario);
    cout<<"aqui"<<endl;
    
    //Cerrar();
}

void EscritorBinario::LectorArchivoTexto(string nombreArchivoTexto)
{

    //Abrir archivo personas

    std::ifstream ifsPersonas(nombreArchivoTexto, std::ifstream::in);
    if (!ifsPersonas.is_open())
    {
        
        throw new ExcepcionNoSeAbreArchivoTexto();
        
    }

    while (std::getline(ifsPersonas, lineaPersonas))
    {

        id = 0;
        nombre = "";
        apellido = "";
        correo = "";

        std::istringstream ss(lineaPersonas);
        ss >> id >> nombre >> apellido >> correo;

        CreadorLibro(id, nombre, apellido, correo);
    }

Cerrar();
    ifsPersonas.close();
}

void EscritorBinario::AperturaArchivoBinario(string nombreLibro)
{
    archivoSalida.open(nombreLibro, ios::out | ios::binary);

    if (!archivoSalida.is_open())
    {
        throw new ExcepcionNoSeAbreArchivoBinario();
    }
}

void EscritorBinario::CreadorLibro(int id, string nombrePersona, string apellidoPersona, string correoPersona)
{

    Libro libro1{id, nombrePersona, apellidoPersona, correoPersona};
    EscritorArchivoBinario(libro1);
}

void EscritorBinario::EscritorArchivoBinario(Libro &libro)
{

    archivoSalida.write((char *)&libro, sizeof(Libro));
}

void EscritorBinario::Cerrar()
{
    archivoSalida.close();
}

#include "libro.h"
#include <string>
#include <cstring>

using namespace std;

Libro::Libro(int id, string nombreDePersona, string apellidoDePersona, string correoDePersona) {
    
    this->id = id;    
    strcpy(this->nombre, nombreDePersona.c_str());
    strcpy(this->apellido, apellidoDePersona.c_str());
    strcpy(this->correo, correoDePersona.c_str());
}

    
Libro::Libro() {
    this->id = 0;    
    strcpy(this->nombre, "");
    strcpy(this->apellido, "");
    strcpy(this->correo, "");
}

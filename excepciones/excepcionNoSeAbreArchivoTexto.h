#ifndef ExcepcionNoSeAbreArchivoTexto_H
#define ExcepcionNoSeAbreArchivoTexto_H

#include <exception>

class ExcepcionNoSeAbreArchivoTexto : public std::exception
{
    public:
    ExcepcionNoSeAbreArchivoTexto() noexcept = default;
    ~ExcepcionNoSeAbreArchivoTexto() = default;

    virtual const char* what() const noexcept {
        return "No se puede abrir archivo texto";
    }

};

#endif
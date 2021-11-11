#ifndef ExcepcionNoSeAbreArchivoBinario_H
#define ExcepcionNoSeAbreArchivoBinario_H

#include <exception>

class ExcepcionNoSeAbreArchivoBinario : public std::exception
{
    public:
    ExcepcionNoSeAbreArchivoBinario() noexcept = default;
    ~ExcepcionNoSeAbreArchivoBinario() = default;

    virtual const char* what() const noexcept {
        return "No se puede abrir archivo Binario";
    }

};

#endif
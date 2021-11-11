#include <gtest/gtest.h>
#include <string>

#include "../src/libro.h"
#include "../src/escritorBinario.h"
#include "./excepciones/excepcionNoSeAbreArchivoBinario.h"
#include "./excepciones/excepcionNoSeAbreArchivoTexto.h"

using namespace std;

namespace
{
    TEST(EscritorTest, Prueba_EscrituraDeLibro)
    {
        Libro libroPrueba1{1, "Amelia", "Earhart", "amelia.earhart@ucr.ac.cr"};

        EscritorBinario escritura;
        escritura.AperturaArchivoBinario("pruebaDeLibro.dat");
        escritura.EscritorArchivoBinario(libroPrueba1);
        escritura.Cerrar();

       
    }

}
#include <gtest/gtest.h>
#include <string>

#include "../src/libro.h"
#include "../src/escritorBinario.h"
#include "../src/lectorDePrueba.h"
#include "../src/excepciones/excepcionNoSeAbreArchivoBinario.h"
#include "../src/excepciones/excepcionNoSeAbreArchivoTexto.h"

using namespace std;

namespace
{
    TEST(EscritorTest, Prueba_EscrituraDeLibro)
    {
        Libro libroDePrueba1{1, "Amelia", "Earhart", "amelia.earhart@ucr.ac.cr"};

        EscritorBinario escritura;
        escritura.AperturaArchivoBinario("pruebaDeLibro.dat");
        escritura.EscritorArchivoBinario(libroDePrueba1);
        escritura.Cerrar();

        LectorDePrueba lector {"pruebaDeLibro.dat"};
        Libro libroLeido = lector.ComprobarLibro(0);
        lector.Cerrar();

        EXPECT_EQ(libroLeido.getID(), libroDePrueba1.getID());
        EXPECT_EQ(libroLeido.getNombre(), libroDePrueba1.getNombre());
        EXPECT_EQ(libroLeido.getApellido(), libroDePrueba1.getApellido());
        EXPECT_EQ(libroLeido.getCorreo(), libroDePrueba1.getCorreo());

       
    }

}
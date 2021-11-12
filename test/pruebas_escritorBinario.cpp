#include <gtest/gtest.h>

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
        Libro libroLeidoDeBinario{1, "Amelia", "Earhart", "amelia_earhart@ucr.com"};
        string nombreArchivoPrueba = "pruebaDeLibro.dat";

        EscritorBinario escrituraBinaria;
        escrituraBinaria.AperturaArchivoBinario(nombreArchivoPrueba);
        escrituraBinaria.EscritorArchivoBinario(libroLeidoDeBinario);
        escrituraBinaria.Cerrar();

        LectorDePrueba lector{nombreArchivoPrueba};
        Libro libroLeido = lector.ComprobarLibro(1);
        lector.Cerrar();

        EXPECT_EQ(libroLeido.getID(), libroLeidoDeBinario.getID());
        EXPECT_EQ(libroLeido.getNombre(), libroLeidoDeBinario.getNombre());
        EXPECT_EQ(libroLeido.getApellido(), libroLeidoDeBinario.getApellido());
        EXPECT_EQ(libroLeido.getCorreo(), libroLeidoDeBinario.getCorreo());
    }

    TEST(EscritorTest, Prueba_ExcepcionNoSeAbreArchivoBinario)
    {

        Libro libroDePrueba2{1, "Jane", "Austen", "jane_austen@ucr.com"};
        string nombreArchivoPrueba = "pruebaDeLibro3A.dat";

        EXPECT_THROW(
            {
                EscritorBinario escrituraBinaria;
                escrituraBinaria.AperturaArchivoBinario(nombreArchivoPrueba);
                escrituraBinaria.LectorArchivoTexto("personas.txt");
                escrituraBinaria.EscritorArchivoBinario(libroDePrueba2);
                escrituraBinaria.Cerrar();

                // Leer el libro de prueba
                LectorDePrueba lector{"pruebaDeLibro3B.dat"};
                Libro libroLeido = lector.ComprobarLibro(1);
                lector.Cerrar();
            },
            ExcepcionNoSeAbreArchivoBinario);
    }

    TEST(EscritorTest, Prueba_ExcepcionNoSeAbreArchivoTexto)
    {

        Libro libroDePrueba2{10, "Catherine", "Janeway", "ka_janeway@ucr.com"};
        string nombreArchivoPrueba = "pruebaDeLibro3A.dat";

        EXPECT_THROW(
            {
                EscritorBinario escrituraBinaria;
                escrituraBinaria.AperturaArchivoBinario(nombreArchivoPrueba);
                escrituraBinaria.LectorArchivoTexto("celebridades.txt");
                escrituraBinaria.EscritorArchivoBinario(libroDePrueba2);
                escrituraBinaria.Cerrar();

                // Leer el libro de prueba
                LectorDePrueba lector{nombreArchivoPrueba};
                Libro libroLeido = lector.ComprobarLibro(10);
                lector.Cerrar();
            },
            ExcepcionNoSeAbreArchivoTexto);
    }

}
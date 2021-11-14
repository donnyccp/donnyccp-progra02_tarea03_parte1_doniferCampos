#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

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
        Libro libroEscritoBinario{1, "Amelia", "Earhart", "amelia_earhart@ucr.com"};
        string nombreArchivoPrueba = "pruebaDeLibro.dat";

        EscritorBinario escrituraBinaria;
        escrituraBinaria.AperturaArchivoBinario(nombreArchivoPrueba);
        escrituraBinaria.EscritorArchivoBinario(libroEscritoBinario);
        escrituraBinaria.Cerrar();

        LectorDePrueba lector;
        ifstream archivoEntrada;
        archivoEntrada = lector.AbrirArchivo(nombreArchivoPrueba);
        Libro libroLeido = lector.ComprobarLibro(archivoEntrada, 0);

        lector.Cerrar();
        archivoEntrada.close();

        EXPECT_EQ(libroLeido.getID(), libroEscritoBinario.getID());
        EXPECT_EQ(libroLeido.getNombre(), libroEscritoBinario.getNombre());
        EXPECT_EQ(libroLeido.getApellido(), libroEscritoBinario.getApellido());
        EXPECT_EQ(libroLeido.getCorreo(), libroEscritoBinario.getCorreo());
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
                LectorDePrueba lector;
                ifstream archivoEntrada;
                archivoEntrada = lector.AbrirArchivo("pruebaDeLibro3B.dat");
                Libro libroLeido = lector.ComprobarLibro(archivoEntrada, 0);

                lector.Cerrar();
                archivoEntrada.close();
            },
            ExcepcionNoSeAbreArchivoBinario);
    }

    TEST(EscritorTest, Prueba_ExcepcionNoSeAbreArchivoTexto)
    {

        Libro libroDePrueba2{10, "Catherine", "Janeway", "ka_janeway@ucr.com"};
        string nombreArchivoPrueba = "pruebaDeLibro4.dat";

        EXPECT_THROW(
            {
                EscritorBinario escrituraBinaria;
                escrituraBinaria.AperturaArchivoBinario(nombreArchivoPrueba);
                escrituraBinaria.LectorArchivoTexto("celebridades.txt");
                escrituraBinaria.EscritorArchivoBinario(libroDePrueba2);
                escrituraBinaria.Cerrar();

                // Leer el libro de prueba
                LectorDePrueba lector;
                ifstream archivoEntrada;
                archivoEntrada = lector.AbrirArchivo(nombreArchivoPrueba);
                Libro libroLeido = lector.ComprobarLibro(archivoEntrada, 0);

                lector.Cerrar();
                archivoEntrada.close();
            },ExcepcionNoSeAbreArchivoTexto);
    }

}
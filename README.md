
# progra02_tarea03_doniferCampos
Programación 02- Tarea 3_Parte1-Donifer Campos Parra
Programado en Windows10- Visual Studio Code 1.60.0
mkdir obj
g++ -std=c++17 -stdlib=libc++ -g ./src/*.cpp -o ./obj/tarea1 

La primera aplicación, lee un archivo de personas.txt y escribe un archivo binario con
la información utilizando el siguiente formato por cada persona:
Nombre del campo -    Tipo      -  Tamaño
ID               - Entero (int) -
Nombre           - String       -    15   
Apellido         -  String      -    15
Correo           -  String      -    50
El archivo a escribe un binario y llamarse personas.dat
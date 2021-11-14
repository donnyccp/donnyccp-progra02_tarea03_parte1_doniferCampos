
# progra02_tarea03_doniferCampos
Programación 02- Tarea 3_Parte1-Donifer Campos Parra <br />
Programado en Windows10- Visual Studio Code 1.62.1 <br />
mkdir obj <br />
g++ -std=c++17 -stdlib=libc++ -g ./src/*.cpp -o ./obj/tarea3 <br /> 

La primera aplicación, lee un archivo de personas.txt y escribe un archivo binario con
la información de las personas, utilizando el siguiente formato por cada persona: <br />
Nombre del campo &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-    Tipo&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-  Tamaño <br />
ID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- Entero (int)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - <br />
Nombre&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- String&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-    15 <br />
Apellido&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-  String&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-    15 <br />
Correo&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-  String&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-    50 <br />

Para que este programa se ejecute eficazmente es necesario que siga los siguientes requerimientos especiales:<br />
&nbsp;&nbsp;&nbsp;1- Escriba correctamente el nombre del archibo de texto a leer.<br />
&nbsp;&nbsp;&nbsp;2- Los datos de las personas en el archivo de texto no pueden exceder el tamaño designado en la anterior tabla segun su designacion en nombre de campo. Ejemplo: Correo no mayor a 50 caracteres.<br />

 Este programa cuenta con 4 clases. La clase principal main gestiona la instancia a la clase escritorBinario. La clase escritorBinario gestiona la escritura de un archivo binario con el nombre de "personas.dat" que contiene los datos de id, nombre, apellido y correo de cada persona (libro), para ello realiza una instancia a la clase libro. La clase libro gestiona los datos de las personas en un arreglo de caracteres denominado libro. La clase lectorDePrueba es una clase auxiliar a las pruebas unitarias con GoogleTest de la correcta escritura de el archivo binario, no es esencial para la escritura de un archivo binario<br />

 Para comprobar el correcto funcionamiento del programa y sus metodos este programa cuenta con pruebas unitarias que se ejecutan usando GoogleTests, tome las previsiones necasarias para ejecuatar las pruebas, mas información en https://google.github.io/googletest/.<br />

Al final de la ejecución se escribe un archivo binario  llamado "personas.dat". <br />
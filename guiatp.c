// Trabajo Final Lenguajes Estructurados
// Modulo 1: Banco de preguntas.
// Modulo 2: Generación de Examen.
// Modulo 3: Correccion de examen

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// declaraciones de estructuras
//  struct pregunta{};
//  struct examen{};
//  struct correccion{}; 

void main()
{
    // posibles arreglos de estructuras
    // struct pregunta preg;

    // menu de modulos

    return;
}

// definiciones de funciones

// modulo1
    // menu de preguntas: nueva, consulta un pregunta por capituo y modulo, modificar
    // borrar, listar todas.

// modulo2
    // ingresar nro de examen, fecha, preguntas
    // como selecciono las preguntas?
    //     leo el archivo preguntas y lo guardo en memoria en un arreglo de preguntas
    //     ingrese el capitulo y el subcapitulo -> de ese arreglo de pregunats filtro 
    //  por capitulo y subcapitulo y luego elijo una
    // y esa lo mando a un arreglo de estructuras 
    // cuando finaliza lo guardo todo en una archivo

    // se guarda en un archivo

//modulo3



// como armar y desarmar un registro
void armarRegistro(struct pregunta registro, char registro[T])
{
    strcat(registro, nropregunta);
    strcat(registro, ",");
    strcat(registro, nroCapitulo);
    strcat(registro, ",");

    return;
}

void desarmarRegistro(struct pregunta reg, char registro[T])
{
    int longitudCadena = strlen(registro);

    reg.nroPregunta = 
    strcat(registro, nropregunta);
    strcat(registro, ",");
    strcat(registro, nroCapitulo);
    strcat(registro, ",");

    return;
}

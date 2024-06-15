#include <stdio.h>
#include "functions.h"
/*
 * Este archivo se va a encargar de ejecutar el programa invocando a todas las funciones
 * y va a contener un menu
 *
    printf("Hello, World!\n");
    char saludo[20];
    //scanf(" %s",&saludo); no permite ingresar palabras separadas por espacios en blanco
    gets(saludo);
    puts(saludo);
    //strcat(saludo,);
*/
// Declaraciones de constantes
const int MAX_PREGUNTAS=500;
// Declaraciones de estructuras

/*struct examen{ //
    int nExamen;
    int fecha;
    int cantidadPreguntas;
    Pregunta preguntas[MAX_PREGUNTAS];
};
struct correccion{
    int nExamen;
    int puntaje;
    struct examen examenes[MAX_PREGUNTAS];
};

*/
// Funcion Principal del sistema
int main()
{
    int opcion;
    do
    {
        opcion=menu();
        switch (opcion)
        {
            case 1:
                menuPreguntas();
                break;
            case 2:
                menuExamenes();
                break;
            case 3:
                menuCorreciones();
                break;
            case 0:
                printf("FIN PROGRAMA.\n");
                break;
        }

    }while (opcion!=0);// corre hasta que se ingrese 0
    return 0;
}





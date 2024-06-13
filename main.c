#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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
const int T=1000;
// Declaraciones de estructuras

/*struct examen{ //
    int nExamen;
    int fecha;
    int cantidadPreguntas;
    Pregunta preguntas[T];
};
struct correccion{
    int nExamen;
    int puntaje;
    struct examen examenes[T];
};

*/
// Declaraciones de funciones
int menu();
void menuPreguntas(Pregunta preguntas[T]);
void menuExamenes(Examen examenes[T]);
void menuCorreciones(Correccion correcciones[T]);


int main()
{
    int opcion;
    Pregunta preguntas[T];
    Examen examenes[T];
    Correccion correcciones[T];
    do
    {
        opcion=menu();
        switch (opcion)
        {
            case 1:
                menuPreguntas(preguntas);
                break;
            case 2:
                menuExamenes(examenes);
                break;
            case 3:
                menuCorreciones(correcciones);
                break;
            case 0:
                printf("FIN PROGRAMA.\n");
                break;
        }

    }while (opcion!=0);// corre hasta que se ingrese 0
    return 0;
}


int menu()
{   int opcion;
    printf("\nPROGRAMA BANCO DE PREGUNTAS\n");
    printf("Opciones\n");
    printf("1-Administracion del Banco de preguntas.\n");
    printf("2-Administracion de Examenes.\n");
    printf("3-Administracion de Correcciones.\n");
    printf("0-FIN PROGRAMA\n");
    do {
        printf("Ingresa una opcion:");
        scanf(" %d",&opcion);
        if(opcion<0 || opcion>3){
            printf("Opcion Invalida.");
        }
    } while (opcion<0 || opcion>3);
    return opcion;
}

// Funcion para submenu preguntas
void menuPreguntas(Pregunta preguntas[T]){// hacer switch
    int opcion;
    printf("Menu administracion de preguntas\n");
    printf("1-Agregar nuevas preguntas.\n");
    printf("2-Modificar preguntas existentes.\n");
    printf("3-Mostrar preguntas.\n");
    printf("0-Fin seccion preguntas.\n");
    printf("Ingresa una opcion:");
    do {
        printf("Ingresa una opcion:");
        scanf(" %d",&opcion);
        switch (opcion)
        {
            case 1:
                ingresarPreguntas(preguntas);
                break;

            case 2:
                modificarPreguntas(preguntas);
                break;
            case 3:
                mostrarPreguntas(preguntas);
                break;
            case 0:
                printf("Fin seccion preguntas.\n");
                break;
        }

    } while (opcion<0 || opcion>3);
}
void menuExamenes(Examen examenes[T]){
    printf("Menu Administracion de Examenes.\n");
    printf("1-Generar Examenes.\n");
    printf("0-Salir del menu examenes.\n");

}
void menuCorreciones(Correccion correcciones[T]){
    printf("Menu administracion de correcciones.\n");
    printf("1-Corregir Examenes.\n");
    printf("0-Salir del menu correciones.");

}
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
void menuPreguntas();
void menuExamenes();
void menuCorreciones();


int main()
{   prueba();
    int opcion;
    Pregunta preguntas[T];
    //struct examen examenes[T];
    //struct correccion correcciones[T];
    /*do
    {
        opcion=menu();
        switch (menu()) {
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
            default:
                printf("Opcion incorrecta.");
                break;
        }

    }while (opcion!=0);// corre hasta que se ingrese 0
    */
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

void menuPreguntas(){// hacer logica
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
        if(opcion<0 || opcion>3){
            printf("Opcion Invalida.");
        }
    } while (opcion<0 || opcion>3);
}
void menuExamenes(){
    printf("Menu Administracion de Examenes.\n");
    printf("1-Generar Examenes.\n");
    printf("0-Salir del menu examenes.\n");

}
void menuCorreciones(){
    printf("Menu administracion de correcciones.\n");
    printf("1-Corregir Examenes.\n");
    printf("0-Salir del menu correciones.");

}
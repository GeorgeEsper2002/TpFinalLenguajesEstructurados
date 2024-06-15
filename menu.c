
#include <stdio.h>
#include "functions.h"
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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
#define T 1000
#define MAX_LONG_PREGUNTA 30
// Declaraciones de estructuras
struct pregunta{
    int nPregunta;
    int nCapitulo;
    char nombreCap[30];
    int nSubCapitulo;
    char nombreSubCap[30];
    char opciones[6][MAX_LONG_PREGUNTA];
};
struct examen{
    int nExamen;
    int fecha;
    int cantidadPreguntas;
    struct pregunta preguntas[T];
};
struct correccion{
    int nExamen;
    int puntaje;
    struct examen examenes[T];
};


// Declaraciones de funciones
void menu();
void menuPreguntas();
void menuExamenes();
void menuCorreciones();


int main()
{
    int opcion,opcionPreg,opcionExam,opcionCorrc;
    struct pregunta preguntas[T];
    struct examen examenes[T];
    struct correccion correcciones[T];
    do
    {
        menu();
        scanf(" %d",&opcion);
        if(opcion==1)
        {   // Opcion 1 administracion de preguntas
            printf("Has ingresado 1 - Administracion de preguntas.\n");
            do {
                menuPreguntas();
                scanf(" %d",&opcionPreg);
                if (opcionPreg==0){
                    break;
                }
                else if(opcionPreg==1)
                {
                                    ;
                }
                else if(opcionPreg==2)
                {
                                    ;
                }
                else if(opcionPreg==3){
                                    ;
                }
            } while (opcionPreg<0||opcionPreg>3);

        }
        else if(opcion==2)
        {
            // Opcion 2 administracion de examenes
            printf("Has ingresado 2 - Administracion de examenes.\n");
            menuExamenes();
        }
        else if(opcion==3)
        {
            // Opcion 3, administracion de correcciones
            printf("Has ingresado 3 - Administracion de correciones.\n");
            menuCorreciones();
        }

    }while (opcion!=0);// corre hasta que se ingrese 0
    return 0;

}
void menu()
{
    printf("\nPROGRAMA BANCO DE PREGUNTAS\n");
    printf("Opciones\n");
    printf("1-Administracion del Banco de preguntas.\n");
    printf("2-Administracion de Examenes.\n");
    printf("3-Administracion de Correcciones.\n");
    printf("0-FIN PROGRAMA\n");
    printf("Ingresa una opcion:");
}

void menuPreguntas(){
    printf("Menu administracion de preguntas\n");
    printf("1-Agregar nuevas preguntas.\n");
    printf("2-Modificar preguntas existentes.\n");
    printf("3-Mostrar preguntas.\n");
    printf("0-Fin seccion preguntas.\n");
    printf("Ingresa una opcion:");
    
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
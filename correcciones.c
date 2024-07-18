

#include <stdio.h>
#include "functions.h"
#include "persistencia.h"

void menuCorreciones();
void corregirExamen();
void verExamenesCorregidos();

void menuCorreciones(){
    int opcion;
    printf("Menu administracion de correcciones.\n");
    printf("1-Corregir Examenes.\n");
    printf("2-Ver examenes corregidos.\n");
    printf("0-Salir del menu correciones.");
    scanf(" %d", &opcion);
    switch (opcion)
    {
        case 1:
            corregirExamen();
            break;
        case 2:
            verExamenesCorregidos();
            break;
        case 0:
            printf("Saliendo del menu correcciones.\n");
            break;

    }
}

/*
 * Necesito idExamen
 * Necesito nombre del alumno
 * itero hasta la cantidad de preguntas del examen
 * muestro las preguntas del examen
 * crear arreglo respuestas alumno, me guardo las respuestas del alumno
 *
 */
void corregirExamen(){
    printf("Corregir examen\n");
    Correccion nuevaCorreccion;
    Examen examen;
    int idExamen, bandera;
    do {
        printf("Ingresa el numero de examen a corregir: ");
        scanf(" %d", &idExamen);
        if (verSiExisteExamen(idExamen)== 0) {
            printf("El examen no existe.\n");
        }
    } while (verSiExisteExamen(idExamen)== 0);
    examen=getExamenById(idExamen);
    nuevaCorreccion.nExamen = idExamen;
    nuevaCorreccion.puntaje = 0;
}
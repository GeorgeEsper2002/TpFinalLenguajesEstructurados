

#include <stdio.h>
#include "functions.h"
#include "persistencia.h"
#include <string.h>
#include <ctype.h>

void menuCorreciones();
void corregirExamen();
void verExamenesCorregidos();
float sacarPuntaje(int respuestasAlumno[], int respuestasCorrectas[], int cantidadPreguntas);

void menuCorreciones(){
    int opcion;

    do{
        printf("Menu administracion de correcciones.\n");
        printf("1-Corregir Examenes.\n");
        printf("2-Ver examenes corregidos.\n");
        printf("0-Salir del menu correciones.\n");
        printf("Ingresa una opcion: ");
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
    }while (opcion<0 || opcion>2);
}

/*
 * Necesito idExamen
 * Necesito nombre del alumno
 * itero hasta la cantidad de preguntas del examen
 * muestro las preguntas del examen
 * crear arreglo respuestas alumno, me guardo las respuestas del alumno
 * No funciona bien, no guarda las respuestas del alumno
 */
void corregirExamen(){

    Correccion nuevaCorreccion;
    Examen examen;
    int idExamen,cantidadPreguntas;
    char alumno[50],opcion;
    float puntaje;
    printf("-------Corregir examen-------\n");
    do {
       do {
            printf("Ingresa el numero de examen a corregir: ");
            scanf(" %d", &idExamen);
            if (verSiExisteExamen(idExamen)== 0){
                printf("El examen no existe.\n");
            }
       } while (verSiExisteExamen(idExamen)== 0);
        examen=getExamenById(idExamen);
        nuevaCorreccion.nExamen = idExamen;
        nuevaCorreccion.puntaje = 0;
        cantidadPreguntas=examen.cantidadPreguntas;
        nuevaCorreccion.cantidadPreguntas=cantidadPreguntas;
        do {
            printf("Ingresa el nombre del alumno: ");
            scanf(" %[^\n]", alumno);
            if(strlen(alumno)<1){
                printf("Nombre invalido.\n");
            }
        } while (strlen(alumno)<1);
        int respuestasAlumno[examen.cantidadPreguntas];
        int respuestasCorrectas[examen.cantidadPreguntas];
        printf("Ingresa las respuestas del alumno uno a uno: ");
        for (int i = 0; i < cantidadPreguntas; ++i) {
            printf("Pregunta %d: %s\n",i+1, ObtenerPreguntaPorId(examen.idPreguntas[i]).pregunta);
            do {
                printf("Respuesta: ");
                scanf(" %d", &respuestasAlumno[i]);
                if(respuestasAlumno[i]<1 || respuestasAlumno[i]>4){
                    printf("Respuesta invalida.\n");
                }
            }while(respuestasAlumno[i]<1 || respuestasAlumno[i]>4);
            respuestasCorrectas[i]=ObtenerPreguntaPorId(examen.idPreguntas[i]).respuestaCorrecta;
            if(respuestasAlumno[i]==respuestasCorrectas[i]){
               printf("Respuesta correcta.\n");
            }
            else{
                printf("Respuesta incorrecta.\n");
            }
        }
        puntaje=sacarPuntaje(respuestasAlumno,respuestasCorrectas,examen.cantidadPreguntas);
        printf("Alumno: %s\n",alumno);
        printf("Puntaje: %.2f\n",puntaje);
        nuevaCorreccion.puntaje=puntaje;
        strcpy(nuevaCorreccion.nombreAlumno,alumno);
        for (int i = 0; i < examen.cantidadPreguntas ; ++i) {
            nuevaCorreccion.respuestas[i]=respuestasCorrectas[i];
        }
        guardarCorreccionEnArchivo(nuevaCorreccion);
        do {
            printf("Desea corregir otro examen? (s/n): ");
            scanf(" %c",&opcion);
            if(tolower(opcion)!= 's' && tolower(opcion)!='n'){
                printf("Opcion invalida.\n");
            }
        }while(opcion!='s' && opcion!='n');

    }while (opcion!='n');
}

void verExamenesCorregidos(){
    Correccion correcciones[MAX_PREGUNTAS];
    int idExamen;
    do{
        printf("Ingrese el id de correccion : ");
        scanf(" %d",&idExamen);
        if(examenTieneCorreccion(idExamen)!=0){
            printf("El examen ya esta corregido.\n");
        }
    } while (examenTieneCorreccion(idExamen)!=0 && idExamen<0);
    obtenerCorrecciones(correcciones);
    for (int i = 0; i < C; ++i){
        if(correcciones[i].nExamen==idExamen){
            printf("Correccion %d\n",correcciones[i].nExamen);
            printf("Nombre Alumno: %s\n",correcciones[i].nombreAlumno);
            printf("Puntaje: %.2f\n",correcciones[i].puntaje);
            printf("\n");
        }

    }
}








float sacarPuntaje(int respuestasAlumno[],int respuestasCorrectas[],int cantidadPreguntas){
    float puntaje=0;
    for (int i = 0; i < cantidadPreguntas; ++i) {
        if(respuestasAlumno[i]==respuestasCorrectas[i]){
            puntaje++;
        }
    }
    return (float) puntaje/cantidadPreguntas*10;

}
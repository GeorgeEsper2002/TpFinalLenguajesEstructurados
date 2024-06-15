#include <stdio.h>
#include "functions.h"
#include "persistencia.h"
#define ARCHIVO_PREGUNTAS "preguntas.txt"

void guardarPreguntaEnArchivo(Pregunta nuevaPregunta){
    FILE *archivo;
    archivo=fopen(ARCHIVO_PREGUNTAS,"a");
    if (archivo==NULL){
        printf("Error al abrir el archivo.");
        return;
    }

    fprintf(archivo, "%d;%d;%s;%d;%s;%d;%s;%s;%s;%s;%s;%d\n",
            nuevaPregunta.id,
            nuevaPregunta.capitulo.id,
            nuevaPregunta.capitulo.nombreCap,
            nuevaPregunta.subCapitulo.id,
            nuevaPregunta.subCapitulo.nombreSubCap,
            nuevaPregunta.subCapitulo.idCapitulo,
            nuevaPregunta.pregunta,
            nuevaPregunta.opcion1,
            nuevaPregunta.opcion2,
            nuevaPregunta.opcion3,
            nuevaPregunta.opcion4,
            nuevaPregunta.respuestaCorrecta);

    fclose(archivo);
    printf("pregunta agregada con exito.");
}

// Funcion para sobreescribir preguntas en el archivo de preguntas.
void guardarPreguntasEnArchivo(Pregunta preguntas[MAX_PREGUNTAS]){
    FILE *archivo;
    archivo=fopen(ARCHIVO_PREGUNTAS,"a");
    if (archivo==NULL){
        printf("Error al abrir el archivo.");
        return;
    }
    for (int i=0;i<MAX_PREGUNTAS;i++){
        fprintf(archivo, "%d;%d;%s;%d;%s;%d;%s;%s;%s;%s;%s;%d;\n",
                preguntas[i].id,
                preguntas[i].capitulo.id,
                preguntas[i].capitulo.nombreCap,
                preguntas[i].subCapitulo.id,
                preguntas[i].subCapitulo.nombreSubCap,
                preguntas[i].subCapitulo.idCapitulo,
                preguntas[i].pregunta,
                preguntas[i].opcion1,
                preguntas[i].opcion2,
                preguntas[i].opcion3,
                preguntas[i].opcion4,
                preguntas[i].respuestaCorrecta);
    }
    fclose(archivo);
    printf("Pregunta agregada con exito.");
}

// funcion para obtener las preguntas
void leerPreguntasEnArchivo(Pregunta preguntas[MAX_PREGUNTAS]){
   FILE *archivo;
    archivo=fopen(ARCHIVO_PREGUNTAS,"r");
    if (archivo==NULL){
        printf("Error al abrir el archivo.");
        return;
    }
    int i=0;
    while (!feof(archivo)){
        fscanf(archivo, "%d;%d;%s;%d;%s;%d;%s;%s;%s;%s;%s;%d;\n",
                &preguntas[i].id,
                &preguntas[i].capitulo.id,
                preguntas[i].capitulo.nombreCap,
                &preguntas[i].subCapitulo.id,
                preguntas[i].subCapitulo.nombreSubCap,
                &preguntas[i].subCapitulo.idCapitulo,
                preguntas[i].pregunta,
                preguntas[i].opcion1,
                preguntas[i].opcion2,
                preguntas[i].opcion3,
                preguntas[i].opcion4,
                &preguntas[i].respuestaCorrecta);
        i++;
    }

}

// Funcion que existe para ver si existe un capitulo
int verSiExisteCapitulo(int idCapitulo){
     Pregunta preguntas[MAX_PREGUNTAS];
    leerPreguntasEnArchivo(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
         if (preguntas[i].capitulo.id==idCapitulo) {
             return 1;
         }
    }
    return 0;
}


// Funcion para guardar una pregunta modificada
void guardarPreguntaModificada(Pregunta preguntaModificada){
    Pregunta preguntas[MAX_PREGUNTAS];
    leerPreguntasEnArchivo(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].id==preguntaModificada.id){
            preguntas[i]=preguntaModificada;
            break;
        }
    }
    guardarPreguntasEnArchivo(preguntas);
    printf("Pregunta modificada con exito!!");
}

void eliminarPregunta(Pregunta preguntaABorrar){
    Pregunta preguntas[MAX_PREGUNTAS];
    Pregunta preguntasNuevas[MAX_PREGUNTAS];
    leerPreguntasEnArchivo(preguntas);
    int j=0;
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].id!=preguntaABorrar.id){
            preguntasNuevas[j]=preguntas[i];
            j++;
        }
    }
    guardarPreguntasEnArchivo(preguntasNuevas);
    printf("Pregunta eliminada con exito!!");

}

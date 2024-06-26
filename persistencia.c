#include <stdio.h>
#include <string.h>
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

    fprintf(archivo, "%d;%d;%s;%d;%s;%s;%s;%s;%s;%s;%d\n",
            nuevaPregunta.id,
            nuevaPregunta.capitulo.id,
            nuevaPregunta.capitulo.nombreCap,
            nuevaPregunta.subCapitulo.id,
            nuevaPregunta.subCapitulo.nombreSubCap,
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
        fprintf(archivo, "%d;%d;%s;%d;%s;%s;%s;%s;%s;%s;%d;\n",
                preguntas[i].id,
                preguntas[i].capitulo.id,
                preguntas[i].capitulo.nombreCap,
                preguntas[i].subCapitulo.id,
                preguntas[i].subCapitulo.nombreSubCap,
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

// funcion para obtener las preguntas a memoria
void leerPreguntasEnArchivo(Pregunta preguntas[MAX_PREGUNTAS]){
   FILE *archivo;
    archivo=fopen(ARCHIVO_PREGUNTAS,"r");
    if (archivo==NULL){
        printf("Error al abrir el archivo.");
        return;
    }
    int i=0;
    char line[512];
    while (fgets(line, sizeof(line), archivo)) {
        sscanf(line, "%d;%d;%[^;];%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;\n",
               &preguntas[i].id,
               &preguntas[i].capitulo.id,
               preguntas[i].capitulo.nombreCap,
               &preguntas[i].subCapitulo.id,
               preguntas[i].subCapitulo.nombreSubCap,
               preguntas[i].pregunta,
               preguntas[i].opcion1,
               preguntas[i].opcion2,
               preguntas[i].opcion3,
               preguntas[i].opcion4,
               &preguntas[i].respuestaCorrecta);
        i++;
    }

}

// Funcion para ver si existe una pregunta retorna 0 si no hay pregunta y 1 si hay pregunta existente.
int verSiExistePregunta(int idPregunta){
    Pregunta preguntas[MAX_PREGUNTAS];
    leerPreguntasEnArchivo(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].id == idPregunta){
            return 1;
        }
    }
    return 0;
}

// Funcion  para ver si existe un capitulo, retorna 0 si no hay capitulo y 1 si hay capitulo existente.
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

// Funcion  para ver si existe un subcapitulo retorna 0 si no hay subcapitulo y 1 si hay subcapitulo existente.
int verSiExisteSubCapitulo(int idCapitulo,int idSubCapitulo){
    Pregunta preguntas[MAX_PREGUNTAS];
    leerPreguntasEnArchivo(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].subCapitulo.id==idSubCapitulo && preguntas[i].capitulo.id==idCapitulo) {
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

// Funcion para eliminar una pregunta
void eliminarPregunta(Pregunta preguntaABorrar){
    Pregunta preguntas[MAX_PREGUNTAS];
    Pregunta preguntasNuevas[MAX_PREGUNTAS];
    leerPreguntasEnArchivo(preguntas);
    printf("La pregunta a borrar es:\n");
    mostrarPregunta(&preguntaABorrar.id);
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

// Funcion para buscar un capitulo por id
Capitulo buscarCapituloPorId(int idCapitulo){
    Pregunta preguntas[MAX_PREGUNTAS];
    Capitulo capitulo;
    leerPreguntasEnArchivo(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].capitulo.id==idCapitulo){
            capitulo.id=preguntas[i].capitulo.id;
            strcpy(capitulo.nombreCap,preguntas[i].capitulo.nombreCap);
            break;
        }
    }
    return capitulo;
}

SubCapitulo buscarSubCapituloPorId(int idCapitulo,int idSubCapitulo){
    Pregunta preguntas[MAX_PREGUNTAS];
    SubCapitulo subCapitulo;
    leerPreguntasEnArchivo(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].subCapitulo.id==idSubCapitulo && preguntas[i].capitulo.id==idCapitulo){
            subCapitulo.id=preguntas[i].subCapitulo.id;
            strcpy(subCapitulo.nombreSubCap,preguntas[i].subCapitulo.nombreSubCap);
            break;
        }
    }
    return subCapitulo;
}

void obtenerTodasLasPreguntas(Pregunta preguntas[MAX_PREGUNTAS]){
    leerPreguntasEnArchivo(preguntas);
}

void obtenerPreguntaPorCapitulo(Pregunta preguntasCapitulo[MAX_PREGUNTAS],int idCapitulo){
    Pregunta preguntas[MAX_PREGUNTAS];
    Pregunta preguntasC[MAX_PREGUNTAS];
    leerPreguntasEnArchivo(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].capitulo.id==idCapitulo){
            preguntasC[i]=preguntas[i];
        }
    }
}
#ifndef TPFINALC_FUNCTIONS_H
#define TPFINALC_FUNCTIONS_H

#define MAX_LONG_PREGUNTA 100
#define C 1000
extern const int MAX_PREGUNTAS;

typedef struct{
    int id;
    char nombreSubCap[50];
    int idCapitulo;
}SubCapitulo;


typedef struct{
    int id;
    char nombreCap[50];
}Capitulo;


typedef struct{
    int id;
    Capitulo capitulo;
    SubCapitulo subCapitulo;
    char pregunta[200];
    char opcion1[100];
    char opcion2[100];
    char opcion3[100];
    char opcion4[100];
    int respuestaCorrecta;
}Pregunta;



typedef struct{
    int nExamen;
    int fecha;
    int cantidadPreguntas;
    Pregunta preguntas[C];
}Examen;

typedef struct{
    int nExamen;
    int puntaje;
    Examen examenes;
}Correccion;

//Functions of questions handling
void menuPreguntas();
void menuExamenes();
void menuCorreciones();
void menuModificarPregunta();
Pregunta ObtenerPreguntaPorId(int *idPregunta);
void modificarPregunta();
int menu();
#endif //TPFINALC_FUNCTIONS_H
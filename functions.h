#ifndef TPFINALC_FUNCTIONS_H
#define TPFINALC_FUNCTIONS_H

#define C 100
extern const int MAX_PREGUNTAS;

typedef struct{
    int id;
    char nombreSubCap[50];
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
    int idExamen;
    char fecha[20];
    int cantidadPreguntas;
    int idPreguntas[C];
}Examen;

typedef struct{
    int nExamen;
    char nombreAlumno[50];
    float puntaje;
    int cantidadPreguntas;
    Examen examen;
    int respuestas[C];
}Correccion;

//Funciones relacionas a preguntas
void menuPreguntas();
void menuExamenes();
void menuCorreciones();
void menuModificarPregunta();
Pregunta ObtenerPreguntaPorId(int idPregunta);
void ingresarPreguntas();
void subMenuMostrarPreguntas();
void subMenuMostrarPreguntasSubcapitulo();
void mostrarPreguntas();
void menuModificarPregunta();
void subMenuEliminarPregunta();
void mostrarPregunta(int idPregunta);
void mostrarPreguntasPorSubCapitulo(int idCapitulo,int idSubCapitulo,Pregunta preguntas[MAX_PREGUNTAS]);
void mostrarPreguntasSubcapitulo();
void modificarPregunta();
int menu();

// Funciones relacionadas a examenes
void generarExamenes();

// Funciones relacionadas a correcciones
#endif //TPFINALC_FUNCTIONS_H
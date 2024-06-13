#ifndef TPFINALC_FUNCTIONS_H
#define TPFINALC_FUNCTIONS_H

#define MAX_LONG_PREGUNTA 100
#define C 1000
extern const int T;
typedef struct{
    int nPregunta;
    int nCapitulo;
    char nombreCap[30];
    int nSubCapitulo;
    char nombreSubCap[30];
    char opciones[6][MAX_LONG_PREGUNTA];
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
void ingresarPreguntas(Pregunta preguntas[T]);
void guardarPreguntas(Pregunta preguntas[T]);
void mostrarPreguntas(Pregunta preguntas[T]);
void modificarPreguntas(Pregunta preguntas[T]);
void prueba();

#endif //TPFINALC_FUNCTIONS_H
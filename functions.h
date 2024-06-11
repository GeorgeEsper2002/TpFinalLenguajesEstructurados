#ifndef TPFINALC_FUNCTIONS_H
#define TPFINALC_FUNCTIONS_H

#define MAX_LONG_PREGUNTA 100

extern const int T;
typedef struct{
    int nPregunta;
    int nCapitulo;
    char nombreCap[30];
    int nSubCapitulo;
    char nombreSubCap[30];
    char opciones[6][MAX_LONG_PREGUNTA];
}Pregunta;



void prueba();

#endif //TPFINALC_FUNCTIONS_H
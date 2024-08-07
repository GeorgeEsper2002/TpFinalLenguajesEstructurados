//
// Created by Usuario on 13/6/2024.
//
#ifndef TPFINALC_PERSISTENCIA_H
#define TPFINALC_PERSISTENCIA_H
#include "functions.h"


void guardarPreguntaEnArchivo(Pregunta nuevaPregunta);
void guardarPreguntasEnArchivo(Pregunta preguntas[MAX_PREGUNTAS]);
void leerPreguntasDesdeArchivo(Pregunta preguntas[MAX_PREGUNTAS]);
void guardarPreguntaModificada(Pregunta preguntaModificada);
void eliminarPregunta(Pregunta preguntaABorrar);
void obtenerPreguntasPorCapitulo(Pregunta preguntasCapitulo[MAX_PREGUNTAS], int idCapitulo);
void obtenerTodasLasPreguntas(Pregunta preguntas[MAX_PREGUNTAS]);
int verSiExistePregunta(int idPregunta);
int verSiExistePreguntaEnArreglo(int idPregunta, Pregunta preguntas[MAX_PREGUNTAS]);
int verSiExisteCapitulo(int idCapitulo);
int verSiExisteSubCapitulo(int idCapitulo,int idSubCapitulo);
Capitulo buscarCapituloPorId(int idCapitulo);
SubCapitulo buscarSubCapituloPorId(int idCapitulo,int idSubCapitulo);
void obtenerTodosLosCapitulos(Capitulo capitulos[MAX_PREGUNTAS]);
int contarPreguntasDisponiblesPorSubcapitulo(int idCapitulo,int idSubCapitulo);
void mostrarSubCapitulosPorCapitulo(int idCapitulo,SubCapitulo subCapitulos[MAX_PREGUNTAS]);
void mostrarCapitulos(Capitulo capitulos[MAX_PREGUNTAS]);
void obtenerPreguntasPorSubCapitulo(int idCapitulo, int idSubCapitulo,Pregunta preguntas[MAX_PREGUNTAS]);
void guardarExamenEnArchivo(Examen nuevoExamen);
int verSiExisteExamen(int idExamen);
void obtenerTodosLosExamenes(Examen examenes[MAX_PREGUNTAS]);
Examen getExamenById(int idExamen);
void preguntasDisponibles(Pregunta preguntas[MAX_PREGUNTAS], int idCapitulo, int idSubCapitulo);
void guardarCorreccionEnArchivo(Correccion nuevaCorreccion);
void obtenerCorrecciones(Correccion correcciones[MAX_PREGUNTAS]);
int hayPreguntasDisponibles(Pregunta pregunta[MAX_PREGUNTAS],int idCapitulo,int idSubCapitulo);
int examenTieneCorreccion(int idExamen);
#endif //TPFINALC_PERSISTENCIA_H

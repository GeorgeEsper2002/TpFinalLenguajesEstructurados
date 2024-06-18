//
// Created by Usuario on 13/6/2024.
//
#ifndef TPFINALC_PERSISTENCIA_H
#define TPFINALC_PERSISTENCIA_H
#include "functions.h"


void guardarPreguntaEnArchivo(Pregunta nuevaPregunta);
void guardarPreguntasEnArchivo(Pregunta preguntas[MAX_PREGUNTAS]);
void leerPreguntasEnArchivo(Pregunta preguntas[MAX_PREGUNTAS]);
void guardarPreguntaModificada(Pregunta preguntaModificada);
void subMenuEliminarPregunta();
void eliminarPregunta(Pregunta preguntaABorrar);
int verSiExistePregunta(int idPregunta);
int verSiExisteCapitulo(int idCapitulo);
int verSiExisteSubCapitulo(int idCapitulo,int idSubCapitulo);
Capitulo buscarCapituloPorId(int idCapitulo);
SubCapitulo buscarSubCapituloPorId(int idCapitulo,int idSubCapitulo);








#endif //TPFINALC_PERSISTENCIA_H

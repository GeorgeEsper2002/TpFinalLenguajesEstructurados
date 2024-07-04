
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "util.h"
#include "persistencia.h"
void menuExamenes(){
    int opcion;
    printf("-----------------Menu Administracion de Examenes-----------------\n");
    printf("1-Generar Examenes.\n");
    printf("0-Salir del menu examenes.\n");
    printf("-----------------------------------------------------------------\n");
    printf("Ingresa una opcion: ");
    do {
        printf("Ingresa una opcion: ");
        scanf(" %d",&opcion);
        if(opcion<0 || opcion>1){
            printf("Opcion Invalida.");
        }
        switch (opcion)
        {
            case 1:
                 generarExamenes();
                break;
            case 0:
                printf("Saliendo del menu examenes.\n");
                break;

        }
    } while (opcion<0 || opcion>1);

}



// Funcion para generar examenes


/*
 * La funcion deberia generar exanemenes
 * usanndo el banco de preguntas,obteniendo dichas preguntas por Id y guardando esas preguntas en un examen.
 * En un archivo examenes.txt se guardan los examenes generados.
 *
 */
void generarExamenes(){
    printf("Generar examenes\n");


    int cantidadPreguntas=0,maxPreguntas;
    maxPreguntas=contarPreguntasDisponibles();
    Examen nuevoExamen;
    Pregunta preguntas[MAX_PREGUNTAS];
    Capitulo capitulos[MAX_PREGUNTAS];
    SubCapitulo subCapitulos[MAX_PREGUNTAS];
    do {
        printf("Ingresa el numero de examen: ");
        scanf(" %d",&nuevoExamen.idExamen);
    }while (nuevoExamen.idExamen < 0);
    do {
        printf("Ingresa fecha de examen en formato (dd/mm/aaaa): ");
        scanf(" %s",nuevoExamen.fecha);
        if(validarFecha(nuevoExamen.fecha)==0){
            printf("Fecha invalida.\n");
        }
    } while (strlen(nuevoExamen.fecha)<1 && validarFecha(nuevoExamen.fecha)==0);
    do{
        printf("Ingresa la cantidad de preguntas: ");
        scanf(" %d",&nuevoExamen.cantidadPreguntas);
        if(maxPreguntas<nuevoExamen.cantidadPreguntas){
            printf("No hay suficientes preguntas en el banco de preguntas.\n");
            do{
                printf("ReIngresa la cantidad de preguntas: ");
                scanf(" %d",&nuevoExamen.cantidadPreguntas);
            } while (maxPreguntas<nuevoExamen.cantidadPreguntas);
        }
    }while (nuevoExamen.cantidadPreguntas<0);

    do {
        printf("Ingresa el capitulo de la pregunta: ");
        scanf(" %d",&capitulos[0].id);
        if(verSiExisteCapitulo(capitulos[0].id)==0){
            printf("El Capitulo no existe.\n");
            continue;
        }
        mostrarCapitulos(capitulos);
        mostrarSubCapitulosPorCapitulo(capitulos[0].id,subCapitulos);
        printf("Ingresa el subcapitulo de la pregunta: ");
        scanf(" %s",subCapitulos[0].nombreSubCap);
        if(verSiExisteSubCapitulo(capitulos[0].id,subCapitulos[0].id)==0){
            printf("El SubCapitulo no existe.\n");
            continue;
        }
    }while (verSiExisteSubCapitulo(capitulos[0].id,subCapitulos[0].id)==0);

    for (int i=0;i<nuevoExamen.cantidadPreguntas;i++){

        do {
            mostrarPreguntasPorSubCapitulo(capitulos[0].id,subCapitulos[0].id);
            printf("Ingresa el id de la pregunta: ");
            scanf(" %d",&preguntas[i].id);
            if(verSiExistePregunta(preguntas[i].id)==0){
                printf("La pregunta no existe.\n");
                continue;
            }
        }while (verSiExistePregunta(preguntas[i].id)==0);
    }
    guardarExamenEnArchivo(nuevoExamen);
}



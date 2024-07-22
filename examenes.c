
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "util.h"
#include "persistencia.h"


void mostrarPreguntasDisponiblesSubcapitulo(Pregunta preguntas[MAX_PREGUNTAS]);
void eliminarPreguntaElegida(Pregunta pregunta[MAX_PREGUNTAS],int idPregunta);


void menuExamenes(){
    int opcion;
    printf("-----------------Menu Administracion de Examenes-----------------\n");
    printf("1-Generar Examenes.\n");
    printf("0-Salir del menu examenes.\n");
    printf("-----------------------------------------------------------------\n");
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



// Poder agregar cualquier pregunta en examen y no solo las de un subcapitulo


// Funcion para generar examenes
/*
 * La funcion deberia generar exanemenes
 * usanndo el banco de preguntas,obteniendo dichas preguntas por Id y guardando esas preguntas en un examen.
 * En un archivo examenes.txt se guardan los examenes generados.
 *
 */
void generarExamenes(){
    printf("------Generar examenes------\n");
      int bandera,idPregunta,cantidadTotalPreguntas,idCapitulo,idSubCapitulo;
        Examen nuevoExamen;
        nuevoExamen.cantidadPreguntas=0;
        Pregunta preguntas[MAX_PREGUNTAS];
        Capitulo capitulos[MAX_PREGUNTAS];
        SubCapitulo subCapitulos[MAX_PREGUNTAS];
        for (int i=0;i<C;i++){
            nuevoExamen.idPreguntas[i]=-1;
        }
        do{
            printf("Ingresa el numero de examen: ");
            scanf(" %d",&nuevoExamen.idExamen);
            if(verSiExisteExamen(nuevoExamen.idExamen)==1){
                printf("El examen ya existe.\n");
                do {
                    printf("Reingresa el numero de examen: ");
                    scanf(" %d",&nuevoExamen.idExamen);
                }while(verSiExisteExamen(nuevoExamen.idExamen)==1);
            }
        }while(nuevoExamen.idExamen < 0 && verSiExisteExamen(nuevoExamen.idExamen) != 1);
        do {
            printf("Ingresa fecha de examen en formato (dd/mm/aaaa): ");
            scanf(" %s",nuevoExamen.fecha);
            if(validarFecha(nuevoExamen.fecha)==0){
                do {
                    printf("Ingresa fecha de examen en formato (dd/mm/aaaa): ");
                    scanf(" %s",nuevoExamen.fecha);
                }while(validarFecha(nuevoExamen.fecha)==0);
            }
        } while (strlen(nuevoExamen.fecha)<1 && validarFecha(nuevoExamen.fecha)==0);

    do {
            do {

                printf("Ingresa el capitulo de la pregunta: ");
                mostrarCapitulos(capitulos);
                scanf(" %d",&idCapitulo);
                if(verSiExisteCapitulo(idCapitulo)==0){
                    printf("El Capitulo no existe.\n");
                    continue;
                }
                printf("Ingresa el subcapitulo de la pregunta: ");
                mostrarSubCapitulosPorCapitulo(idCapitulo,subCapitulos);
                scanf(" %d",&idSubCapitulo);
                if(verSiExisteSubCapitulo(idCapitulo,idSubCapitulo) == 0){
                    printf("El SubCapitulo no existe.\n");
                    continue;
                }
            } while (verSiExisteSubCapitulo(idCapitulo,idSubCapitulo) == 0);
            cantidadTotalPreguntas=contarPreguntasDisponiblesPorSubcapitulo(idCapitulo, idSubCapitulo);
            preguntasDisponibles(preguntas,idCapitulo,idSubCapitulo);
            while(nuevoExamen.cantidadPreguntas < cantidadTotalPreguntas != 0){
                if(hayPreguntasDisponibles(preguntas,idCapitulo,idSubCapitulo)==0){
                    printf("No hay preguntas disponibles para este subcapitulo.\n");
                    break;
                }
                printf("Preguntas Disponibles:\n");
                mostrarPreguntasDisponiblesSubcapitulo(preguntas);

                printf("Ingresa el id de pregunta a agregar o 0 para salir:\n ");
                scanf(" %d",&idPregunta);
                if(idPregunta==0){
                    break;
                }
                if(verSiExistePreguntaEnArreglo(idPregunta, preguntas) == 0){
                    printf("La pregunta no existe.\n");
                    continue;
                }
                nuevoExamen.idPreguntas[nuevoExamen.cantidadPreguntas]=idPregunta;
                nuevoExamen.cantidadPreguntas++;
                eliminarPreguntaElegida(preguntas,idPregunta);
            }
            do{
                printf("Desea agregar mas preguntas al examen? (1-Si,0-No):\n");
                scanf(" %d",&bandera);
            } while (bandera!=1 && bandera!=0);

    } while (bandera!=0);
        guardarExamenEnArchivo(nuevoExamen);
    }

void mostrarPreguntasDisponiblesSubcapitulo(Pregunta preguntas[MAX_PREGUNTAS]){
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if(preguntas[i].id!=-1){
            printf("Id: %d|Pregunta: %s\n",preguntas[i].id,preguntas[i].pregunta);
        }
    }
}

void eliminarPreguntaElegida(Pregunta pregunta[MAX_PREGUNTAS],int idPregunta){
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if(pregunta[i].id==idPregunta){
            pregunta[i].id=-1;
            printf("Pregunta agregada con exito.\n");
        }
    }
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "persistencia.h"
// Declaracion Funciones
void ingresarPreguntas();
void guardarPreguntas();
void mostrarPreguntas();
void menuModificarPregunta();
void mostrarPregunta(int *idPregunta);

/*
 * una opcion del menu que permita listar las preguntas ingresadas por capitulo y subcapitulo
 * y de ahi mirar las preguntas almacenadas.
 */
void menuPreguntas(){
    int opcion;
    printf("Menu administracion de preguntas\n");
    printf("1-Agregar nuevas preguntas.\n");
    printf("2-Modificar preguntas existentes.\n");
    printf("3-Mostrar preguntas.\n");
    printf("0-Fin seccion preguntas.\n");
    printf("Ingresa una opcion:");
    do {
        printf("Ingresa una opcion:");
        scanf(" %d",&opcion);
        switch (opcion)
        {
            case 1:
                ingresarPreguntas();
                break;

            case 2:
                menuModificarPregunta();
                break;
            case 3:
                //mostrarPreguntas();
                break;
            case 0:
                printf("Fin seccion preguntas.\n");
                break;
        }

    } while (opcion<0 || opcion>3);
}



/*
void ingresarPreguntas(Pregunta preguntas[T]){
    int n,bandera,total_preguntas=0;
    printf("Ingresa la cantidad de preguntas:");
    scanf(" %d",&n);
    for (int i = 0; i < n; ++i)
    {
        do{

            do {
                printf("Ingresa el numero de capitulo de la Pregunta %d",i+1);
                scanf(" %d",&preguntas[i].nCapitulo);
            } while (preguntas[i].nCapitulo<0);
            do {
                printf("Ingresa el nombre del capitulo %d",preguntas[i].nCapitulo);
                fflush(stdin);
                gets(preguntas[i].nombreCap,sizeof(preguntas[i].nombreCap),stdin); // Lee la entrada del usuario
                preguntas[i].nombreCap[strcspn(preguntas[i].nombreCap, "\n")] = 0; // Elimina el enter al ingresar
            } while (strlen(preguntas[i].nombreCap) == 0); // sigue iterando si el string esta vacio.

            do {
                printf("Ingresa el numero de subcapitulo de la Pregunta %s :",preguntas[i].nombreCap);
                scanf(" %d",&preguntas[i].nSubCapitulo);
            }while(preguntas[i].nSubCapitulo<0);
            // Ingreso el nombre del subcapitulo
            do {
                printf("Ingresa el nombre de subcapitulo %d capitulo %s y numero %d",preguntas[i].nSubCapitulo,preguntas[i].nombreCap,preguntas[i].nCapitulo);
                fgets(preguntas[i].nombreSubCap,sizeof(preguntas[i].nombreCap),stdin);
                preguntas[i].nombreSubCap[strcspn(preguntas[i].nombreSubCap, "\n")] = 0;
            } while (strlen(preguntas[i].nombreSubCap) == 0);

            // Ingreso la Pregunta
            do {
                printf("Ingresa el numero de la Pregunta:");
                fgets(preguntas[i].opciones[0],sizeof(preguntas[i].opciones[0]),stdin);
                preguntas[i].opciones[0][strcspn(preguntas[i].opciones[0], "\n")]=0;
            } while (strlen(preguntas[i].opciones[0]) == 0);

            // Opcion 1
            do{
                printf("%s\n",preguntas[i].opciones[0]);
                printf("Ingresa la respuesta 1:");
                fgets(preguntas[i].opciones[1],sizeof(preguntas[i].opciones[1]),stdin);
                preguntas[i].opciones[1][strcspn(preguntas[i].opciones[1], "\n")] = 0;
            } while (strlen(preguntas[i].opciones[1] ) == 0);
            // Opcion 2
            do{
                printf("%s\n",preguntas[i].opciones[0]);
                printf("Ingresa la respuesta 2:");
                fgets(preguntas[i].opciones[2],sizeof(preguntas[i].opciones[2]),stdin);
                preguntas[i].opciones[2][strcspn(preguntas[i].opciones[2], "\n")] = 0;

            } while (strlen(preguntas[i].opciones[1] ) == 0);
            // Opcion 3
            do{
                printf("%s\n",preguntas[i].opciones[0]);
                printf("Ingresa la respuesta 3:");
                fgets(preguntas[i].opciones[3],sizeof(preguntas[i].opciones[3]),stdin);
                preguntas[i].opciones[3][strcspn(preguntas[i].opciones[3], "\n")] = 0;

            } while(strlen(preguntas[i].opciones[3]) == 0);
            // Opcion 4
            do{
                printf("%s\n",preguntas[i].opciones[0]);
                printf("Ingresa la respuesta 4:");
                fgets(preguntas[i].opciones[4],sizeof(preguntas[i].opciones[4]),stdin);
                preguntas[i].opciones[4][strcspn(preguntas[i].opciones[0], "\n")] = 0;
            }while(strlen(preguntas[i].opciones[4] ) == 0);
            // Opcion Correcta
            do{
                printf("%s\n",preguntas[i].opciones[0]);
                printf("Ingresa la respuesta correcta:");
                fgets(preguntas[i].opciones[5],sizeof(preguntas[i].opciones[5]),stdin);
                preguntas[i].opciones[5][strcspn(preguntas[i].opciones[0], "\n")] = 0;
            }while (strlen(preguntas[i].opciones[5] ) == 0);
            do{
                printf("Desea seguir ingresando preguntas 0:NO 1:SI? :");
                scanf(" %d",&bandera);
            } while (bandera!=0 && bandera!=1);
            if (bandera==0){
                preguntas[i].nPregunta=0;
            }
        } while (bandera!=0);
    }


}
*/
void ingresarPreguntas(){
    Pregunta nuevaPregunta;
    int opcion;
    printf("1:Ingresar Preguntas\n0:Salir\n");
    scanf(" %d",&opcion);
    while(opcion!=0){

        do {
            printf("Ingresa el id de la pregunta: ");
            scanf(" %d",&nuevaPregunta.id);
            // hacer funcion para ver si existe el id
        } while (nuevaPregunta.id<0);

        do {
            printf("Ingresa el numero de capitulo: ");
            scanf(" %d",&nuevaPregunta.capitulo.id);
            // Hacer funcion para ver si existe el id
        } while (nuevaPregunta.capitulo.id<0);


        do {
            printf("Ingresa el nombre del capitulo %d: ",nuevaPregunta.capitulo.id);
            scanf(" %[^\n]",nuevaPregunta.capitulo.nombreCap);
        } while (strlen(nuevaPregunta.capitulo.nombreCap)<0);


        do {
            printf("Ingresa el numero del subcapitulo: ");
            scanf(" %d",&nuevaPregunta.subCapitulo.id);
        } while (nuevaPregunta.subCapitulo.id<0);

        nuevaPregunta.subCapitulo.idCapitulo=nuevaPregunta.capitulo.id;

        do{
            printf("Ingresa el nombre del subcapitulo: ");
            scanf(" %[^\n]",nuevaPregunta.subCapitulo.nombreSubCap);
        } while (strlen(nuevaPregunta.subCapitulo.nombreSubCap)<0);

        do {
            printf("Ingresa la pregunta: ");
            scanf(" %[^\n]",nuevaPregunta.pregunta);
        } while (strlen(nuevaPregunta.pregunta)<0);


        do {
            printf("Ingresa la opcion 1 de la pregunta: ");
            scanf(" %[^\n]",nuevaPregunta.opcion1);
        } while (strlen(nuevaPregunta.opcion1)<0);


        do{
            printf("Ingresa la opcion 2 de la pregunta: ");
            scanf(" %[^\n]",nuevaPregunta.opcion2);
        } while (strlen(nuevaPregunta.opcion2)<0);


        do {
            printf("Ingresa la opcion 3 de la pregunta:");
            scanf(" %[^\n]",nuevaPregunta.opcion3);
        } while (strlen(nuevaPregunta.opcion3)<0);


        do {
            printf("Ingresa la opcion 4 de la pregunta:");
            scanf(" %[^\n]",nuevaPregunta.opcion4);

        } while (strlen(nuevaPregunta.opcion4)<0);

        do {
            printf("Ingresa la respuesta correcta (1-4):");
            scanf(" %d",&nuevaPregunta.respuestaCorrecta);

        } while (nuevaPregunta.respuestaCorrecta<1||nuevaPregunta.respuestaCorrecta>4);
        guardarPreguntaEnArchivo(nuevaPregunta);
        printf("GEI");
        printf("1:Ingresar Preguntas\n0:Salir\n");
        scanf(" %d",&opcion);
    }





}


void menuModificarPregunta(){
    int opcion;
    printf("Menu Modificar Preguntas\n");
    printf("1-Modificar Pregunta.\n");
    printf("2-Eliminar Pregunta.\n");
    printf("0-Salir del menu modificar preguntas.\n");
    printf("Ingresa una opcion:");
    do {
        printf("Ingresa una opcion:");
        scanf(" %d",&opcion);
        switch (opcion)
        {
            case 1:
                modificarPregunta();
                break;

            case 2:
                //eliminarPregunta();
                break;
            case 0:
                printf("Fin seccion modificar preguntas.\n");
                break;
        }

    } while (opcion<0 || opcion>2);
}


void modificarPregunta(){
    Pregunta preguntaModificada;
    int id;
    do{
        printf("Ingresa el id de la pregunta a modificar:");
        scanf(" %d",&id);
    } while (id<0);
    preguntaModificada.id=id;
    mostrarPregunta(&preguntaModificada.id);
    // ingreso el id de pregunta
    do {
        printf("Ingresa el numero de capitulo de la Pregunta %d",id);
        scanf(" %d",&preguntaModificada.capitulo.id);
    } while (preguntaModificada.capitulo.id<0);

    // Ingreso el nombre del capitulo
    do {
        printf("Ingresa el nombre del capitulo %d",preguntaModificada.capitulo.id);
        scanf(" %[^\n]",preguntaModificada.capitulo.nombreCap);
    } while (strlen(preguntaModificada.capitulo.nombreCap)<0);
    // Ingreso el numero de subcapitulo
    do {
        printf("Ingresa el numero de subcapitulo de la Pregunta %s :",preguntaModificada.capitulo.nombreCap);
        scanf(" %d",&preguntaModificada.subCapitulo.id);
    }while(preguntaModificada.subCapitulo.id<0);

    preguntaModificada.subCapitulo.idCapitulo=preguntaModificada.capitulo.id;
    // Ingreso el nombre del subcapitulo
    do {
        printf("Ingresa el nombre de subcapitulo %d capitulo %s y numero %d",preguntaModificada.subCapitulo.id,
               preguntaModificada.capitulo.nombreCap,preguntaModificada.capitulo.id);
        scanf(" %[^\n]",preguntaModificada.subCapitulo.nombreSubCap);
    } while (strlen(preguntaModificada.subCapitulo.nombreSubCap)<0);

    // Ingreso la Pregunta
    do {
        printf("Ingresa el nombre de la Pregunta:");
        scanf(" %[^\n]",preguntaModificada.pregunta);
    } while (strlen(preguntaModificada.pregunta)<0);

    // Opcion 1
    do{
        printf("%s\n",preguntaModificada.pregunta);
        printf("Ingresa la respuesta 1:");
        scanf(" %[^\n]",preguntaModificada.opcion1);
    } while (strlen(preguntaModificada.opcion1)<0);
    // Opcion 2
    do{
        printf("%s\n",preguntaModificada.pregunta);
        printf("Ingresa la respuesta 2:");
        scanf(" %[^\n]",preguntaModificada.opcion2);
    } while (strlen(preguntaModificada.opcion2)<0);
    // opcion 3
    do {
        printf(" %s\n",preguntaModificada.pregunta);
        printf("Ingresa la respuesta 3:");
        scanf(" %[^\n]",preguntaModificada.opcion3);
    } while (strlen(preguntaModificada.opcion3)<0);
    // Opcion 4

    do {
        printf(" %s\n",preguntaModificada.pregunta);
        printf("Ingresa la respuesta 4:");
        scanf(" %[^\n]",preguntaModificada.opcion4);
    } while (strlen(preguntaModificada.opcion4)<0);

    // Respuesta Correcta
    do {
        printf(" %s\n",preguntaModificada.pregunta);
        printf("Ingresa la respuesta correcta:");
        scanf(" %d",&preguntaModificada.respuestaCorrecta);
    } while (preguntaModificada.respuestaCorrecta<1||preguntaModificada.respuestaCorrecta>4);
    guardarPreguntaModificada(preguntaModificada);
}





// Funcion que busca la pregunta por id para mostrarla
Pregunta ObtenerPreguntaPorId(int *idPregunta){
    Pregunta preguntas[MAX_PREGUNTAS];
    leerPreguntasEnArchivo(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].id==*idPregunta){
            return preguntas[i];
        }

    }
    printf("Pregunta no encontrada\n");
    Pregunta preguntaVacia;
    preguntaVacia.id=-1;
    return preguntaVacia;
}








void mostrarPregunta(int *idPregunta){
    printf("Mostrando pregunta %d\n",*idPregunta);
    Pregunta pregunta;
    pregunta=ObtenerPreguntaPorId(idPregunta);
    if(pregunta.id!=-1){
        printf("Pregunta: %s\n",pregunta.pregunta);
        printf("Opcion 1: %s\n",pregunta.opcion1);
        printf("Opcion 2: %s\n",pregunta.opcion2);
        printf("Opcion 3: %s\n",pregunta.opcion3);
        printf("Opcion 4: %s\n",pregunta.opcion4);
        printf("Respuesta Correcta: %d\n",pregunta.respuestaCorrecta);
    }
    printf("Pregunta inexistente.\n");
}
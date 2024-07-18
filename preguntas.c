
#include <string.h>
#include <stdio.h>
#include "functions.h"
#include "persistencia.h"
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
                subMenuMostrarPreguntas();
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
// Funcion para ingresar preguntas
void ingresarPreguntas(){
    Pregunta nuevaPregunta;
    int opcion,banderaPregunta;
    printf("1:Ingresar Preguntas\n0:Salir\n");
    printf("Ingresa una opcion: ");
    scanf(" %d",&opcion);
    while(opcion!=0){

        do {
            printf("Ingresa el id de la pregunta: ");
            scanf(" %d",&nuevaPregunta.id);
            banderaPregunta= verSiExistePregunta(nuevaPregunta.id);
            while(banderaPregunta==1){
                printf("El id de la pregunta ya existe\n");
                printf("Ingresa el id de la pregunta: ");
                scanf(" %d",&nuevaPregunta.id);
                banderaPregunta= verSiExistePregunta(nuevaPregunta.id);
            }
        } while (nuevaPregunta.id<0);


        do {
            printf("Ingresa el numero de capitulo:");
            scanf(" %d",&nuevaPregunta.capitulo.id);
            if (verSiExisteCapitulo(nuevaPregunta.capitulo.id)==1){
             //Funcion para traer el capitulo por id y copiar el nombre en la nueva pregunta.
             printf("Nombre del capitulo: %s\n",buscarCapituloPorId(nuevaPregunta.capitulo.id).nombreCap);
             strcpy(nuevaPregunta.capitulo.nombreCap,buscarCapituloPorId(nuevaPregunta.capitulo.id).nombreCap);
            }
            else if (nuevaPregunta.capitulo.id>0){
                do {
                    printf("Ingresa el nombre del capitulo %d: ",nuevaPregunta.capitulo.id);
                    scanf(" %[^\n]",nuevaPregunta.capitulo.nombreCap);
                } while (strlen(nuevaPregunta.capitulo.nombreCap)<0);
            }
            else{
                printf("El id del capitulo no puede ser negativo\n");
            }
        } while (nuevaPregunta.capitulo.id<0);

        do {
            printf("Ingresa el numero del subcapitulo: ");
            scanf(" %d",&nuevaPregunta.subCapitulo.id);
            // Funcion para ver si existe un subcapitulo existe
           if(verSiExisteSubCapitulo(nuevaPregunta.capitulo.id,nuevaPregunta.subCapitulo.id)==1){
               //Funcion para traer el subcapitulo por id y copiar el nombre en la nueva pregunta.
               printf("Nombre del subcapitulo: %s\n",buscarSubCapituloPorId(nuevaPregunta.capitulo.id,nuevaPregunta.subCapitulo.id).nombreSubCap);
               strcpy(nuevaPregunta.subCapitulo.nombreSubCap,buscarSubCapituloPorId(nuevaPregunta.capitulo.id,nuevaPregunta.subCapitulo.id).nombreSubCap);
           }
           else if (nuevaPregunta.subCapitulo.id>0){
               do {
                   printf("Ingresa el nombre del subcapitulo %d: ",nuevaPregunta.subCapitulo.id);
                   scanf(" %[^\n]",nuevaPregunta.subCapitulo.nombreSubCap);
               } while (strlen(nuevaPregunta.subCapitulo.nombreSubCap)<0);
           }
           else{
               printf("El id del subcapitulo no puede ser negativo\n");
           }
        } while (nuevaPregunta.subCapitulo.id<0);

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
        printf("1:Ingresar Preguntas\n0:Salir\n");
        scanf(" %d",&opcion);
        if (opcion==0){
            nuevaPregunta.id=-1;// Marca en array de preguntas que no hay mas preguntas
        }
    }





}

// Submenu modificar pregunta
void menuModificarPregunta(){
    int opcion;
    printf("Menu Modificar Pregunta\n");
    printf("1-Modificar Pregunta.\n");
    printf("2-Eliminar Pregunta.\n");
    printf("0-Salir del menu modificar pregunta.\n");
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
                subMenuEliminarPregunta();
                break;
            case 0:
                printf("Fin seccion modificar preguntas.\n");
                break;
        }

    } while (opcion<0 || opcion>2);
}

// Funcion para modificar una pregunta
void modificarPregunta(){
    Pregunta preguntaAModificar;
    int banderaPregunta;
    do {
        printf("Ingresa el id de la pregunta: ");
        scanf(" %d",&preguntaAModificar.id);
        banderaPregunta= verSiExistePregunta(preguntaAModificar.id);
        while(banderaPregunta==1){
            printf("El id de la pregunta ya existe\n");
            printf("Ingresa el id de la pregunta: ");
            scanf(" %d",&preguntaAModificar.id);
            banderaPregunta= verSiExistePregunta(preguntaAModificar.id);
        }
    } while (preguntaAModificar.id<0);


    do {
        printf("Ingresa el numero de capitulo:");
        scanf(" %d",&preguntaAModificar.capitulo.id);
        if (verSiExisteCapitulo(preguntaAModificar.capitulo.id)==1){
            //Funcion para traer el capitulo por id y copiar el nombre en la nueva pregunta.
            printf("Nombre del capitulo: %s\n",buscarCapituloPorId(preguntaAModificar.capitulo.id).nombreCap);
            strcpy(preguntaAModificar.capitulo.nombreCap,buscarCapituloPorId(preguntaAModificar.capitulo.id).nombreCap);
        }
        else if (preguntaAModificar.capitulo.id>0){
            do {
                printf("Ingresa el nombre del capitulo %d: ",preguntaAModificar.capitulo.id);
                scanf(" %[^\n]",preguntaAModificar.capitulo.nombreCap);
            } while (strlen(preguntaAModificar.capitulo.nombreCap)<0);
        }
        else{
            printf("El id del capitulo no puede ser negativo\n");
        }
    } while (preguntaAModificar.capitulo.id<0);

    do {
        printf("Ingresa el numero del subcapitulo: ");
        scanf(" %d",&preguntaAModificar.subCapitulo.id);
        // Funcion para ver si existe un subcapitulo existe
        if(verSiExisteSubCapitulo(preguntaAModificar.capitulo.id,preguntaAModificar.subCapitulo.id)==1){
            //Funcion para traer el subcapitulo por id y copiar el nombre en la nueva pregunta.
            printf("Nombre del subcapitulo: %s\n",buscarSubCapituloPorId(preguntaAModificar.capitulo.id,preguntaAModificar.subCapitulo.id).nombreSubCap);
            strcpy(preguntaAModificar.subCapitulo.nombreSubCap,buscarSubCapituloPorId(preguntaAModificar.capitulo.id,preguntaAModificar.subCapitulo.id).nombreSubCap);
        }
        else if (preguntaAModificar.subCapitulo.id>0){
            do {
                printf("Ingresa el nombre del subcapitulo %d: ",preguntaAModificar.subCapitulo.id);
                scanf(" %[^\n]",preguntaAModificar.subCapitulo.nombreSubCap);
            } while (strlen(preguntaAModificar.subCapitulo.nombreSubCap)<0);
        }
        else{
            printf("El id del subcapitulo no puede ser negativo\n");
        }
    } while (preguntaAModificar.subCapitulo.id<0);

    do {
        printf("Ingresa la pregunta: ");
        scanf(" %[^\n]",preguntaAModificar.pregunta);
    } while (strlen(preguntaAModificar.pregunta)<0);


    do {
        printf("Ingresa la opcion 1 de la pregunta: ");
        scanf(" %[^\n]",preguntaAModificar.opcion1);
    } while (strlen(preguntaAModificar.opcion1)<0);


    do{
        printf("Ingresa la opcion 2 de la pregunta: ");
        scanf(" %[^\n]",preguntaAModificar.opcion2);
    } while (strlen(preguntaAModificar.opcion2)<0);


    do {
        printf("Ingresa la opcion 3 de la pregunta:");
        scanf(" %[^\n]",preguntaAModificar.opcion3);
    } while (strlen(preguntaAModificar.opcion3)<0);


    do {
        printf("Ingresa la opcion 4 de la pregunta:");
        scanf(" %[^\n]",preguntaAModificar.opcion4);

    } while (strlen(preguntaAModificar.opcion4)<0);

    do {
        printf("Ingresa la respuesta correcta (1-4):");
        scanf(" %d",&preguntaAModificar.respuestaCorrecta);

    } while (preguntaAModificar.respuestaCorrecta<1||preguntaAModificar.respuestaCorrecta>4);
    guardarPreguntaModificada(preguntaAModificar);
}





// Funcion que busca la pregunta por id para mostrarla
Pregunta ObtenerPreguntaPorId(int *idPregunta){
    Pregunta preguntas[MAX_PREGUNTAS];
    leerPreguntasDesdeArchivo(preguntas);
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







// Funcion para mostrar una pregunta por id
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

// Funcion para apartado mostrar preguntas.
void subMenuMostrarPreguntas(){
    int opcion;
    printf("Menu Mostrar Preguntas\n");
    printf("1-Mostrar Preguntas por Capitulo.\n");
    printf("2-Mostrar todas las preguntas almacenadas.\n");
    printf("0-Salir del menu mostrar preguntas.\n");
    printf("Ingresa una opcion:");
    do {
        printf("Ingresa una opcion:");
        scanf(" %d",&opcion);
        switch (opcion)
        {
            case 1:
                //mostrarPreguntasPorCapitulo();
                break;
            case 2:
                mostrarPreguntas();
                break;
            case 0:
                printf("Fin seccion mostrar preguntas.\n");
                break;
        }

    } while (opcion<0 || opcion>2);

}



// Funcion para mostrar todas las preguntas almacenadas
void mostrarPreguntas(){
    Pregunta preguntas[MAX_PREGUNTAS];
    obtenerTodasLasPreguntas(preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].id == -1){
            break;
        }
        printf("Pregunta %d\n",i+1);
        printf("Capitulo %s\n",preguntas[i].capitulo.nombreCap);
        printf("SubCapitulo %s\n",preguntas[i].subCapitulo.nombreSubCap);
        printf("Pregunta: %s\n",preguntas[i].pregunta);
        printf("Opcion 1: %s\n",preguntas[i].opcion1);
        printf("Opcion 2: %s\n",preguntas[i].opcion2);
        printf("Opcion 3: %s\n",preguntas[i].opcion3);
        printf("Opcion 4: %s\n",preguntas[i].opcion4);
        printf("Respuesta Correcta: %d\n",preguntas[i].respuestaCorrecta);
    }

}

// Submenu eliminar pregunta
void subMenuEliminarPregunta(){
    int opcion,id;
    Pregunta pregunta;
    printf("Menu Eliminar Pregunta\n");
    printf("1-Eliminar Pregunta por id.\n");
    printf("0-Salir del menu eliminar pregunta.\n");
    do{
        printf("Ingresa una opcion:");
        scanf(" %d",&opcion);
        switch (opcion)
        {
            case 1:
                do{
                  printf("Ingresa el id de la pregunta a eliminar:");
                    scanf(" %d",&id);
                    if(verSiExistePregunta(id) == 0){
                        printf("La pregunta no existe.\n");
                    }
                    else{
                        printf("La pregunta existe.\n");
                        pregunta.id=id;
                        eliminarPregunta(pregunta);
                    }
                } while (verSiExistePregunta(id) == 0);
                    break;
            case 0:
                printf("Fin seccion eliminar preguntas.\n");
                break;
        }

    } while (opcion<0 || opcion>1);
}




// Funcion para mostrar preguntas por capitulo y subcapitulo

void mostrarPreguntasPorSubCapitulo(int idCapitulo,int idSubCapitulo, Pregunta preguntas[MAX_PREGUNTAS]){
    //obtenerPreguntasPorSubCapitulo(idCapitulo,idSubCapitulo,preguntas);
    for (int i=0;i<MAX_PREGUNTAS;i++){
        if (preguntas[i].id == -1){
            break;
        }
        printf("id:%d|Capitulo:%s|SubCapitulo %s|Pregunta: %s|Opcion 1: %s|Opcion 2: %s|Opcion 3: %s|Opcion 4: %s|Respuesta Correcta: %d",
               preguntas[i].id,
               preguntas[i].capitulo.nombreCap,
               preguntas[i].subCapitulo.nombreSubCap,
               preguntas[i].pregunta,
               preguntas[i].opcion1,
               preguntas[i].opcion2,
               preguntas[i].opcion3,
               preguntas[i].opcion4,
               preguntas[i].respuestaCorrecta);

    }
}
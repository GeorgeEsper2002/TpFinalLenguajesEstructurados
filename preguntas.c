/*
 * Este archivo se va a encargar de crear todas las funciones relacionadas
 * con el apartado 1 del trabajo, ingresar las preguntas y almacenarlas.
 */
/*
 * struct pregunta{
    int nPregunta;
    char pregunta;
    int nCapitulo;
    char nombreCap[30];
    int nSubCapitulo;
    char nombreSubCap[30];
    char opciones[5][30];
};
    int n;
    scanf(" %i",&n);
    printf("%i",n);
 */
#include <string.h>
#include <stdlib.h>
#include "main.c" // con esto se incluye el archivo main.c y todos sus contenidos
#define T 1000
// Declaracion Funciones
void ingresarPreguntas(struct pregunta preguntas[T]);


// Definicion Funciones

void ingresarPreguntas(struct pregunta preguntas[T]){
    int n,bandera;
    printf("Ingresa la cantidad de preguntas:");
    scanf(" %d",&n);
    for (int i = 0; i < n; ++i)
    {
        do{
            do {
                printf("Ingresa el numero de la pregunta:");
                scanf(" %d",&preguntas[i].nPregunta);
            } while (preguntas[i].nPregunta<0);
            do {
                printf("Ingresa el numero de capitulo de la pregunta %d",preguntas[i].nPregunta);
            } while (preguntas[i].nCapitulo);
            do {
                printf("Ingresa el nombre del capitulo %d",preguntas[i].nCapitulo);
                fgets(preguntas[i].nombreCap,sizeof(preguntas[i].nombreCap),stdin); // Lee la entrada del usuario
                preguntas[i].nombreCap[strcspn(preguntas[i].nombreCap, "\n")] = 0; // Elimina el enter al ingresar
            } while (strlen(preguntas[i].nombreCap) == 0); // sigue iterando si el string esta vacio.

            do {
                printf("Ingresa el numero de subcapitulo de la pregunta %s :",preguntas[i].nombreCap);
                scanf(" %d",&preguntas[i].nSubCapitulo);

            }while(preguntas[i].nSubCapitulo<0);

            do {
                printf("Ingresa el nombre de subcapitulo %d capitulo %s y numero %d",preguntas[i].nSubCapitulo,preguntas[i].nombreCap,preguntas[i].nCapitulo);
                fgets(preguntas[i].nombreSubCap,sizeof(preguntas[i].nombreCap),stdin);
                preguntas[i].nombreSubCap[strcspn(preguntas[i].nombreSubCap, "\n")] = 0;
            } while (strlen(preguntas[i].nombreSubCap) == 0);

            do {
                printf("Ingresa la pregunta del subcapitulo %s:",preguntas[i].nombreSubCap);
                fgets(preguntas[i].pregunta,sizeof(preguntas[i].pregunta),stdin);
                preguntas[i].pregunta[strcspn(preguntas[i].pregunta, "\n")]=0;
            } while (strlen(preguntas[i].pregunta) == 0);
            do {
                do{
                    printf("%s\n",preguntas[i].pregunta);
                    printf("Ingresa la respuesta 1:");
                    fgets(preguntas[i].opciones[0],sizeof(preguntas[i].pregunta),stdin);
                    preguntas[i].opciones[0][strcspn(preguntas[i].opciones[0], "\n")] = 0;
                } while (strlen(preguntas[i].opciones[0] ) == 0);
                /*do{

                } while ();
                do{

                } while();
                do{

                }while();
                do{

                } while ();

            } while ();
                 */








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
/*
 * Este archivo se va a encargar de crear todas las funciones relacionadas
 * con el apartado 1 del trabajo, ingresar las preguntas y almacenarlas.
 */
/*
 * struct Pregunta{
    int nPregunta;
    char Pregunta;
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
void ingresarPreguntas(Pregunta preguntas[T]);


// Definicion Funciones

void ingresarPreguntas(Pregunta preguntas[T]){
    int n,bandera;
    printf("Ingresa la cantidad de preguntas:");
    scanf(" %d",&n);
    for (int i = 0; i < n; ++i)
    {
        do{

            do {
                printf("Ingresa el numero de capitulo de la Pregunta %d",preguntas[i].nCapitulo);
                scanf(" %d",&preguntas[i].nCapitulo);
            } while (preguntas[i].nCapitulo<0);
            do {
                printf("Ingresa el nombre del capitulo %d",preguntas[i].nCapitulo);
                fgets(preguntas[i].nombreCap,sizeof(preguntas[i].nombreCap),stdin); // Lee la entrada del usuario
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

            } while(strlen(preguntas[i].opciones[3] ) == 0);
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
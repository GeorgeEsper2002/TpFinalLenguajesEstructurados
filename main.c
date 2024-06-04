#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct pregunta{
    char pregunta;
    char opt1[30];
    char opt2[30];
    char opt3[30];
    char opt4[30];
    int correcta;
};
int main() {
    printf("Hello, World!\n");
    char saludo[20];
    //scanf(" %s",&saludo); no permite ingresar palabras separadas por espacios en blanco
    gets(saludo);
    puts(saludo);
    //strcat(saludo,);
    return 0;
}

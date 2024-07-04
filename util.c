//
// Created by Usuario on 3/7/2024.
//

#include "util.h"
#include <stdio.h>
int validarFecha(char date[20]){
    int dia, month, year;
    if (sscanf(date, "%d/%d/%d", &dia, &month, &year) != 3) {
        printf("Fecha Invalida.\n");
        return 0;
    }
    if (dia < 1 || dia > 31 || month < 1 || month > 12 || year < 1900 || year > 9999) {
        printf("Fecha Invalida.\n");
        return 0;
    }
    return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int pedirentero(char* mensaje, int maximo, int minimo);

int main()
{
    int edad;

    edad=pedirentero("Ingrese edad (entre 1 y 199): ", 200, 1);
    printf("Su edad es: %d", edad);

    return 0;
}



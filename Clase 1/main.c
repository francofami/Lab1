#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    /*
    Mascaras de entrada:
    int: %d
    float: %f
    char: %c
    */

    int numero1=88;
    float numero2=33.2232;

    printf("El numero entero es: %d \nEl numero flotante es: %.2f \n", numero1, numero2); //El .2 hace que me muestre 2 decimales despues de la coma


    /*
    \n = salto de línea
    \a = suena el speaker del mother
    \t = salta a otra columna
    */
    getch();
    return 0;
}

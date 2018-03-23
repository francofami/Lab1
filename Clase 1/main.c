#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Mascaras de entrada:
    int: %d
    float: %f
    char: %cscanf("%c",&letra);
    */

    int numero1;
    float numero2;
    float suma;
    char letra;

    printf("Ingrese un numero entero: ");
    scanf("%d", &numero1);
    printf("Ingrese un numero con coma: ");
    scanf("%f", &numero2);
    printf("Ingrese una letra: ");
    letra = getche();

    //letra=getch(); Cuando apretemos una tecla no se dibuja en pantalla
    //letra=getche(); Cuando apretemos una tecla se va a dibujar en pantalla
    //fflush(stdin); Opcion para limpiar el buffer de entrada para que podamos ingresar un caracter se pone antes de scanf("%c",&letra);
    //scanf(" %c", &letra); Otra opcion: dejo un espacio entre " y % para que me lea el caracter.

    suma=numero1+numero2;

    printf("\nEl numero entero es: %d \nEl numero flotante es: %.2f \n", numero1, numero2); //El .2 hace que me muestre 2 decimales despues de la coma
    printf("La suma de los numeros es: %.2f\n",suma);
    printf("La letra es: %c\n", letra);



    /*
    \n = salto de línea
    \a = suena el speaker del mother
    \t = salta a otra columna
    */
    getch();
    return 0;
}

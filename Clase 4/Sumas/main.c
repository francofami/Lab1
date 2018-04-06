#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

    void sumar1();
    void sumar2(int n1, int n2);
    int sumar3();
    int sumar4(int, int);

int main()
{
    int resultado, resultadoSumar4;
    int numero1, numero2;

    /* Prototipo 1*/
    sumar1();

    /* Prototipo 2*/
    sumar2(4,9);

    /* Prototipo 3*/
    resultado=sumar3();
    printf("La suma es %d", resultado);

    /* Prototipo 4*/
    resultadoSumar4=sumar4();

    return 0;
}

void sumar1()
{
    int numero1;
    int numero2;
    int suma;

    numero1=pedirentero("Ingrese un numero: ", 1000, 1);
    numero2=pedirentero("Ingrese un numero: ", 1000, 1);

    suma=numero1+numero2;
    printf("La suma es: %d", suma);
}

void sumar2(int n1, int n2)
{
    int suma;

    suma = n1+n2;
    printf("La suma es: %d", suma);
}

int sumar3()
{
    int numero1;
    int numero2;
    int suma=-1;

    numero1=pedirentero("Ingrese un numero: ", 1000, 1);
    numero2=pedirentero("Ingrese un numero: ", 1000, 1);

    suma=numero1+numero2;

    return suma;
}

int suma4()
{
    int numero1, numero2;
    int suma=-1;


    suma=numero1+numero2;

    return suma;
}

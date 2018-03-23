#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Se ingresan numeros (!=0), no se sabemos cuantos.
    Se pide mostrar:
        * Cantidad de pares e impares.
        * Porcentaje de numeros positivos y negativos.
        * Máximo y mínimo
        * Máximo número par.
        * Cantidad de números comprendidos entre 125 y 236.
    */

    float porcentajePositivos, porcentajeNegativos;
    char respuesta;
    int contadorPares=0, contadorImpares=0, contadorPositivos=0, contadorNegativos=0, contador=0, contadorDos=0, numero, maximo, minimo, maximopar=0;

    do
    {
        contador++;

        printf("Ingrese numero (distinto de 0): ");
        scanf("%d", &numero);

        while(numero==0)
        {
            printf("¡Error! Ingrese numero (distinto de 0): ");
            scanf("%d", &numero);
        }

        if(numero%2 == 0)
        {
            contadorPares++;
        }
        else
        {
            contadorImpares++;
        }

        if(numero<0)
        {
            contadorNegativos++;
        }
        else
        {
            contadorPositivos++;
        }

        if(contador==1)
        {
            minimo=numero;
            maximo=numero;
        }
        else if(minimo>numero)
        {
            minimo=numero;
        }
        if(maximo<numero)
        {
            maximo=numero;
        }

        if(maximopar<numero && numero%2==0)
        {
            maximopar=numero;
        }


        if(numero>=125 && numero<=236)
        {
            contadorDos++;
        }

        printf("Ingrese n para salir: \n");
        respuesta = getch();
    } while(respuesta!='n');

    /* Como en el resultado quiero mostrar un porcentaje con resultado en float pero estoy dividiendo dos int
    tengo que hacer un "casteo explícito" que es pasar un int a un float en este caso (tipo de variable numerica a otra)
    variablefloat=(float)int/int; */

    porcentajeNegativos=(float)(contadorNegativos*100)/contador;
    porcentajePositivos=100-porcentajeNegativos;

    printf("La cantidad de pares es: %d\n", contadorPares);
    printf("La cantidad de impares es: %d\n", contadorImpares);
    printf("El porcentaje de numeros positivos es: %.2f\n", porcentajePositivos);
    printf("El porcentaje de numeros negativos es: %.2f\n", porcentajeNegativos);
    printf("El maximo es: %d\n", maximo);
    printf("El minimo es: %d\n", minimo);
    if(maximopar!=0)
    printf("El maximo numero par es: %d\n", maximopar);
    else
        printf("No hay maximo numero par.\n");
    printf("La cantidad de numeros comprendidos entre 125 y 236 es: %d", contadorDos);

    getch();
    return 0;
}

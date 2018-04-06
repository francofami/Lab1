#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main()
{
    int numero, respuesta=1, i;

    printf("Ingrese numero para calcular su factorial: ");
    scanf("%d", &numero);

    /* for(i=numero;i>=1;i--)
    {
        respuesta= respuesta*i;
    }
    */

    respuesta=factorial(numero);

    printf("El factorial de %d es %d", numero, respuesta);

    return 0;
}

int factorial(int numero)
{
    int respuesta;

    if(numero==0)
    respuesta=1;
    respuesta= numero*factorial(numero-1);
    return respuesta;
}

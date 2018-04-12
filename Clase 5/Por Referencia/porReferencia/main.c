#include <stdio.h>
#include <stdlib.h>
#define cantidad 5

void cambiarEntero(int numero);
void cambiarVector(int listadoDeNumeros[]);
void cambiarVectorEnMenosUno(int listado[]);

int main()
{
    int edades[3];
    int edad=22;
    int listado[cantidad];
    int lenghtVector, lenghtElemento, lenghtElementos;
    cambiarEntero(edad);
    printf("%d\n", edad);
    cambiarVector(edades);
    printf("%d\n", edades[0]);
    cambiarVectorEnMenosUno(listado);

    //Para sacar el tamaño de un vector lo hago en el main y no en la funcion void:
    lenghtVector=sizeof(listado);
    lenghtElemento=sizeof(listado[0]);
    lenghtElementos=lenghtVector/lenghtElemento;
    printf("El vector tiene: %d elementos.",lenghtElementos);


    return 0;
}

void cambiarEntero(int numero)
{
    numero=666;
}

void cambiarVector(int listadoDeNumeros[])
{
    listadoDeNumeros[0]=666;
}

void cambiarVectorEnMenosUno(int listado[])
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        listado[i]=-1;
    }
}

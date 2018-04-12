#include "funcionesVectores.h"

int dameEnteroEntre(int min, int max);
float dameUnFlotanteEntre(int min, int max);

void ejemploCargaSecuencial()
{
    int i;
    float precioAux;
    float listadoPrecios[5];

    i=dameEnteroEntre(0,4);

    precioAux=dameUnFlotanteEntre(1,1000);

    listadoPrecios[i]= precioAux;

    for(i=0;i<5;i++)
    {
        printf("El valor de la posicion %d es: %f\n",i,listadoPrecios[i]);
    }
}

int dameEnteroEntre(int min, int max)
{
    int i;

    do{
       printf("Ingrese un entero entre 0 y 4: ");
    scanf("%d", &i);
    }while(!(i>=min && i<max));

    return i;
}

float dameUnFlotanteEntre(int min, int max)
{
    float precioAux;

    do{
       printf("Ingrese un entero entre 1 y 1000: ");
    scanf("%f", &precioAux);
    }while(!(precioAux>=min && precioAux<max));

    return precioAux;
}


#include <stdio.h>
#include <stdlib.h>

int cargarArray(int* puntero, int);
void mostrarArray(int* puntero, int);

int main()
{
    int vector[3];
    //int* puntero;
    //int i;

    //puntero=vector; //Saco la direccion de memoria del primer elemento del vector.

    if(cargarArray(vector,3)) //If analiza un valor booleano: 0=false cualquier otro num=true
        printf("Carga exitosa!!!!\n");
    else
        printf("Error al cargar los datos.\n");

    mostrarArray(vector,3);

    /*for(i=0;i<3;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", puntero+i);
        //Donde i son los bytes del tipo de dato del puntero.
        //A la direccion de memoria le voy sumando 4 bytes (en caso de ser int),
        //es decir, voy cargando un dato atras de otro
    }


    for(i=0;i<3;i++)
    {
        printf("%d\n",*(puntero+i));
    }*/


    return 0;
}

int cargarArray(int* array, int length)
{
    int i, retorno=0;

    if(array!=NULL)
    {
        retorno=1;

        for(i=0;i<length;i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", array+i);
        }
    }

    return retorno;
}

void mostrarArray(int* array, int length)
{
    int i;

    for(i=0;i<length;i++)
    {
        printf("%d\n",*(array+i));
    }
}

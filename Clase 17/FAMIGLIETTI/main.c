#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
#include "numeroNatural.h"

int main()
{
    char seguir='s';
    int opcion=0,i;
    ArrayList* lista;
    FILE* pFile;

    lista=al_newArrayList();

    while(seguir=='s')
    {
        printf("\n1- Altas\n2- Completar par, impar, primo\n3- Generar archivo\n4- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);

        //system("cls");

        switch(opcion)
        {
            case 1:
                {
                    parserDatos(pFile, lista);
                }
                break;
            case 2:
                {
                    completar(pFile, lista);
                }
                break;
            case 3:
                {
                    generarArchivo(pFile, lista);
                }
                break;
            default:
                seguir=='n';
        }

    }

    return 0;
}

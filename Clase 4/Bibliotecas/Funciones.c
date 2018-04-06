#include <stdio.h>
#include "Funciones.h"

int pedirentero(char* mensaje, int maximo, int minimo)
{
    int ed=-1;

    do{
        printf("%s", mensaje);
        scanf("%d", &ed);

        if(ed<maximo && ed>=minimo)
        {
            break;
        }
    }while(1==1);

    return ed;
}

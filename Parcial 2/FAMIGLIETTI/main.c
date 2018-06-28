#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
#include "empleados.h"

int main()
{
    FILE *fp;
    char seguir='s';
    int opcion=0,i;

    ArrayList* pList;
    empleados* aux;

    pList=al_newArrayList();

    while(seguir=='s')
    {
        printf("1- Levantar archivo y crear lista\n");
        printf("2- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    parserEmpleados(fp,pList);
                }
                break;
            case 2:
                {
                    seguir='n';
                }
                break;
            default:
                seguir='n';
        }
    }

    return 0;
}

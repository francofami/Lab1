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
    ArrayList* listaFiltrada;

    pList=al_newArrayList();

    while(seguir=='s')
    {
        printf("\n1- Levantar archivo y crear lista\n");
        printf("2- Obtener lista filtrada (Programadores con edad mayor a 30)\n");
        printf("3- Generar archivo con lista filtrada\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                    parserEmpleados(fp,pList);
                }
                break;
            case 2:
                {
                    listaFiltrada=al_filter(pList,funcionQueFiltra);

                    empleados_printAll(listaFiltrada);
                }
                break;
             case 3:
                {
                    crearArchivo(fp, listaFiltrada);
                }
                break;
            default:
                seguir='n';
        }
    }

    return 0;
}

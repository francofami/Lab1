#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

//Lee desde el archivo cada empleado y lo carga en el arraylist
int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int retorno;
    int r;
    int a,b,c,d;

    pFile=fopen("data.csv", "r");

    if(pFile == NULL)
    {
        printf("El archivo no existe");
        retorno= -1;
    }
    do
    {
        al_add(ArrayList* pList,void* pElement)

        r=fscanf(pFile,"%d,%s,%s,%d\n",&a,&b,&c,&d);


        if(r==4)
        {
           printf("Lei %d %s %s %d\n",a,b,c,d);
        }
        else
        break;
    }while(!feof(pFile));

    fclose(pFile);

    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

//Lee desde el archivo cada empleado y lo carga en el arraylist
int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    Employee* empleado;
    int retorno=-1;
    char id[4096];
    char nombre[4096];
    char apellido[4096];
    char edad[4096];
    char estado[4096];

    if(pFile!=NULL)
    {
        pFile=fopen("data.csv", "r");

        do
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,estado);
            empleado = employee_newParametros(id, nombre, apellido, estado);
            al_add(pArrayListEmployee, empleado);

        }while(!feof(pFile));

    fclose(pFile);
    retorno=0;

    return retorno;
    }
}

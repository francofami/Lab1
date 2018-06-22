#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    //Primero debo crear un arraylist en memoria
    ArrayList* pList;
    Employee* eAux;
    int i;
    FILE* fp;

    pList=al_newArrayList();

    parserEmployee(fp, pList);

    for(i=0;i<al_len(pList);i++)
    {
        employee_print(al_get(pList,i));
    }

    return 0;
}

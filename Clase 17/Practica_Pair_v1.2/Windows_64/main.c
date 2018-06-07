#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

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
    ArrayList* lista;
    Employee* e1;
    Employee* e2;
    Employee* eAux;
    int intAux,i;

    lista=al_newArrayList();

    e1=employee_new();
    e2=employee_new();

    e1->id=666;
    strcpy(e1->name,"Juan");
    strcpy(e1->lastName,"Gomez");
    e1->isEmpty=1;

    e2->id=667;
    strcpy(e2->name,"Fernando");
    strcpy(e2->lastName,"Fernandez");
    e2->isEmpty=1;

    al_add(lista,e1); //Debo pasar e1 al Arraylist
    al_add(lista,e2);

    intAux=al_len(lista);
    printf("Cant elementos: %d\n",intAux);

    al_sort(lista, employee_compare, 1);


    //Si quiero borrar a uno
    al_remove(lista,al_indexOf(lista, e1));
    employee_delete(e1);


    intAux=al_len(lista);
    printf("Cant elementos despues de eliminar: %d\n",intAux);


    for(i=0;i<intAux;i++)
    {
        eAux=(Employee*)al_get(lista, i); //Casteo para guardarlo como tipo de Employee*, uso el getter que me trae la posicion i de la lista
        employee_print(eAux);
    }

    return 0;
}

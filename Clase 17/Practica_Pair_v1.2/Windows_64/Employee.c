#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* e1;
    Employee* e2;

    e1=(Employee*)pEmployeeA;//casteo
    e2=(Employee*)pEmployeeB;

    return (stricmp(e1->name,e2->name));
}


void employee_print(Employee* this)
{
    printf("ID: %d\n", this->id);
    printf("Nombre: %s\n",this->name);
    printf("Apellido: %s\n", this->lastName);
    printf("estado: %d\n", this->isEmpty);
}


Employee* employee_new(void)
{
    Employee* returnAux;
    returnAux = (Employee*)malloc(sizeof(Employee));

    return returnAux;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this, int id)
{
    int retorno=-1;

    if(this!=NULL && id>0)
    {
        retorno=1;
        this->id = id;
    }

    return retorno;
}

int employee_getId(Employee* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id;
    }

    return retorno;
}

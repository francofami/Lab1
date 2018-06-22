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
    if(this->isEmpty!=-1)
    {
        printf("ID: %d ", this->id);
        printf("Nombre: %s ",this->name);
        printf("Apellido: %s ", this->lastName);
        printf("estado: %d\n", this->isEmpty);
    }
}

Employee* employee_new(void)
{

    Employee* returnAux = (Employee*) malloc(sizeof(Employee));
    return returnAux;

}

Employee* employee_newParametros(char* id, char* nombre, char* apellido, char* estado)
{
    int idEntero;
    int estadoEntero=0;
    Employee* returnAux;

    idEntero=atoi(id);

    if(strcmp(estado,"true")==0)
    {
        estadoEntero=1;
    }
    if(strcmp(estado,"is_empty")==0)
    {
        estadoEntero=-1;
    }

    returnAux = employee_new();

    employee_setId(returnAux,idEntero);
    employee_setNombre(returnAux, nombre);
    employee_setApellido(returnAux, apellido);
    employee_setEstado(returnAux, estadoEntero);

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

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno=-1;

    if(this!=NULL)
    {
      retorno=1;
      strcpy(this->name,nombre);
    }

    return retorno;
}

int employee_getNombre(Employee* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->name;
    }

    return retorno;
}

int employee_setApellido(Employee* this, char* apellido)
{
    int retorno=-1;

    if(this!=NULL)
    {
      retorno=1;
      strcpy(this->lastName,apellido);
    }

    return retorno;
}

int employee_getApellido(Employee* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->lastName;
    }

    return retorno;
}


int employee_setEstado(Employee* this, int estado)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=1;
        this->isEmpty=estado;
    }

    return retorno;
}

int employee_getEstado(Employee* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->isEmpty;
    }

    return retorno;
}

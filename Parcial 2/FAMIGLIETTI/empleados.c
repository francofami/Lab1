#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "empleados.h"

empleados* empleados_new(void)
{
    empleados* returnAux = (empleados*) malloc(sizeof(empleados));
    return returnAux;
}

empleados* empleados_newParametros(int id, char* nombre, char* sueldo, int edad, char* profesion)
{
    empleados* this;

    this = empleados_new();

     if(!empleados_setId(this,id) &&
        !empleados_setNombre(this,nombre) &&
        !empleados_setSueldo(this,sueldo) &&
        !empleados_setEdad(this,edad) &&
        !empleados_setProfesion(this,profesion)
       )
    {
        return this;
    }

    empleados_delete(this);

    return NULL;
}

void empleados_delete(empleados* this)
{
    if(this != NULL)
    free(this);
}

int empleados_setId(empleados* this, int id)
{
    int retorno=-1;

    if(this!=NULL && id>0)
    {
        retorno=0;

        this->id=id;
    }

    return retorno;
}

int empleados_getId(empleados* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id;
    }

    return retorno;
}

int empleados_setNombre(empleados* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int empleados_getNombre(empleados* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->nombre;
    }

    return retorno;
}

int empleados_setSueldo(empleados* this, char* sueldo)
{
    int retorno=-1;

    if(this!=NULL && sueldo!=null)
    {
        retorno=0;
        strcpy(this->sueldo,sueldo);
    }

    return retorno;
}

int empleados_getSueldo(empleados* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->sueldo;
    }

    return retorno;
}

int empleados_setEdad(empleados* this, int edad)
{
    int retorno=-1;

    if(this!=NULL && edad>=0)
    {
        retorno=0;

        this->edad=edad;
    }

    return retorno;
}

int empleados_getEdad(empleados* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->edad;
    }

    return retorno;
}

int empleados_setProfesion(empleados* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL)
    {
        retorno = 0;
        strcpy(this->profesion,profesion);
    }
    return retorno;
}

int empleados_getProfesion(empleados* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->profesion;
    }

    return retorno;
}

void empleados_print(empleados* this)
{
    int id;
    char nombre[51];
    char sueldo[50];
    int edad;
    char profesion[50];

    if(this != NULL)
    {

        id=empleados_getId(this);
        strcpy(nombre,empleados_getNombre(this));
        strcpy(sueldo,empleados_getSueldo(this));
        edad=empleados_getEdad(this);
        strcpy(profesion,empleados_getProfesion(this));

        printf("%d\t%s\t\t%s\t\t%d\t%s\n", id,nombre, sueldo, edad, profesion);
    }

}

void empleados_printAll(ArrayList* this)
{
    int i;
    int length;
    empleados* aux;

    length=this->len(this);

    printf("\nID\tNombre\t\tSueldo\t\tEdad\tProfesion\n");

    for(i=0;i<length;i++)
    {
        aux=this->get(this,i);

        if(aux!=NULL)
        {
            empleados_print(aux);
        }
    }
}

int funcionQueFiltra(void* item)
{
    int retorno=0;

    empleados* aux;
    aux = (empleados*) item;

    if(stricmp(empleados_getProfesion(aux),"Programador")==0 && empleados_getEdad(aux)>30)
    {
        retorno=1;
    }

    return retorno;
}

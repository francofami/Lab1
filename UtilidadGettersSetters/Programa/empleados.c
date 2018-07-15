#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "ArrayList.h"

empleados* empleados_new(void)
{
	empleados* returnAux = (empleados*) malloc(sizeof(empleados));
	return returnAux;
} 

int empleados_setid(empleados* this, int id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		this->id=id;
	}

	return retorno;
}

int empleados_getid(empleados* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->id;
	}

	return retorno;
}

int empleados_setnombre(empleados* this, char* nombre)
{
	int retorno=-1;

	if(this!=NULL && nombre!=NULL)
	{
		retorno=0;
		strcpy(this->nombre,nombre);
	}
	return retorno;
}

int empleados_getnombre(empleados* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->nombre;
	}

	return retorno;
}
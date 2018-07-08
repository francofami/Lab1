#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#include "productos.h"

productos* productos_new(void)
{
    productos* returnAux = (productos*) malloc(sizeof(productos));
    return returnAux;
}


void productos_delete(productos* this)
{
    if(this != NULL)
        free(this);
}

int productos_setCodigo(productos* this, int codigo)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->codigo = codigo ;
    }
    return retorno;
}

int productos_getCodigo(productos* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->codigo;
    }

    return retorno;
}

int productos_setDescripcion(productos* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(this->descripcion,descripcion);
    }
    return retorno;
}

int productos_getDescripcion(productos* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->descripcion;
    }

    return retorno;
}

int productos_setImporte(productos* this, float importe)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->importe= importe ;
    }
    return retorno;
}

int productos_getImporte(productos* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->importe;
    }

    return retorno;
}

int productos_setCantidad(productos* this, int cantidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->cantidad = cantidad;
    }
    return retorno;
}

int productos_getCantidad(productos* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->cantidad;
    }

    return retorno;
}

int productos_setActivo(productos* this, int activo)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->activo = activo;
    }
    return retorno;
}

int productos_getActivo(productos* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->activo;
    }

    return retorno;
}

void productos_print(productos* this)
{
    int codigo;
    char descripcion[51];
    float importe;
    int cantidad;

    if(this != NULL)
    {

        if(productos_getActivo(this)==1)
        {
            codigo=productos_getCodigo(this);
            strcpy(descripcion,productos_getDescripcion(this));
            importe=productos_getImporte(this);
            cantidad=productos_getCantidad(this);

            printf("%d\t%.2f\t%d\t\t%s\n", codigo,importe, cantidad, descripcion);
        }

    }

}

void productos_printAll(ArrayList* this)
{
    int i;
    int length;
    productos* aux;

    length=this->len(this);

    printf("\nCodigo\tImporte\tCantidad\t\tDescripcion\n");

    for(i=0;i<length;i++)
    {
        aux=this->get(this,i);

        if(aux!=NULL)
        {
            productos_print(aux);
        }
    }
}

int compararPorDescripcion(void* productoA, void* productoB)
{
    int retorno=-5;

    productos* producto1;
    productos* producto2;

    producto1 = (productos*) productoA;
    producto2 = (productos*) productoB;

    retorno=strcmp(producto1->descripcion, producto2->descripcion);

    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "numeroNatural.h"


numeroNatural* numeroNatural_new(void)
{
    numeroNatural* returnAux = (numeroNatural*) malloc(sizeof(numeroNatural));
    return returnAux;
}

numeroNatural* numeroNatural_newParametros(int id, int numero, char* nombre, int par, int impar, int primo)
{
    numeroNatural* this;

    this = numeroNatural_new();

     if(!numeroNatural_setId(this,id) &&
        !numeroNatural_setNumero(this,numero) &&
        !numeroNatural_setNombre(this,nombre) &&
        !numeroNatural_setPar(this,par) &&
        !numeroNatural_setImpar(this,impar) &&
        !numeroNatural_setPrimo(this,primo)
       )
    {
        return this;
    }

    numeroNatural_delete(this);

    return NULL;
}

void numeroNatural_delete(numeroNatural* this)
{
    if(this != NULL)
    free(this);
}

int numeroNatural_setNumero(numeroNatural* this, int numero)
{
    int retorno=-1;

    if(this!=NULL && numero>=0)
    {
        retorno=0;

        this->numero=numero;
    }

    return retorno;
}

int numeroNatural_getNumero(numeroNatural* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->numero;
    }

    return retorno;
}

int numeroNatural_getId(numeroNatural* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id;
    }

    return retorno;
}

int numeroNatural_setPar(numeroNatural* this, int par)
{
    int retorno=-1;

    if(this!=NULL && (par==0 || par==1))
    {
        retorno=0;

        this->par=par;
    }

    return retorno;
}

int numeroNatural_getPar(numeroNatural* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->par;
    }

    return retorno;
}

int numeroNatural_setImpar(numeroNatural* this, int impar)
{
    int retorno=-1;

    if(this!=NULL && (impar==0 || impar==1))
    {
        retorno=0;

        this->impar=impar;
    }

    return retorno;
}

int numeroNatural_setId(numeroNatural* this, int id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=0;

        this->id=id;
    }

    return retorno;
}

int numeroNatural_getImpar(numeroNatural* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->impar;
    }

    return retorno;
}

int numeroNatural_setPrimo(numeroNatural* this, int primo)
{
    int retorno=-1;

    if(this!=NULL && (primo==0 || primo==1))
    {
        retorno=0;

        this->primo=primo;
    }

    return retorno;
}

int numeroNatural_getPrimo(numeroNatural* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->primo;
    }

    return retorno;
}

int numeroNatural_setNombre(numeroNatural* this, char* nombre)
{
    int retorno = -1;
    int largo;

    largo=strlen(nombre);

    if(this != NULL && nombre != NULL && largo<=50)
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int numeroNatural_getNombre(numeroNatural* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->nombre;
    }

    return retorno;
}

void numeroNatural_print(numeroNatural* this)
{
    int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;
    int id;

    if(this != NULL)
    {

        numero=numeroNatural_getNumero(this);
        strcpy(nombre,numeroNatural_getNombre(this));
        par=numeroNatural_getPar(this);
        impar=numeroNatural_getImpar(this);
        primo=numeroNatural_getPrimo(this);
        id=numeroNatural_getId(this);


        printf("%d\t%d\t%d\t%d\t%d\t%s\n",id, numero, par, impar, primo,nombre);
    }

}

void numeroNatural_printAll(ArrayList* this)
{
    int i;
    int length;
    int opcion=0;
    numeroNatural* aux;

    length=this->len(this);

    printf("\nId\tNum\tPar\tImpar\tPrimo\tNombre\n");

    for(i=0;i<length;i++)
    {
        aux=this->get(this,i);

        if(aux!=NULL)
        {
            numeroNatural_print(aux);

        if(i==10)
        {
            printf("desea seguir mostrando 1- si 2-no");
            fflush(stdin);
            scanf("%d",&opcion);

            if(opcion==2)
            {
                break;
            }
        }

        }



    }
}

int esPar(numeroNatural* this)
{
    int retorno=0;

    if((this->numero)%2==0)
    {
        retorno=1;
    }

    return retorno;
}

int esImpar(numeroNatural* this)
{
    int retorno=0;

    if((this->numero)%2!=0)
    {
        retorno=1;
    }

    return retorno;

}

int esPrimo(numeroNatural* this)
{
    int i,a=0;
    int retorno=0;

    for(i=1;i<((this->numero)+1);i++)
    {
         if((this->numero)%i==0)
         {
            a++;
        }

    }
         if(a!=2)
        {
              retorno=0;
        }
        else
        {
            retorno=1;

        }

    return retorno;
}

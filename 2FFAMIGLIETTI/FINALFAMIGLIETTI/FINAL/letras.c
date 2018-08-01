#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "letras.h"
#include "ArrayList.h"

eLetra* eLetra_new(void)
{
	eLetra* returnAux = (eLetra*) malloc(sizeof(eLetra));
	return returnAux;
}

int eLetra_setletra(eLetra* this, char letra)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		this->letra=letra;
	}
	return retorno;
}

int eLetra_getletra(eLetra* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->letra;
	}

	return retorno;
}

int eLetra_setnombre(eLetra* this, char* nombre)
{
	int retorno=-1;

	if(this!=NULL && nombre!=NULL)
	{
		retorno=0;
		strcpy(this->nombre,nombre);
	}
	return retorno;
}

int eLetra_getnombre(eLetra* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->nombre;
	}

	return retorno;
}

int eLetra_setvocal(eLetra* this, int vocal)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		this->vocal=vocal;
	}

	return retorno;
}

int eLetra_getvocal(eLetra* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->vocal;
	}

	return retorno;
}

int eLetra_setconsonante(eLetra* this, int consonante)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		this->consonante=consonante;
	}

	return retorno;
}

int eLetra_getconsonante(eLetra* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->consonante;
	}

	return retorno;
}

int eLetra_setnumero(eLetra* this, int numero)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		this->numero=numero;
	}

	return retorno;
}

int eLetra_getnumero(eLetra* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->numero;
	}

	return retorno;
}

int esV(char letra)
{
    char retorno=0;

    if(toupper(letra)=='A' || toupper(letra)=='E' || toupper(letra)=='I' || toupper(letra)=='O' || toupper(letra)=='U')
    {
        retorno=1;
    }

    return retorno;
}

int esC(char letra)
{
    int retorno=0;

    if(!(toupper(letra)=='A' || toupper(letra)=='E' || toupper(letra)=='I' || toupper(letra)=='O' || toupper(letra)=='U'))
    {
        if(letra!='1' && letra!='2' && letra!='0' && letra!='3' && letra!='4' && letra!='5' && letra!='6' && letra!='7' && letra!='8' && letra!='9')
        {
            retorno=1;
        }

    }

    return retorno;
}

int esNum(char numero)
{
    int retorno=0;

    if(isdigit(numero)!=0) //si no es devuelve 0
    {
        retorno = 1;
    }

    return retorno;
}

void eLetra_print(eLetra* this)
{
    char letra;
	char nombre[22];
	int vocal;
	int consonante;
	int numero;

    if(this != NULL && strcmp(eLetra_getnombre(this),"nombre")!=0)
    {
            letra=eLetra_getletra(this);
            strcpy(nombre,eLetra_getnombre(this));
            vocal=eLetra_getvocal(this);
            consonante=eLetra_getconsonante(this);
            numero = eLetra_getnumero(this);

            printf("%c\t%s\t%d\t%d\t\t%d\n", letra,nombre, vocal, consonante, numero);
    }

}

void eLetra_printAll(ArrayList* this)
{
    int i;
    int length;
    eLetra* aux;

    length=this->len(this);

    printf("\nLetra\tNombre\tVocal\tConsonante\tNumero\n");

    for(i=0;i<length;i++)
    {
        aux=this->get(this,i);

        if(aux!=NULL)
        {
            eLetra_print(aux);
        }
    }
}

int compararAlfabeticamente(void* letraA, void* letraB)
{
    int retorno = 0;

    eLetra* letra1;
    eLetra* letra2;

    letra1 = (eLetra*) letraA;
    letra2 = (eLetra*) letraB;

    if(letra1->letra < letra2->letra)
    {
        retorno = -1;
    }

    if(letra1->letra > letra2->letra)
    {
        retorno = 1;
    }

    return retorno;
}

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

int eLetra_setcaracter(eLetra* this, char* caracter)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		this->caracter=caracter;
	}

	return retorno;
}

int eLetra_getcaracter(eLetra* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=this->caracter;
	}

	return retorno;
}

int eLetra_setletra(eLetra* this, char* letra)
{
	int retorno=-1;

	if(this!=NULL && letra!=NULL)
	{
		retorno=0;
		strcpy(this->letra,letra);
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

int eLetra_setvocal(eLetra* this, char* vocal)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		strcpy(this->vocal,vocal);
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

int eLetra_setconsonante(eLetra* this, char* consonante)
{
	int retorno=-1;

	if(this!=NULL)
	{
		retorno=0;
		strcpy(this->consonante,consonante);
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

int esVocalChar(char letra)
{
    int retorno=0;

    if(letra=='a' || letra=='e' || letra=='i' || letra=='o' || letra=='u' || letra=='A' || letra=='E' || letra=='I' || letra=='O' || letra=='U')
    {
        retorno=1;
    }

    return retorno;
}

int esConsonanteChar(char letra)
{
    int retorno=0;

    if(!(letra=='a' || letra=='e' || letra=='i' || letra=='o' || letra=='u' || letra=='A' || letra=='E' || letra=='I' || letra=='O' || letra=='U'))
    {
        if(letra!='1' && letra!='2' && letra!='0' && letra!='3' && letra!='4' && letra!='5' && letra!='6' && letra!='7' && letra!='8' && letra!='9')
        {
            retorno=1;
        }

    }

    return retorno;
}

void eLetra_print(eLetra* this)
{
    char letra[5];
	char nombre[22];
	char vocal[3];
	char consonante[3];

    if(this != NULL && strcmp(eLetra_getnombre(this),"nombre")!=0)
    {
            strcpy(letra,eLetra_getletra(this));
            strcpy(nombre,eLetra_getnombre(this));
            strcpy(vocal,eLetra_getvocal(this));
            strcpy(consonante,eLetra_getconsonante(this));

            printf("%s\t%s\t%s\t%s\n", letra,nombre, vocal, consonante);
    }

}

void eLetra_printAll(ArrayList* this)
{
    int i;
    int length;
    eLetra* aux;

    length=this->len(this);

    printf("\nLetra\tNombre\tVocal\tConsonante\n");

    for(i=0;i<length;i++)
    {
        aux=this->get(this,i);

        if(aux!=NULL)
        {
            eLetra_print(aux);
        }
    }
}

int esVocal(eLetra* this)
{
    int retorno=0;

    if(strcmp(this->letra, "a")==0 || strcmp(this->letra, "e")==0 || strcmp(this->letra, "i")==0 || strcmp(this->letra, "o")==0 || strcmp(this->letra, "u")==0 || strcmp(this->letra, "A")==0 || strcmp(this->letra, "E")==0 || strcmp(this->letra, "I")==0 || strcmp(this->letra, "O")==0 || strcmp(this->letra, "U")==0)
    {
        retorno=1;
    }

    return retorno;
}

int esConsonante(eLetra* this)
{
    int retorno=0;

    if(!(strcmp(this->letra, "a")==0 || strcmp(this->letra, "e")==0 || strcmp(this->letra, "i")==0 || strcmp(this->letra, "o")==0 || strcmp(this->letra, "u")==0 || strcmp(this->letra, "A")==0 || strcmp(this->letra, "E")==0 || strcmp(this->letra, "I")==0 || strcmp(this->letra, "O")==0 || strcmp(this->letra, "U")==0))
    {
        if(strcmp(this->letra, "0")!=0 && strcmp(this->letra, "1")!=0 && strcmp(this->letra, "2")!=0 && strcmp(this->letra, "3")!=0 && strcmp(this->letra, "4")!=0 && strcmp(this->letra, "5")!=0 && strcmp(this->letra, "6")!=0 && strcmp(this->letra, "7")!=0 && strcmp(this->letra, "8")!=0 && strcmp(this->letra, "9")!=0)
        {
            retorno=1;
        }

    }

    return retorno;
}

void eLetra_printT(eLetra* this)
{
    char letra[5];
	char nombre[22];
	char vocal[3];
	char consonante[3];
	char caracter;

    if(this != NULL && strcmp(eLetra_getnombre(this),"nombre")!=0)
    {
            caracter=this->caracter;
            strcpy(nombre,eLetra_getnombre(this));
            strcpy(vocal,eLetra_getvocal(this));
            strcpy(consonante,eLetra_getconsonante(this));

            printf("%c\t%s\t%s\t%s\n", caracter,nombre, vocal, consonante);
    }

}

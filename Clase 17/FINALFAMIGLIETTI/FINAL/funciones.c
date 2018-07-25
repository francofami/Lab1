#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "letras.h"
#include "ArrayList.h"

int parserLetras(ArrayList* this)
{
    int retorno = -1;

    FILE* pFile;
    char letra[5];
	char nombre[22];
	char vocal[3];
	char consonante[3];

    eLetra* aux;

    pFile = fopen("datos.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            aux = (eLetra*) malloc(sizeof(eLetra));
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",letra,nombre,vocal,consonante);
            eLetra_setletra(aux, letra);
            eLetra_setnombre(aux,nombre);
            eLetra_setvocal(aux,vocal);
            eLetra_setconsonante(aux,consonante);

            //aux = destinatarios_newParametros(name,mail, contador, 1);

            this->add(this,aux);
        }while(!feof(pFile));

    }

    fclose(pFile);

    return retorno;
}

void completar(ArrayList* this)
{
    FILE* pFile;
    char letra[5];
	char nombre[22];
	char vocal[3];
	char consonante[3];
	int esV;
	int esC;

    eLetra* aux;

    pFile = fopen("datos.csv", "r");

    if(pFile != NULL)
    {

        this->clear(this);

        //printf("Id\tNum\tPar\tImpar\tPrimo\tNombre\n");

        while(!feof(pFile))
        {
            aux = eLetra_new();

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",letra,nombre,vocal,consonante);


                eLetra_setletra(aux, letra);
                eLetra_setnombre(aux, nombre);

                esV=esVocal(aux);
                esC=esConsonante(aux);

                if(esV==1)
                {
                    strcpy(vocal, "1");
                }
                else
                {
                    strcpy(vocal, "0");
                }

                if(esC==1)
                {
                    strcpy(consonante, "1");
                }
                else
                {
                    strcpy(consonante, "0");
                }

                eLetra_setvocal(aux,vocal);
                eLetra_setconsonante(aux,consonante);

                this->add(this,aux);
        }

       eLetra_printAll(this);
    }

    fclose(pFile);
}

void listar()
{
    eLetra* aux;
    ArrayList* lista;

    int i,j;
    char cadena[10];

    char letra[5];
	char nombre[22];
	char vocal[3];
	char consonante[3];
	char caracter;
	int esV;
	int esC;
	int largoCadena;
	char auxiChar;

	char auxi[22];

    lista=al_newArrayList();

    printf("Ingrese cadena de caracteres: ");
    fflush(stdin);
    gets(cadena);

    largoCadena=strlen(cadena);

    for(i=0;i<largoCadena-1;i++)
    {
        for(j=i+1;j<largoCadena;j++)
        {
            if(cadena[i]<cadena[j])
            {
                auxiChar=cadena[j];
                cadena[j]=cadena[i];
                cadena[i]=auxiChar;
            }
        }
    }



    printf("Letra\tVocal\tConsonante\n");

    for(i=0;i<largoCadena;i++)
    {
        caracter=cadena[i];

        esV=esVocalChar(cadena[i]);
        esC=esConsonanteChar(cadena[i]);

        if(esV==1)
        {
            strcpy(vocal, "1");
        }
        else
        {
            strcpy(vocal, "0");
        }

        if(esC==1)
        {
            strcpy(consonante, "1");
        }
        else
        {
            strcpy(consonante, "0");
        }

        printf("%c\t%s\t%s\n", caracter, vocal, consonante);

        eLetra_setcaracter(aux, caracter);
        eLetra_setconsonante(aux, consonante);
        eLetra_setvocal(aux, vocal);
        lista->add(lista,aux);
    }
}

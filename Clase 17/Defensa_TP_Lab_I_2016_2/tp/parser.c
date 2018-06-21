#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "destinatarios.h"


int parserDestinatarios(FILE* pFile , ArrayList* this)
{
    int retorno = -1, contador=0;
    char name[4096];
    char mail[4096];
    destinatarios* auxDestinatarios;

    pFile = fopen("destinatarios.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            fscanf(pFile,"%[^,],%[^\n]\n",name,mail);
            auxDestinatarios = destinatarios_newParametros(name,mail, contador, 1);
            al_add(this,aux);
            contador+=1;
            }

        }while(!feof(pFile));
    }

    fclose(pFile);

    return retorno;
}

int parserBlackList(FILE* pFile , ArrayList* this)
{
    int retorno = -1;
    int contador=0;
    char name[4096];
    char mail[4096];
    destinatarios* auxBlackList;

    pFile = fopen("black_list.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            fscanf(pFile,"%[^,],%[^\n]\n",name,mail);
            auxBlackList = destinatarios_newParametros(name,mail, contador, 1);
            al_add(this,aux);
            contador+=1;
        }while(!feof(pFile));
    }

    fclose(pFile);

    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "destinatarios.h"


int parserDestinatarios(FILE* pFile, ArrayList* this)
{
    int retorno = -1, contador=0;
    char name[50];
    char mail[50];
    destinatarios* auxDestinatarios;

    pFile = fopen("destinatarios.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            auxDestinatarios = (destinatarios*) malloc(sizeof(destinatarios));
            contador++;
            fscanf(pFile,"%[^,],%[^\n]\n",name,mail);
            auxDestinatarios = destinatarios_newParametros(name,mail, contador, 1);
            this->add(this,auxDestinatarios);
        }while(!feof(pFile));

    }


    fclose(pFile);

    return retorno;
}

int parserBlackList(FILE* pFile2, ArrayList* this, ArrayList* pList)
{

    int i, retorno = -1;
    destinatarios* auxDestinatarios = NULL;

    if((pFile2 = fopen ("black_list.csv", "r")) != NULL)
    {
        char name[100], mail[150];

        do
        {
            destinatarios* blackAux = (destinatarios*) malloc(sizeof(destinatarios));

            fscanf(pFile2, "%[^,],%[^\n]\n", name, mail);
            strcpy(blackAux->name, name);
            strcpy(blackAux->mail, mail);

            for(i = 0; i < pList->len(pList); i++)
            {
                auxDestinatarios = (destinatarios*) pList->get(pList, i);

                if(((strcmp(auxDestinatarios->name, blackAux->name) == 0) && (strcmp(auxDestinatarios->mail, blackAux->mail) == 0)))
                {
                    retorno = this->add(this, auxDestinatarios);
                    break;
                }
            }
        }while(!feof(pFile2));

        fclose(pFile2);
    }
    else
    {
        printf("Error\n");
    }
    return retorno;

    /*int retorno = -1;
    int contador=0;
    char name[50];
    char mail[50];

    destinatarios* auxBlackList;

    pFile = fopen("black_list.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            auxBlackList = (destinatarios*) malloc(sizeof(destinatarios));
            contador++;
            fscanf(pFile,"%[^,],%[^\n]\n",name,mail);
            auxBlackList = destinatarios_newParametros(name,mail, contador, 1);
            al_add(this,auxBlackList);
        }while(!feof(pFile));
    }

    fclose(pFile);

    return retorno;*/
}

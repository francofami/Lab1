#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "destinatarios.h"
#include "parser.h"

int main()
{
    int i, j, length, length2,flag=0;

    ArrayList* pList;
    ArrayList* blackList;
    ArrayList* listaFinal;

    destinatarios* actual;

    FILE* pFile;
    FILE* pFile2;

    pList=al_newArrayList();
    blackList=al_newArrayList();
    listaFinal=al_newArrayList();

    parserDestinatarios(pFile,pList);
    parserDestinatarios(pFile2,blackList);

    printf("Antes de eliminar:\n");

    for(i=0;i<=pList->len(pList);i++)
    {
        destinatarios_print(al_get(pList,i));
    }

    if(pList!=NULL && blackList!=NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            for(j=0;j<blackList->size; j++)
            {
                if(!(destinatarios_compareMail(*(pList->pElements+i),*(blackList->pElements+j))))
                {
                    flag=1;
                }
            }

            if(flag==0)
            {
                actual = destinatarios_newParametros(destinatarios_getName(pList), destinatarios_getMail(pList), destinatarios_getId(pList), destinatarios_getIsEmpty(pList));
                al_add(listaFinal, actual);
            }

            flag=0;
        }

    }

    printf("\n\n\n\nDespues:\n");
    for(i=0;i<=listaFinal->len(listaFinal);i++)
    {
        destinatarios_print(al_get(listaFinal,i));
    }


    return 0;
}

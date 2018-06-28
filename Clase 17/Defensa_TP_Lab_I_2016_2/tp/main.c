#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "destinatarios.h"
#include "parser.h"

int main()
{
    int i, j, length, length2, contador=0;

    ArrayList* pList;
    ArrayList* blackList;
    ArrayList* listaFinal;

    FILE* pFile;
    FILE* pFile2;

    pList=al_newArrayList();
    blackList=al_newArrayList();
    listaFinal=al_newArrayList();

    parserDestinatarios(pFile,pList);
    parserBlackList(pFile2,blackList,pList);

    /*printf("Antes de eliminar:\n");

    for(i=0;i<=pList->len(pList);i++)
    {
        destinatarios_print(al_get(pList,i));
    }*/

    length=pList->size;

    length2=blackList->size;

    /*if(pList!=NULL && blackList!=NULL)
    {
        for(i=0;i<pList->size;i++)
        {
            if(al_contains(blackList,pList->get(pList,i))==1)
            {
                al_remove(pList,i);
            }
        }
    }*/

    destinatarios* auxDestinatarios;
    destinatarios* auxBlackList;

    for(i=0;i<length;i++)
    {
        auxBlackList = (destinatarios*) blackList->get(blackList, i);
        auxDestinatarios = (destinatarios*) pList->get(pList, i);

        if((blackList->contains(blackList, auxDestinatarios))==0)
        {
            listaFinal->add(listaFinal, auxDestinatarios);
        }
    }


    printf("\n\n\n\nDespues:\n");

    for(i=0;i<=listaFinal->len(listaFinal);i++)
    {
        destinatarios_print(al_get(listaFinal,i));
    }

    printf("\n\nContador: %d",contador);

    return 0;
}

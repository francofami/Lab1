#include <stdio.h>
#include <stdlib.h>
#define TAM 5

/* 3 Cosas que pueden suceder cuando busco memoria:
1. Encuentra
2. No encuentra (memoria consecutiva, osea un bloque de memoria del tamaño deseado), reasigna con realloc
3. No encuentra, NULL. (No tengo espoacio fisico en la PC.
*/

int main()
{
    int vector,i;
    int* pVector;
    int* aux;

    pVector =(int*) malloc(sizeof(int) * TAM); //Para guardar TAM enteros

    if(pVector!=NULL)
    {
        for(i=0;i<TAM;i++)
        {
            *(pVector+i)=i+1;
        }

        for(i=0;i<TAM;i++)
        {
            printf("%d\n", *(pVector+i));
        }

        aux=realloc(pVector,sizeof(int)*(TAM*2));

        if(aux!=NULL) //Si hay lugar en memoria le paso la direccion de memoria a pVector
        {
            pVector=aux;

            for(i=TAM;i<TAM*2;i++)
            {
                *(pVector+i) = i+1;
            }

            printf("Luego del realloc\n");

            for(i=0;i<TAM*2;i++)
            {
                printf("%d\n", *(pVector+i));
            }
        }

        free(aux); //Libero de la memoria la variable aux
    }

    return 0;
}

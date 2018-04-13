#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, aux;
    int vector[5]={6,2,7,3,7};

    for(i=0;i<4;i++)
    {
        for(j=i+1; j<5; j++)
        {
            if(vector[j]<vector[i]) //Menor a mayor
            {
                aux=vector[j];
                vector[j]=vector[i];
                vector[i]=aux;
            }
        }
    }

    for(i=0;i<5;i++)
    {
        printf("%d",vector[i]);
    }

    return 0;
}

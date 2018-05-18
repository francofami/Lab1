#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a;
    char b;
}dato;

int main()
{
    dato d;
    d.a=5;
    d.b='<';

    dato *pDato;
    pDato=&d;

    printf("%d--%c\n", pDato->a, pDato->b); //Es lo mismo que printf("%d--%c\n", (*(pDato+i)).a,(*(pDato+i)).b)

    printf("%d--%c\n", (*pDato).a, (*pDato).b);

      //&pDato= 0X39EF
      //pDato= 0X37E
      //*pDato = d

    printf("%d--%d\n",&d, &d.a); //la dir de memoria de d coincide con d.a porque en d.a comienza la estructura


    printf("Tam: %d\n",sizeof(int)); //sizeof(int) devuelve el tamaño de una variable de tipo int (En 32 bits pesa 2 bytes y en 64 pesa 4 bytes)
    printf("Tam: %d\n",sizeof(dato)); //sizeof(int) devuelve la suma del tamaño de todas las variables dentro de la estructura dato

    printf("%d--%c\n", d.a, d.b);

/*
int i;
dato lista[2]={{1,'a'},{1,'b'}};
dato* pLista;

pLista=lista;

for(i=0;i<2;i++)
{
    printf("%d--%c\n", lista[i].a,lista[i].b);
}

for(i=0;i<2;i++)
{
    printf("%d--%c\n", (pLista+i)->a,(pLista+i)->b); //Lo mismo que printf("%d--%c\n", (*(pLista+i)).a,(*(pLista+i)).b)
}
*/


    return 0;
}

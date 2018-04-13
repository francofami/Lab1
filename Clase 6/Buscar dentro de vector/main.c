#include <stdio.h>
#include <stdlib.h>

int contarPares(int array[],int lenghtTotal);
/** \brief Determina si un caracter esta o no dentro de un array
 *
 * \param array[] char El array
 * \param lenght int El tamaño del array
 * \param caracter char El caracter a buscar
 * \return int Si es -1 no lo encontro al caracter y si es 1 si.
 *
 */
int buscarChar(char array[], int lenght, char caracter);

int main()
{
    int lengthVector, lenghtPosicion, lenghtTotal, vector[5]={5,2,9,6,5}, cantidadPares, indexLetra;
    char letras[]={'f','g','i','m','q'};
    char ingreseCaracter;
    int a=9, b=5, c;

    //SWAP
    c=a;
    a=b;
    b=c;

    lengthVector=sizeof(vector);
    lenghtPosicion=sizeof(vector[0]);
    lenghtTotal=lengthVector/lenghtPosicion;

    cantidadPares=contarPares(vector,lenghtTotal);
    printf("La cantidad de numeros pares es de: %d\n", cantidadPares);

    printf("Ingrese caracter: ");

    ingreseCaracter=getche(ingreseCaracter);

    indexLetra=buscarChar(letras,5,ingreseCaracter);

    if(indexLetra==-1)
    {
        printf("\nEl caracter no se encuentra en el array");
    }
    else
    {
        printf("\nEl caracter se encuentra en el array");
    }

    return 0;
}

int contarPares(int array[],int lenghtTotal)
{
    int contarPares=0, i;

    for(i=0;i<lenghtTotal;i++)
    {
        if(array[i]%2 == 0)
            {
                contarPares+=1;
            }
    }

    return contarPares;
}

int buscarChar(char array[], int lenght, char caracter)
{
    int index=-1, i;

    for(i=0; i<lenght; i++)
    {
        if(array[i]==caracter)
        {
            index=1;
            break;
        }
    }

    return index;
}

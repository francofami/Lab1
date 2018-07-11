#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"
#include "numeroNatural.h"

int parserDatos(FILE* pFile, ArrayList* this)
{
    int retorno = -1;

    int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;
    int id=1;

    numeroNatural* aux;

    pFile = fopen("datos.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        printf("Id\nNum\tPar\tImpar\tPrimo\tNombre\n");

        while(!feof(pFile))
        {
            aux = numeroNatural_new();

            if(fscanf(pFile,"%d,%[^,],%d,%d,%d\n",&numero, nombre, &par, &impar, &primo)==5)
            {
                aux = numeroNatural_newParametros(id,numero,nombre, par, impar, primo);


                this->add(this,aux);

                id++;
            }


        }
        numeroNatural_printAll(this);


    }

    fclose(pFile);

    return retorno;
}

void completar(FILE* pFile, ArrayList* this)
{
    int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;
    int contador=0;
    int id=1;

    numeroNatural* aux;

    pFile = fopen("datos.csv", "r");

    if(pFile != NULL)
    {

        printf("Id\tNum\tPar\tImpar\tPrimo\tNombre\n");

        while(!feof(pFile))
        {
            aux = numeroNatural_new();

            if(fscanf(pFile,"%d,%[^,],%d,%d,%d\n",&numero, nombre, &par, &impar, &primo)==5)
            {

                aux = numeroNatural_newParametros(id, numero,nombre, par, impar, primo);

                par=esPar(aux);
                impar=esImpar(aux);
                primo=esPrimo(aux);

                aux = numeroNatural_newParametros(id, numero,nombre, par, impar, primo);

                this->add(this,aux);
                id++;

            }
        }

        numeroNatural_printAll(this);
    }

    fclose(pFile);

}

void generarArchivo(FILE* pFile, ArrayList* this)
{
    numeroNatural* empleadoAux;

    int i, length;
    int retorno=-1;

    pFile = fopen("info.csv", "w");

    if(pFile!=NULL)
    {
        length=this->len(this);
        retorno=0;

        int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;
    int id;

        for(i=0;i<length;i++)
        {
            empleadoAux= (numeroNatural*) this->get(this, i);

            id=numeroNatural_getId(empleadoAux);
            strcpy(nombre, numeroNatural_getNombre(empleadoAux));
            par=numeroNatural_getPar(empleadoAux);
            impar=numeroNatural_getImpar(empleadoAux);
            primo=numeroNatural_getPrimo(empleadoAux);

            fprintf(pFile, "%d,%s,%d,%d,%d\n", id, nombre,par,impar,primo);
        }

        printf("Archivo generado con exito.\n");
    }

    fclose(pFile);

    return retorno;


}


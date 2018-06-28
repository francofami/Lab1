#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"
#include "empleados.h"

int parserEmpleados(FILE* pFile, ArrayList* this)
{
    int retorno = -1;

    char nombre[51];
    char id[50];
    char sueldo[50];
    char profesion[50];
    char edad[50];

    empleados* auxEmpleados;

    pFile = fopen("data.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            auxEmpleados = (empleados*) malloc(sizeof(empleados));
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, sueldo, edad, profesion);
            auxEmpleados = empleados_newParametros(id,nombre, sueldo, edad, profesion);
            this->add(this,auxEmpleados);
            empleados_print(auxEmpleados);
        }while(!feof(pFile));

    }




    fclose(pFile);



    return retorno;
}


/*int crearArchivo(ArrayList* pList)
{
    empleados* empleadoAux;

    int i;
    char nombre[][15]= {"Ariel","Angel","Alberto","Carlos","Jorge","Daniela","Lucia"};
    int id=0;
    float sueldo[]= {10000,20000,30000,40000,50000,60000,70000};
    char profesion[][15]= {"tester","analista","programador","tester","programador","analista","analista"};
    int edad[]= {20,30,25,24,28,40,50};
    int retorno=-1;

    FILE *fp;

    fp = fopen("data.csv", "w");

    if(fp!=NULL)
    {
        retorno=0;

        for(i=0;i<7;i++)
        {
            id++;
            fprintf(fp, "%d,%s,%f,%s,%d\n", id, nombre[i], sueldo[i], profesion[i], edad[i]);

            empleadoAux = (empleados*) pList->get(pList, i);

            retorno = pList->add(pList, empleadoAux);
        }


    }
    else
    {
        printf("No se pudo escribir el archivo.");
    }


    fclose(fp);

    return retorno;
}*/



/*ArrayList* crearLista(FILE* pFile)
{
    int retorno = -1;

    int id[8];
    char nombre[51];
    char sueldo[8];
    int edad[8];
    char profesion[15];

    ArrayList* lista=NULL;
    empleados* auxEmpleados;

    pFile = fopen("data.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            auxEmpleados = (empleados*) malloc(sizeof(empleados));
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre,sueldo, edad, profesion);
            auxEmpleados = empleados_newParametros(id, nombre,sueldo, edad, profesion);
            lista->add(lista,auxEmpleados);
        }while(!feof(pFile));

    }

    fclose(pFile);

    return lista;
}*/

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
    int id;
    char sueldo[50];
    char profesion[50];
    int edad;
    char nomArchivo[50];

    empleados* auxEmpleados;

    //printf("Ingrese nombre del archivo a abrir: ");
    //fflush(stdin);
    //gets(nomArchivo);

    pFile = fopen("data.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        printf("\nId\tNombre\t\tSueldo\t\tEdad\tProfesion\n");

        do
        {
            auxEmpleados = (empleados*) malloc(sizeof(empleados));

            if(fscanf(pFile,"%d,%[^,],%[^,],%d,%[^\n]\n",&id, nombre, sueldo, &edad, profesion)==5)
            {
                auxEmpleados = empleados_newParametros(id,nombre, sueldo, edad, profesion);
                this->add(this,auxEmpleados);
                empleados_print(auxEmpleados);
            }
        }while(!feof(pFile));

    }

    fclose(pFile);

    return retorno;
}


int crearArchivo(FILE* pFile, ArrayList* this)
{
    empleados* empleadoAux;

    int i, length;
    int retorno=-1;

    pFile = fopen("out.csv", "w");

    if(pFile!=NULL)
    {
        length=this->len(this);
        retorno=0;

        int id;
        char nombre[50];
        char sueldo[50];
        char profesion[50];
        int edad;

        for(i=0;i<length;i++)
        {
            empleadoAux= (empleados*) this->get(this, i);

            id=empleados_getId(empleadoAux);
            strcpy(nombre, empleados_getNombre(empleadoAux));
            strcpy(sueldo, empleados_getSueldo(empleadoAux));
            strcpy(profesion, empleados_getProfesion(empleadoAux));
            edad=empleados_getEdad(empleadoAux);

            fprintf(pFile, "%d,%s,%s,%d,%s\n", id, nombre, sueldo, edad, profesion);
        }

        printf("Archivo generado con exito.\n");
    }

    fclose(pFile);

    return retorno;
}

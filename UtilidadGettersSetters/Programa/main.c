#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    char nombreArchivo[50];
    char buffer[50];
    char buffer2[50];
    char nombreArchivoC[50];
    char nombreArchivoH[50];
    char nombreEstructura[50];

    printf("Ingrese nombre de archivo a crear (sin extension): ");
    fflush(stdin);
    gets(nombreArchivo);

    strcpy(buffer,nombreArchivo);
    strcpy(buffer2,nombreArchivo);

    strcpy(nombreArchivoC,strcat(buffer,".c"));
    strcpy(nombreArchivoH,strcat(buffer2,".h"));

    printf("Ingrese nombre de la estructura a crear en el .h: ");
    fflush(stdin);
    gets(nombreEstructura);

    imprimirIncludesEnPuntoC(nombreArchivoC, nombreArchivo);
    imprimirH(nombreArchivoH, nombreArchivo);

    while(seguir=='s')
    {
        printf("\n1- Crear constructor\n");
        printf("2- Crear getters y setters\n");
        printf("3- Salir (obligatorio ingresar aca antes de salir)\n");

        fflush(stdin);
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                    constructor(nombreArchivoC,nombreEstructura);
                }
                break;
            case 2:
                {
                    gettersSetters(nombreArchivoC,nombreEstructura, nombreArchivoH);
                }
                break;
             case 3:
                {
                    imprimirFinalStruct(nombreArchivoH, nombreEstructura, nombreArchivo);
                }
                break;
            default:
                seguir='n';
        }
    }



    return 0;
}

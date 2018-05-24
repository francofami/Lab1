#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE* f;
    char mensaje[100]="hola a to2";



    f= fopen("mihtml.html","w");

    if(f!=NULL)
    {
        fprintf(f,"<html><head>");
        fprintf(f,mensaje);
        fprintf(f,"</head></html>");
        fclose(f);
    }

    /*


    APP:
    (lectura)
    Estructuras con peliculas ABM
    Antes de mostrar cualquier cosa con el programa hago fopen y fread

    DISCO:
    (escritura)
    fopen, y guardo las peliculas

    el .html es un archivo de texto


    */
    return 0;
}

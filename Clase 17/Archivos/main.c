#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1. Abrir el archivo
    // 2. Obtener datos o escribir datos
    // 3. Cerrar el archivo

    //2 tipos de archivos: de texto y binario (guardan bloques de info ej: entero, entero y char, cadena, struct, etc)

    FILE *fp; //Puntero que representa en el programa al archivo

    char buffer[100]="ffsdfsdfafdsf\n"; //Texto a guardar dentro del archivo
    char bufferIn[100];

    fp = fopen("fichero.txt", "w"); // w (modo escritura) Crea el archivo si no existe, sino lo reemplaza

    fprintf(fp, buffer); //Escribe texto en el archivo
    fprintf(fp, "%s", "Otra forma de escribir\n");
    fprintf(fp,"Otra forma mas\nY el buffer contiene: %s",buffer);

    fclose(fp);

    system("pause");
    system("cls");

    fp = fopen("fichero.txt", "r");

     if(fp==NULL)
    {
        printf("Archivo no encontra2!!!");
    }
    else
    {
        while(!feof(fp)) //feof(archivo) Muestro cosas mientras no sea el final del archivo
        {
            fgets(bufferIn,100,fp); //Guarda en una variable el contenido de un archivo (string,tamaño,archivo)
            puts(bufferIn); //Muestra el bufferIn por consola
        }

    }


    return 0;
}

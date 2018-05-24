#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
} eDato;

int main()
{
    // 1. Abrir el archivo
    // 2. Obtener datos o escribir datos
    // 3. Cerrar el archivo

    //2 tipos de archivos: de texto y binario (guardan bloques de info ej: entero, entero y char, cadena, struct, etc)

    FILE *fp; //Puntero que representa en el programa al archivo

    eDato d={1,'B'};

    char buffer[100]="ffsdfsdfafdsf\n"; //Texto a guardar dentro del archivo
    char bufferIn[100];
    int numero=64,i;
    int lista[5];//={1,2,3,4,5};

    //Guardar datos de una estructura en un archivo binario y abrirlo
/*

    /*
        Split: supongo que tengo datos de una estructura en un archivo: int, nombre, apellido, edad

           si luego quiero obtener solo la edad pongo un delimitador (ej una coma) despues de poner cada dato
           usandolo como guia para saber en que parte tenemos cada dato

           Con una funcion que recorre cada array se consigue llegar a ese dato.
    */


    fp=fopen("miBinario.dat", "wb"); //Puede ser .dat o .bin wb para escribir rb para leer

    if(fp!=NULL)
    {
        fwrite(&d,sizeof(eDato),1,fp);
        fclose(fp);
    }

    fp=fopen("miBinario.dat", "rb"); //Puede ser .dat o .bin wb para escribir rb para leer

    if(fp!=NULL)
    {
        fread(&d,sizeof(eDato),1,fp);
        fclose(fp);

        printf("%d -- %c\n", d.a, d.b);
    }
*/

    //Formas de escribir en un archivo de texto
/*
    fp = fopen("fichero.txt", "w"); // w (modo escritura) Crea el archivo si no existe, sino lo reemplaza

    fwrite(&numero,sizeof(int),1,fp); //Permite escribir otros tipos de archivos aparte de texto, lo usamos para los .BIN
    //Recibe: (direccion de memoria del dato a escribir &variable o puntero, sizeof(tipo de dato a escribir), cantidad de datos a escribir,nombre puntero a archivo
    //En este caso me guarda un arroba (codigo ascii)

    fclose(fp);
*/

    //Carga secuencial de numeros en archivo y lectura
/*
    fp = fopen("fichero.txt","w");

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        fwrite(&numero,sizeof(int),1,fp); //Cuando escribo me guarda en el archivo y no en memoria
    }

    fp = fclose(fp);

    fp = fopen("fichero.txt","r");

    while(!feof(fp))
    {
        fread(&numero,sizeof(int),1,fp);

        if(feof(fp))
            break;

        printf("%d\n",numero);
    }

    fclose(fp);//Termino de iterar y cierro el flujo de datos
*/

    //Guardar un entero en archivo
/*
    fp = fopen("fichero.txt","r");

    fread(&numero,sizeof(int),1,fp); //Guardo en &numero un int

    fclose(fp);

    printf("%d\n", numero); //Aca no me va a mostrar el @ sino un 64 porque lo guarde como entero

    if(fp!=NULL)
    {
        fprintf(fp, buffer); //Escribe texto en el archivo, solo strings
        fprintf(fp, "%s", "Otra forma de escribir\n");
        fprintf(fp,"Otra forma mas\nY el buffer contiene: %s",buffer);
    }
    else
    {
        printf("No se pudo escribir el archivo.");
    }

    fclose(fp);
*/

    system("pause");
    system("cls");

    //Mostrar lo que tiene el archivo

/*
    fp = fopen("fichero.txt", "r"); //Si no se puede abrir el archivo porque no lo encuentra fopen devuelve NULL

    if(fp==NULL)
    {
        printf("Archivo no encontra2!!!");
    }
    else
    {
        while(!feof(fp)) //feof(archivo) Muestro cosas mientras no sea el final del archivo, sino imprimiria solo la primer linea
        {
            fgets(bufferIn,100,fp); //Guarda en una variable el contenido de un archivo (string,tamaño,archivo)
            puts(bufferIn); //Muestra el bufferIn por consola
        }
    }
*/
    return 0;
}

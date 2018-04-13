#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantidadChar, comparacion;
    char palabra1[15];
    //En este caso puedo guardar 14 caracteres como max porque el ultimo va un \0 que indica el fin del vector.
    //El \0 se pone automaticamente despues del ultimo caracter que ingrese.
    //Solo en la linea de la declaracion puedo asignarle una palabra entre "" al array. Ej= palabra[15]="Hola";
    char palabra2[15];
    char buffer[1024];

    //printf("Ingrese una palabra: ");
    //fflush(stdin); //Limpio el buffer antes de usar un gets.
    //gets(palabra1); //Para cargar strings uso la funcion gets en vez de el scanf.

    //strcpy(destino, origen);Sirve para copiar un string en otro vector. Para usar esta funcion debo incluir: #include <string.h>
    strcpy(palabra2, "perro"); //Tambien puedo hacer strcpy(palabra2, "Lo que sea");

    //strupr(palabra1); Pasa todo a MAYUSCULA
    //strlwr(palabra2); Pasa todo a minuscula


    do{
        printf("Ingrese una palabra (menor a 15 caracteres): ");
        fflush(stdin);
        gets(buffer);
    }while(strlen(buffer)>14);

    strcpy(palabra1, buffer);

    strcat(buffer, palabra2); //strcat(destino, origen) Es para concatenar strings.

    //De esta forma lo que hago es validar no me ingresen mas de 14 caracteres en palabra1.

    comparacion=strcmp(palabra1,palabra2);
    //strcmp() Compara dos strings, devuelve -1 si palabra1 esta antes alfabeticamente y 1 si no.
    comparacion=stricmp(palabra1,palabra2);
    //stricmp() Hace lo mismo que strcmp pero no es Case-Sensitive.

    cantidadChar=strlen(palabra1); //strlen(vector); Sirve para contar cuantos caracteres se cargaron en el string.

    printf("Palabra1: %s\n", palabra1); //%s es de string
    printf("Palabra2: %s\nBuffer: %s\n", palabra2,buffer);
    printf("Cantidad de caracteres ingresados: %d\n", cantidadChar);

    printf("%d",comparacion);

    return 0;
}

/*
Declarar 3 variables char nombre, char apellido, char apellidoYnombre.
(definimos nosotros la cantidad de caracteres)
El usuario va a ingresar el apellido, el nombre y en la variable apellido y nombre deberia quedar:
    apellidoYnombre = "Apellido, Nombre"
A las variables nombre y apellido NO HAY QUE MODIFICARLAS.
*/

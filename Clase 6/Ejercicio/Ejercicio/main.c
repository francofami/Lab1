#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Declarar 3 variables char nombre, char apellido, char apellidoYnombre.
(definimos nosotros la cantidad de caracteres)
El usuario va a ingresar el apellido, el nombre y en la variable apellidoYnombre deberia quedar:
    apellidoYnombre = "Apellido, Nombre"
A las variables nombre y apellido NO HAY QUE MODIFICARLAS.
*/

int main()
{
    char nombre[20];
    char apellido[20];
    char apellidoYnombre[40];

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);

    strcpy(apellidoYnombre, apellido);
    strcat(apellidoYnombre, ", ");
    strcat(apellidoYnombre, nombre);

    printf("%s",apellidoYnombre);

    return 0;
}

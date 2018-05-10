//VALIDACIÓN DE UN NOMBRE O CADENA DE CARACTERES

#include<stdio.h>
#include<conio.h>
#include<string.h>

int validarNombre(char nombre[]);
int main()
{
     char nombre[20];
     int validacion;

     do
     {
         printf("INGRESA UN NOMBRE: ");
         scanf("%s",nombre);
         validacion=validarNombre(nombre);

     }while(validacion==0);

     printf("VALIDACION EXITOSA TU NOMBRE ES: %s",nombre);

    getch();
    return 1;
}
//////////////////////////////////////
int validarNombre(char nombre[])
{
    int i;
    for(i=0 ; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>=65 && nombre[i]<=90 || nombre[i]>=97 && nombre[i]<=122))
        {
            printf("SOLO INGRESA LETRAS");
            return 0;
        }
    }
    return 1;
}

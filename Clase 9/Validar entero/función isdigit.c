#include<stdio.h>
#include<conio.h>
#include<string.h>

int validar_numero(char numero[]);

int main()
{
   char numero[5];
   int N;
   int numerovalido;
   do
   {
       printf("INGRESA UN NUMERO ENTERO: ");
       scanf("%s",numero);
       N=validar_numero(numero);

   }while(N==0);

   numerovalido=atoi(numero);
   printf("\nEL NUMERO ES: %i",numerovalido);

   getch();
   return 1;
}
/////////////////
int validar_numero(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("\nINGRESA SOLO NUMEROS\n");
            getch();
            return 0;
        }
    }
    return 1;
}

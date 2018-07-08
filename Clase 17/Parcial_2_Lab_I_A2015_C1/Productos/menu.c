#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "menu.h"
#include "funciones.h"

void menu()
{
    char seguir='s';
    int opcion, flag=0;

    while(seguir=='s')
    {
        printf("\n1- Alta\n");
        printf("2- Modificacion\n");
        printf("3- Baja logica\n");
        printf("4- Baja fisica\n");
        printf("5- Listar\n");
        printf("6- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                    nuevoProducto();
                }
                break;

            case 2:
                {
                    if(flag!=1)
                    {
                        modificacion();
                    }
                    else
                        printf("Se debe agregar al menos un producto para ingresar a esta opcion.\n");
                }
                break;

            case 3:
                {
                    if(flag!=1)
                    {
                        bajaLogica();
                    }
                    else
                        printf("Se debe agregar al menos un producto para ingresar a esta opcion.\n");

                }

                break;
            case 4:
                {
                    if(flag!=1)
                    {
                        bajaFisica();
                    }
                    else
                        printf("Se debe agregar al menos un producto para ingresar a esta opcion.\n");

                }
                break;
            case 5:
                {
                    if(flag!=1)
                    {
                       leerDatos();
                    }
                    else
                        printf("Se debe agregar al menos un producto para ingresar a esta opcion.\n");
                }
                break;
            default:
                seguir = 'n';
        }

    }
}

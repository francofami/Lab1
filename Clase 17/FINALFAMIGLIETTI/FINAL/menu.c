#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ArrayList.h"
#include "funciones.h"
#include "letras.h"

void mostrarMenu()
{
    ArrayList* lista;
    lista=al_newArrayList();

    ArrayList* listaDos;
    listaDos=al_newArrayList();

    parserLetras(lista);

    char seguir='s';
    int opcion;

    while(seguir=='s')
    {
        printf("\n1- Altas\n");
        printf("2- Completar\n");
        printf("3- Listar\n");
        printf("4- \n");
        printf("5- \n");
        printf("6- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                    eLetra_printAll(lista);
                }
                break;

            case 2:
                {
                    completar(listaDos);
                }
                break;

            case 3:
                {
                    listar();
                }

                break;
            case 4:
                {


                }
                break;
            case 5:
                {

                }
                break;
            default:
                seguir = 'n';
        }

    }
}


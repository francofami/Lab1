#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ArrayList.h"
#include "funciones.h"
#include "letras.h"

void mostrarMenu()
{
    ArrayList* lista; //La lista sin completar
    lista=al_newArrayList();

    ArrayList* listaDos; //La lista completada
    listaDos=al_newArrayList();

    parserLetras(lista);

    completar(listaDos);

    char seguir='s';
    int opcion;

    while(seguir=='s')
    {
        printf("\n1- Altas\n");
        printf("2- Completar\n");
        printf("3- Listar A\n");
        printf("4- Listar B\n");
        printf("5- Generar archivos\n");
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
                    eLetra_printAll(listaDos);
                }
                break;

            case 3:
                {
                    listarA(listaDos);
                }

                break;
            case 4:
                {
                    listarB(listaDos);
                }
                break;
            case 5:
                {
                    ArrayList* listaRepetidos;
                    listaRepetidos = al_newArrayList();

                    generarCompleto(listaDos);
                    listaRepetidos=generarRepetidos(listaDos);

                    generarDepurado(listaDos,listaRepetidos);
                }
                break;
            default:
                seguir = 'n';
        }

    }
}


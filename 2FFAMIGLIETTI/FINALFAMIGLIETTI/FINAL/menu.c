#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ArrayList.h"
#include "funciones.h"
#include "letras.h"

void mostrarMenu()
{
    ArrayList* lista; //La lista completa
    lista=al_newArrayList();

    ArrayList* listaDos; //La lista repetidos
    listaDos=al_newArrayList();

    ArrayList* listaTres; //La lista depurados
    listaTres=al_newArrayList();


    //parserLetras(lista);

    //completar(lista);

    char seguir='s';
    int opcion;

    while(seguir=='s')
    {
        printf("\n1- Altas\n");
        printf("2- Completar\n");
        printf("3- Listar\n");
        printf("4- Listar\n");
        printf("5- Generar archivos\n");
        printf("6- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                    parserLetras(lista);
                }
                break;

            case 2:
                {
                    completar(lista);
                    eLetra_printAll(lista);
                    generarCompleto(lista);
                }
                break;

            case 3:
                {
                    listaTres=listarA(lista);
                    generarDepurado(listaTres);
                }

                break;
            case 4:
                {
                    completar(lista);

                    listaDos=listarB(lista);

                    generarRepetidos(listaDos);
                }
                break;
            case 5:
                {
                    //completar(lista);





                }
                break;
            default:
                seguir = 'n';
        }

    }
}


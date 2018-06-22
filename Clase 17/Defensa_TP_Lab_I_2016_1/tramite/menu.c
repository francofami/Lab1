#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ArrayList.h"
#include "tramite.h"

void menu()
{
    int opcion, i, length;
    char seguir='s';
    int ultimoIdTramiteUrgente=0;
    int ultimoIdTramiteRegular=0;
    char dni[10];
    eTramite* tramiteActual;
    ArrayList* listaTramitesUrgentes;
    ArrayList* listaTramitesRegulares;

    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;

    listaTramitesUrgentes=al_newArrayList();
    listaTramitesRegulares=al_newArrayList();

    atendidosRegulares=al_newArrayList();
    atendidosUrgentes=al_newArrayList();

    while(seguir=='s')
    {
        printf("1- Tramite urgente\n");
        printf("2- Tramite regular\n");
        printf("3- Promximo a ser atendido\n");
        printf("4- Listar pendientes\n");
        printf("5- Informar atendidos\n");
        printf("6- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    ultimoIdTramiteUrgente+=1;
                    printf("Ingrese DNI: ");
                    fflush(stdin);
                    gets(dni);

                    cargarTramite(listaTramitesUrgentes,ultimoIdTramiteUrgente,dni);
                }
                break;
            case 2:
                {
                    ultimoIdTramiteRegular+=1;
                    printf("Ingrese DNI: ");
                    fflush(stdin);
                    gets(dni);

                    cargarTramite(listaTramitesRegulares,ultimoIdTramiteRegular,dni);
                }
                break;
            case 3:
                {
                    if(!listaTramitesUrgentes->isEmpty(listaTramitesUrgentes))
                    {
                        printf("Cliente a ser atendido: ");
                        atenderTramite(listaTramitesUrgentes, atendidosUrgentes);
                    }
                    else if(!listaTramitesRegulares->isEmpty(listaTramitesRegulares))
                    {
                        printf("Cliente a ser atendido: ");
                        atenderTramite(listaTramitesRegulares, atendidosRegulares);
                    }
                    else
                        printf("No hay clientes por atender.\n");
                }
                break;
            case 4:
                {
                    length=listaTramitesUrgentes->len(listaTramitesUrgentes);

                    if(!(listaTramitesUrgentes->isEmpty(listaTramitesUrgentes)))
                    {
                        printf("Tramites urgentes:\n");
                        mostrarListaTramites(listaTramitesUrgentes);
                    }
                    else
                    {
                        printf("No hay tramites urgentes.\n");
                    }

                    length=listaTramitesRegulares->len(listaTramitesRegulares);

                    if(!(listaTramitesRegulares->isEmpty(listaTramitesRegulares)))
                    {
                        printf("\nTramites regulares:\n");
                        mostrarListaTramites(listaTramitesRegulares);
                    }
                    else
                    {
                        printf("No hay tramites regulares.\n");
                    }
                }
                break;
            case 5:
                {
                    length=atendidosUrgentes->len(atendidosUrgentes);

                    atendidosUrgentes->sort(atendidosUrgentes,compararPorDni,0);

                    if(!(atendidosUrgentes->isEmpty(atendidosUrgentes)))
                    {
                        printf("Atendidos urgentes:\n");
                        for(i=0;i<length;i++)
                        {
                            tramiteActual=(eTramite*) atendidosUrgentes->get(atendidosUrgentes,i);
                            mostrarTramite(tramiteActual);
                        }
                    }
                    else
                    {
                        printf("No se atendio a nadie (en estado urgente).\n");
                    }

                    length=atendidosRegulares->len(atendidosRegulares);

                    atendidosRegulares->sort(atendidosRegulares,compararPorDni,0);

                    if(!(atendidosRegulares->isEmpty(atendidosRegulares)))
                    {
                        printf("\Atendidos regulares:\n");
                        for(i=0;i<length;i++)
                        {
                            tramiteActual=(eTramite*) atendidosRegulares->get(atendidosRegulares,i);
                            mostrarTramite(tramiteActual);
                        }
                    }
                    else
                    {
                        printf("No se atendio a nadie (en estado regular).\n");
                    }
                }
                break;
            case 6:
                seguir='n';
                break;
            default:
                printf("Opcion incorrecta.\n");
        }
    }
}

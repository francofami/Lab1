#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#define OCUPADO 0
#define LIBRE 1
#define BORRADO -5
#define EGRESADO -6
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4


void hardcoreIngresos(eAuto listadoAutos[])
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    int i;

    for(i=0; i<10; i++)
    {
        listadoAutos[i].idAuto=id[i];
        listadoAutos[i].idPropietario=propietario[i];
        listadoAutos[i].marca=marca[i];
        listadoAutos[i].estado = OCUPADO;
        strcpy(listadoAutos[i].patente, patente[i]);
    }
}

void eAuto_init(eAuto listadoAutos[],int limite)
{
    int i;

        for(i=0; i<limite; i++)
        {
            listadoAutos[i].estado= LIBRE;
            listadoAutos[i].marca= 0;
            listadoAutos[i].idAuto= 0;
            listadoAutos[i].idPropietario= 0;
            strcpy(listadoAutos[i].patente,"");
            listadoAutos[i].importe=0;
        }
}

void eAuto_ingreso(eAuto listadoAutos[],ePropietario listadoPropietarios[], int largoAutos, int largoPropietarios)
{
    int idUsuario, indiceVacio, i, flag=0, idAutito;

        ePropietario_mostrarListado(listadoPropietarios,largoPropietarios);

        printf("\nIngrese ID de propietario cuyo auto quiera ingresar: ");
        scanf("%d",&idUsuario);

        for(i=0;i<largoPropietarios;i++)
        {
            if(idUsuario==listadoPropietarios[i].idPropietario)
            {
                flag=1;
                break;
            }
        }

        indiceVacio=eAuto_buscarLugarLibre(listadoAutos,largoAutos);


        if(indiceVacio >= 0 && flag==1)
        {
            idAutito=eAuto_siguienteId(listadoAutos,largoAutos);

            do{
                printf("\nIngrese marca del auto (1. Alpha Romeo 2. Ferrari 3. Audi 4. Otros): ");
            scanf("%d",&listadoAutos[indiceVacio].marca);
            }while(listadoAutos[indiceVacio].marca<=1 && listadoAutos[indiceVacio].marca>=4);

            printf("\nIngrese patente: ");
            fflush(stdin);
            gets(listadoAutos[indiceVacio].patente);

            listadoAutos[indiceVacio].idPropietario=idUsuario;
            listadoAutos[indiceVacio].estado=OCUPADO;
            listadoAutos[indiceVacio].idAuto=idAutito;
        }

        if(flag==0)
        {
            printf("No existe dicho propietario.\n");
        }

        if(indiceVacio<0)
        {
            printf("No hay mas espacio.\n");
        }
}

void eAuto_mostrarUno(eAuto parametro)
{
    char marca[20];

    if(parametro.marca==1)
    {
        strcpy(marca,"ALPHA_ROMEO");
    }
    if(parametro.marca==2)
    {
        strcpy(marca,"FERRARI    ");
    }
    if(parametro.marca==3)
    {
        strcpy(marca,"AUDI       ");
    }
    if(parametro.marca==4)
    {
        strcpy(marca,"OTRO       ");
    }
    printf("\n %d         %d               %s                  %s\n",parametro.idAuto,parametro.idPropietario,marca,parametro.patente);
}

void eAuto_mostrarListado(eAuto listadoAutos[],int limite)
{
    int i;

        printf("ID Auto      ID Prop.       Marca                      Patente\n");

        for(i=0; i<limite; i++)
        {
            if(listadoAutos[i].estado==OCUPADO)
            {
                eAuto_mostrarUno(listadoAutos[i]);
            }
        }
}

int eAuto_buscarLugarLibre(eAuto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void eAuto_egreso(eAuto listaAutos[],ePropietario listaPropietarios[],int largoAutos,int largoPropietarios)
{
    int id, indiceAuto, indicePropietario, horas,i, flag=0, flagOcupados, opcion;
    float importe, acumuladorAlpha=0, acumuladorFerrari=0, acumuladorAudi=0, acumuladorOtros=0;
    char marca[20];

    for(i=0;i<largoAutos;i++)
    {
        if(listaAutos[i].estado==OCUPADO)
        {
            eAuto_mostrarListado(listaAutos,largoAutos);

            printf("Ingrese ID de auto que egresa: ");
            scanf("%d", &id);
            flagOcupados=1;
            break;
        }
    }

    if(flagOcupados==0)
    {
        printf("No hay autos estacionados.\n");
        flag=1;
    }

    if(flag!=1)
    {
        indiceAuto=eAuto_buscarPorId(listaAutos,largoAutos,id);
        indicePropietario=ePropietario_buscarPorId(listaPropietarios,largoPropietarios,listaAutos[indiceAuto].idPropietario);

        printf("Esta seguro que desea egresar el auto: \n1. Si  2. No\n");
        scanf("%d", &opcion);

    if(indiceAuto>=0 && opcion==1)
    {
        horas=devolverHorasEstadia();
        if(listaAutos[indiceAuto].marca==1)
        {
            strcpy(marca,"ALPHA_ROMEO");
            importe=horas*150;
            listaAutos[indiceAuto].importe=importe;
        }

        if(listaAutos[indiceAuto].marca==2)
        {
            strcpy(marca,"FERRARI");
            importe=horas*175;
            listaAutos[indiceAuto].importe=importe;
        }

        if(listaAutos[indiceAuto].marca==3)
        {
            strcpy(marca,"AUDI");
            importe=horas*200;
            listaAutos[indiceAuto].importe=importe;
        }

        if(listaAutos[indiceAuto].marca==4)
        {
            strcpy(marca,"OTROS");
            importe=horas*250;
            listaAutos[indiceAuto].importe=importe;
        }

        listaAutos[indiceAuto].estado=EGRESADO;

        printf("Nombre propietario: %s - Patente: %s - Marca: %s - Valor de estadia: %.2f\n", listaPropietarios[indicePropietario].nombreApellido, listaAutos[indiceAuto].patente, marca, importe);
    }
    else
        {
        if(opcion==1)

        printf("El ID ingresado no coincide con ningun auto estacionado.\n");
    }

    }
}

void egresosHardcode(eAuto listadoAutos[])
{
    int marca[]= {1,1,2,3,2,2,3,4,1,1};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};

    int i;

    for(i=0; i<10; i++)
    {
        listadoAutos[i].marca=marca[i];
        listadoAutos[i].estado = EGRESADO;
        listadoAutos[i].importe=importe[i];
    }
}

void eAuto_mostrarEgresos(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int i, j;
    char marca[20];

    printf("Nombre propietario    Patente     Marca           Valor de estadia\n");

    for(i=0;i<largoAutos;i++)
    {
        if(listadoAutos[i].estado==EGRESADO)
        {

            for(j=0;j<largoPropietarios;j++)
            {
                if(listadoAutos[i].idPropietario==listadoPropietarios[j].idPropietario)
                {
                   break;
                }
            }

        if(listadoAutos[i].marca==1)
        {
            strcpy(marca,"ALPHA_ROMEO");
        }

        if(listadoAutos[i].marca==2)
        {
            strcpy(marca,"FERRARI    ");
        }

        if(listadoAutos[i].marca==3)
        {
            strcpy(marca,"AUDI       ");
        }

        if(listadoAutos[i].marca==4)
        {
            strcpy(marca,"OTROS      ");
        }

        printf("%s                   %s        %s       %.2f\n", listadoPropietarios[j].nombreApellido, listadoAutos[i].patente, marca, listadoAutos[i].importe);

        }

    }

}

void eAuto_recaudacionTotal(eAuto listadoAutos[], int largoAutos)
{
    int i;
    float acumuladorImportes=0;

    for(i=0;i<largoAutos;i++)
    {
        acumuladorImportes+=listadoAutos[i].importe;
    }

    printf("La recaudacion total del estacionamiento es de: %.2f\n", acumuladorImportes);
}

void eAuto_recaudacionPorMarca(eAuto listadoAutos[], int largoAutos)
{
    int i;
    float acumuladorAlpha=0, acumuladorFerrari=0, acumuladorAudi=0, acumuladorOtros=0;

    for(i=0;i<largoAutos;i++)
    {
        if(listadoAutos[i].marca==1)
        {
             acumuladorAlpha+=listadoAutos[i].importe;
        }

        if(listadoAutos[i].marca==2)
        {
            acumuladorFerrari+=listadoAutos[i].importe;
        }

        if(listadoAutos[i].marca==3)
        {
            acumuladorAudi+=listadoAutos[i].importe;
        }

        if(listadoAutos[i].marca==4)
        {
            acumuladorOtros+=listadoAutos[i].importe;
        }
    }

    printf("Recaudacion total Alpha Romeo: %.2f\nRecaudacion total Ferrari: %.2f\nRecaudacion total Audi: %.2f\nRecaudacion total Otros: %.2f\n",acumuladorAlpha,acumuladorFerrari,acumuladorAudi,acumuladorOtros);
}

void eAuto_buscarPorIdPropietario(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int id, indicePropietario, i;
    char marca[20];

    ePropietario_mostrarListado(listadoPropietarios,largoPropietarios);

    printf("Ingrese ID del propietario: ");
    scanf("%d", &id);

    indicePropietario=ePropietario_buscarPorId(listadoPropietarios,largoPropietarios, id);

    if(indicePropietario>=0)
    {
        printf("Nombre propietario          Patente          Marca\n");

       for(i=0;i<largoAutos;i++)
        {
            if(listadoPropietarios[indicePropietario].idPropietario==listadoAutos[i].idPropietario && listadoAutos[i].estado==OCUPADO)
            {
                if(listadoAutos[i].marca==1)
                    {
                        strcpy(marca,"ALPHA_ROMEO");
                    }

                if(listadoAutos[i].marca==2)
                    {
                        strcpy(marca,"FERRARI    ");
                    }

                if(listadoAutos[i].marca==3)
                    {
                        strcpy(marca,"AUDI       ");
                    }

                if(listadoAutos[i].marca==4)
                    {
                        strcpy(marca,"OTROS      ");
                    }
                printf("%s                          %s          %s\n", listadoPropietarios[indicePropietario].nombreApellido, listadoAutos[i].patente, marca);
            }
        }
    }
    else
        printf("El propietario ingresado no existe.\n");
}

void eAuto_datosAudi(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int i, j;

    printf("ID prop.      ID auto      Nombre          Direccion          Tarjeta\n");

    for(i=0;i<largoAutos;i++)
    {
        if(listadoAutos[i].marca==3 && listadoAutos[i].estado==OCUPADO)
        {
            for(j=0;j<largoPropietarios;j++)
            {
                if(listadoAutos[i].idPropietario == listadoPropietarios[j].idPropietario)
                {
                   printf("\%d             %d             %s             %s             %s \n",listadoPropietarios[j].idPropietario,listadoAutos[i].idAuto,listadoPropietarios[j].nombreApellido,listadoPropietarios[j].direccion,listadoPropietarios[j].tarjetaCredito);
                }
            }
        }
    }
}

void eAuto_estacionadosPorPatente(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios)
{
    int i,j,k, ultimoOcupado, auxi, indicePropietario,idProp;
    char aux[50], marca[20], variableNombre[20][100], direccion[20][100];

    printf("Patente    ID Auto          Marca              ID Prop           Nombre prop.          Direccion \n");

    ultimoOcupado=eAuto_buscarLugarLibre(listadoAutos,largoAutos);
    if(ultimoOcupado==-2)
    ultimoOcupado=20;

    for(i=0;i<ultimoOcupado-1;i++)
    {
        for(j=i+1;j<ultimoOcupado;j++)
        {
            if(stricmp(listadoAutos[j].patente,listadoAutos[i].patente)==-1)
            {
                strcpy(aux, listadoAutos[j].patente);
                strcpy(listadoAutos[j].patente, listadoAutos[i].patente);
                strcpy(listadoAutos[i].patente, aux);

                auxi=listadoAutos[j].marca;
                listadoAutos[j].marca=listadoAutos[i].marca;
                listadoAutos[i].marca=auxi;

                auxi=listadoAutos[j].idAuto;
                listadoAutos[j].idAuto=listadoAutos[i].idAuto;
                listadoAutos[i].idAuto=auxi;

                auxi=listadoAutos[j].idPropietario;
                listadoAutos[j].idPropietario=listadoAutos[i].idPropietario;
                listadoAutos[i].idPropietario=auxi;
            }
        }
    }

    for(i=0;i<ultimoOcupado;i++)
    {
        indicePropietario=ePropietario_buscarPorId(listadoPropietarios,largoPropietarios, listadoAutos[i].idPropietario);
        strcpy(variableNombre[i], listadoPropietarios[indicePropietario].nombreApellido);
        strcpy(direccion[i], listadoPropietarios[indicePropietario].direccion);
        idProp=listadoPropietarios[indicePropietario].idPropietario;

    if(listadoAutos[i].estado==OCUPADO)
        {

            if(listadoAutos[i].marca==1)
                    {
                        strcpy(marca,"ALPHA_ROMEO");
                    }

                if(listadoAutos[i].marca==2)
                    {
                        strcpy(marca,"FERRARI    ");
                    }

                if(listadoAutos[i].marca==3)
                    {
                        strcpy(marca,"AUDI       ");
                    }

                if(listadoAutos[i].marca==4)
                    {
                        strcpy(marca,"OTROS      ");
                    }

            printf("%s        %d             %s           %d                %s               %s\n",listadoAutos[i].patente, listadoAutos[i].idAuto, marca,idProp, variableNombre[i], direccion[i]);
        }
    }
}

int eAuto_siguienteId(eAuto listadoAutos[],int limite)
{
    int retorno = 0;
    int i;

        for(i=0; i<limite; i++)
        {
            if(listadoAutos[i].estado == OCUPADO)
            {
                    if(listadoAutos[i].idAuto>retorno)
                    {
                         retorno=listadoAutos[i].idAuto;
                    }

            }
        }

    return retorno+1;
}

int eAuto_buscarPorId(eAuto listadoAutos[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoAutos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listadoAutos[i].estado == OCUPADO && listadoAutos[i].idAuto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

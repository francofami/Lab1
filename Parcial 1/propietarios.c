#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "propietarios.h"
#define OCUPADO 0
#define LIBRE 1
#define BORRADO -5
#define EGRESADO -6
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4
#include <time.h>

void inicializarPropietariosHardCode(ePropietario listadoPropietarios[])
{
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

    int i;

    for(i=0; i<4; i++)
    {
        listadoPropietarios[i].idPropietario=id[i];
        listadoPropietarios[i].estado = OCUPADO;
        strcpy(listadoPropietarios[i].tarjetaCredito, tarjeta[i]);
        strcpy(listadoPropietarios[i].nombreApellido, nombre[i]);
        strcpy(listadoPropietarios[i].direccion, direccion[i]);
    }
}

int validarNumero(char numero[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            retorno=0;
            printf("Error! Ingrese solo numeros.\n");
            break;
        }
    }

    return retorno;
}

void ePropietario_init(ePropietario listadoPropietarios[],int limite)
{
    int i;

        for(i=0; i<limite; i++)
        {
            listadoPropietarios[i].estado= LIBRE;
            listadoPropietarios[i].idPropietario= 0;
            strcpy(listadoPropietarios[i].tarjetaCredito,"");
            strcpy(listadoPropietarios[i].nombreApellido,"");
            strcpy(listadoPropietarios[i].direccion,"");
        }
}

int ePropietario_buscarLugarLibre(ePropietario listadoPropietarios[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoPropietarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listadoPropietarios[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePropietario_siguienteId(ePropietario listadoPropietarios[],int limite)
{
    int retorno = 0;
    int i;

        for(i=0; i<limite; i++)
        {
            if(listadoPropietarios[i].estado == OCUPADO)
            {
                    if(listadoPropietarios[i].idPropietario>retorno)
                    {
                         retorno=listadoPropietarios[i].idPropietario;
                    }

            }
        }

    return retorno+1;
}

int ePropietario_alta(ePropietario  listadoPropietarios[],int limite)
{
    int retorno = -1;
    int id;
    int indice;
    int validar;
    char nombre[100];


    if(limite > 0 && listadoPropietarios != NULL)
    {
        retorno = -2;
        indice = ePropietario_buscarLugarLibre(listadoPropietarios,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = ePropietario_siguienteId(listadoPropietarios,limite);

            do
            {
                printf("Ingrese nombre y apellido: ");
                fflush(stdin);
                gets(listadoPropietarios[indice].nombreApellido);
                strcpy(nombre,listadoPropietarios[indice].nombreApellido);
                validar=validarNombre(nombre);
                if(validar==0)
                    printf("Error, asegurese de ingresar solo letras.\n");
            }while(validar==0);

            printf("Ingrese direccion: ");
            fflush(stdin);
            gets(listadoPropietarios[indice].direccion);

            printf("Ingrese tarjeta de credito: ");
            fflush(stdin);
            gets(listadoPropietarios[indice].tarjetaCredito);

            retorno = 0;
            listadoPropietarios[indice].idPropietario = id;
            listadoPropietarios[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int validarNombre(char nombre[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(nombre); i++)
    {
        if(!(isalpha(nombre[i])) && nombre[i]!=' ')
        {
            retorno=0;
            break;
        }
    }

    return retorno;
}


int ePropietario_buscarPorId(ePropietario listadoPropietarios[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoPropietarios != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listadoPropietarios[i].estado == OCUPADO && listadoPropietarios[i].idPropietario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void ePropietario_modificacion(ePropietario listadoPropietarios[] ,int limite)
{
    int id, indicePropietario=-1, validar, opcion;
    char tarjeta[20];

    ePropietario_mostrarListado(listadoPropietarios,limite);

    printf("\nIngrese ID de usuario a modificar su numero de tarjeta: ");
    scanf("%d",&id);

    indicePropietario=ePropietario_buscarPorId(listadoPropietarios,limite,id);

    if(indicePropietario>=0)
    {
        printf("Esta seguro que desea modificar el numero de tarjeta de: \n");
        ePropietario_mostrarUno(listadoPropietarios[indicePropietario]);
        printf("1. Si\n2. No\n");
        scanf("%d",&opcion);

        if(opcion==1)
        {
            printf("\nIngrese nuevo numero de tarjeta: ");
            fflush(stdin);
            gets(listadoPropietarios[indicePropietario].tarjetaCredito);
        }

    }
    else
        printf("El ID ingresado no coincide con ningun propietario.\n");

}

void ePropietario_baja(ePropietario listadoPropietarios[] ,int limite)
{
    int id, indicePropietario=-1, opcion,i;

    ePropietario_mostrarListado(listadoPropietarios,limite);


       printf("\nIngrese ID de usuario a dar de baja: ");
    fflush(stdin);
    scanf("%d",&id);
    indicePropietario=ePropietario_buscarPorId(listadoPropietarios,limite,id);
if(indicePropietario>=0)
    {
    printf("Esta seguro que desea eliminar a: \n");
    ePropietario_mostrarUno(listadoPropietarios[indicePropietario]);
    printf("1. Si\n2. No\n");
    scanf("%d",&opcion);
    }
    else
        printf("No hay ningun propietarios con ese id.\n");




if(opcion==1)
{
    if(indicePropietario>=0)
    {
        ePropietario_mostrarUno(listadoPropietarios[indicePropietario]);

        listadoPropietarios[indicePropietario].estado=BORRADO;
        listadoPropietarios[indicePropietario].idPropietario=0;
        strcpy(listadoPropietarios[indicePropietario].tarjetaCredito,"");
        strcpy(listadoPropietarios[indicePropietario].nombreApellido, "");
        strcpy(listadoPropietarios[indicePropietario].direccion, "");
        printf("\n");
    }
    else
        printf("El ID ingresado no coincide con ningun propietario. \n");
}


}

void ePropietario_mostrarUno(ePropietario parametro)
{
     printf("\n%d           %s             %s            %s \n",parametro.idPropietario,parametro.nombreApellido,parametro.direccion,parametro.tarjetaCredito);
}

void ePropietario_mostrarListado(ePropietario listadoPropietarios[],int limite)
{
    int i;

    printf("ID          Nombre          Direccion          Tarjeta");
        for(i=0; i<limite; i++)
        {
            if(listadoPropietarios[i].estado==OCUPADO)
            {
                ePropietario_mostrarUno(listadoPropietarios[i]);
            }
        }

}


int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

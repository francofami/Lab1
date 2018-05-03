#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1
#define BORRADO -5


int eUser_init( eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idUsuario= 0;
        }
    }
    return retorno;
}

int eProducto_init( eProducto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idProducto= 0;
        }
    }
    return retorno;
}

int eUser_buscarLugarLibre(eUsuario listado[],int limite)
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

int eUser_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idUsuario>retorno)
                    {
                         retorno=listado[i].idUsuario;
                    }

            }
        }
    }

    return retorno+1;
}


int eUser_buscarPorId(eUsuario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int eUser_mostrarUno(eUsuario parametro)
{
     printf("\n %s - %d - %d",parametro.nombre,parametro.idUsuario,parametro.estado);

}

int eUser_mostrarListado(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                eUser_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}


int eUser_mostrarListadoConBorrados(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUser_mostrarUno(listado[i]);
        }
    }
    return retorno;
}




int eUser_alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUser_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUser_siguienteId(listado,limite); //Me da el ID siguiente al ultimo usuario ocupado, este va a ser el id del nuevo usuario.

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                retorno = 0;
                strcpy(listado[indice].nombre,"Juan ");
                listado[indice].idUsuario = id;
                listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}

int eUser_modificacion(eUsuario listado[] ,int limite)
{
    int id, indiceUser=-1;

    eUser_mostrarListado(listado,limite);

    printf("\nIngrese ID de usuario a modificar: ");
    scanf("%d",&id);

    indiceUser=eUser_buscarPorId(listado,limite,id);

    if(indiceUser>=0)
    {
        eUser_mostrarUno(listado[indiceUser]);

        printf("\nIngrese nuevo nombre: ");
        fflush(stdin);
        gets(listado[indiceUser].nombre);

        eUser_mostrarUno(listado[indiceUser]);
    }

    return indiceUser;
}

int eUser_baja(eUsuario listado[] ,int limite)
{
    int id, indiceUser=-1;

    eUser_mostrarListado(listado,limite);

    printf("\nIngrese ID de usuario a dar de baja: ");
    scanf("%d",&id);

    indiceUser=eUser_buscarPorId(listado,limite,id);

    if(indiceUser>=0)
    {
        eUser_mostrarUno(listado[indiceUser]);

        listado[indiceUser].estado=-5;
        listado[indiceUser].idUsuario=0;
        strcpy(listado[indiceUser].nombre, "");
        printf("\n");
        eUser_mostrarUno(listado[indiceUser]);
    }

    return indiceUser;
}

int eProducto_buscarLugarLibre(eProducto listadoProductos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoProductos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listadoProductos[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProducto_siguienteId(eProducto listadoProductos[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listadoProductos != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listadoProductos[i].estado == OCUPADO)
            {
                    if(listadoProductos[i].idProducto>retorno)
                    {
                         retorno=listadoProductos[i].idProducto;
                    }

            }
        }
    }

    return retorno+1;
}

int eProducto_altaPublicacion(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
{
    int idUsuario, indiceVacio, idProducto;

    eUser_mostrarListado(listadoUsuarios,largoUsuarios);

    printf("\nIngrese ID de usuario que publica:");
    scanf("%d",&idUsuario);

    indiceVacio=eProducto_buscarLugarLibre(listadoProductos,largoProductos);

    idProducto=eProducto_siguienteId(listadoProductos,largoProductos);

    listadoProductos[indiceVacio].idProducto=idProducto;
    listadoProductos[indiceVacio].idUsuario=idUsuario;

    printf("\nIngrese nombre de producto:");
    fflush(stdin);
    gets(listadoProductos[indiceVacio].nombre);

    printf("\nIngrese precio del producto:");
    scanf("%f",&listadoProductos[indiceVacio].precio);

    printf("\nIngrese stock del producto:");
    scanf("%d",&listadoProductos[indiceVacio].stock);
}

int eProducto_modificarPublicacion(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
{
    int id, indiceUser=-1;

    eUser_mostrarListado(listado,limite);

    printf("\nIngrese ID de usuario a modificar: ");
    scanf("%d",&id);

    indiceUser=eUser_buscarPorId(listado,limite,id);

    if(indiceUser>=0)
    {
        eUser_mostrarUno(listado[indiceUser]);

        printf("\nIngrese nuevo nombre: ");
        fflush(stdin);
        gets(listado[indiceUser].nombre);

        eUser_mostrarUno(listado[indiceUser]);
    }

    return indiceUser;
}

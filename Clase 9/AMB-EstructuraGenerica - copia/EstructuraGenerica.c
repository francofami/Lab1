#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1
#define BORRADO -5


int eUser_init(eUsuario listado[],int limite)
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

int eProducto_init(eProducto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].idProducto= 0;
            listado[i].cantidadVentas=0;
        }
    }
    return retorno;
}

int eVenta_init(eVenta listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].idVenta=0;
        }
    }
    return retorno;
}

int eVenta_siguienteId(eVenta listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idVenta>retorno)
                    {
                         retorno=listado[i].idVenta;
                    }
            }
        }
    }

    return retorno+1;
}

int eVenta_buscarLugarLibre(eVenta listado[],int limite)
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



void eUser_mostrarUno(eUsuario parametro)
{
     printf("\n %s - %d - %d\n",parametro.nombre,parametro.idUsuario,parametro.estado);
}

void eProducto_mostrarUno(eProducto parametro)
{
     printf("\n Nombre: %s ID Programa: %d - %f - %d\n",parametro.nombre,parametro.idProducto,parametro.precio,parametro.stock);
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

int eProducto_mostrarListado(eProducto listado[],int limite)
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
                eProducto_mostrarUno(listado[i]);
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
    int idUsuario, indiceVacio=-1, idProducto, retorno=-1;

    eUser_mostrarListado(listadoUsuarios,largoUsuarios);

    printf("\nIngrese ID de usuario que publica: ");
    scanf("%d",&idUsuario);

    if(largoProductos > 0 && listadoProductos != NULL)
    {
        retorno=-2;
        indiceVacio=eProducto_buscarLugarLibre(listadoProductos,largoProductos);

    if(indiceVacio >= 0)
        {
            retorno = -3;

            idProducto=eProducto_siguienteId(listadoProductos,largoProductos);
            listadoProductos[indiceVacio].idProducto=idProducto;
            listadoProductos[indiceVacio].idUsuario=idUsuario;

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
            retorno=0;

            printf("\nIngrese nombre de producto:");
            fflush(stdin);
            gets(listadoProductos[indiceVacio].nombre);

            printf("\nIngrese precio del producto:");
            scanf("%f",&listadoProductos[indiceVacio].precio);

            printf("\nIngrese stock del producto:");
            scanf("%d",&listadoProductos[indiceVacio].stock);

            listadoProductos[indiceVacio].idUsuario=idUsuario;
            listadoProductos[indiceVacio].estado=OCUPADO;
            //
        }


    }

    return retorno;
}

int eProducto_modificarPublicacion(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
{
    int idUsuario, indiceProducto=-1, idProducto;

    eUser_mostrarListado(listadoUsuarios,largoUsuarios);

    printf("\nIngrese ID de usuario cuya publicacion quiera modificar: ");
    scanf("%d",&idUsuario);

    eProducto_mostrarProductosPorIdUsuario(listadoProductos, listadoUsuarios, largoProductos, largoUsuarios, idUsuario);

    printf("\nIngrese ID de producto a modificar: ");
    scanf("%d",&idProducto);

    indiceProducto=eProducto_buscarPorId(listadoProductos,  largoProductos, idProducto);

    if(indiceProducto>=0)
    {
        eProducto_mostrarUno(listadoProductos[indiceProducto]);

        printf("\nIngrese nuevo precio: ");
        scanf("%f", &listadoProductos[indiceProducto].precio);

        printf("\nIngrese stock: ");
        scanf("%d", &listadoProductos[indiceProducto].stock);


        eProducto_mostrarUno(listadoProductos[indiceProducto]);
    }

    return indiceProducto;
}

void eProducto_mostrarProductosPorIdUsuario(eProducto listadoProductos[],eUsuario listadoUsuarios[], int largoProductos, int largoUsuarios, int id)
{
    int i;

    if(largoProductos > 0 && listadoProductos != NULL)
    {
        for(i=0;i<largoProductos;i++)
        {
            if(listadoProductos[i].estado == OCUPADO && listadoProductos[i].idUsuario == id)
            {
                printf("\n Nombre: %s ID producto: %d Precio: %.2f Stock: %d", listadoProductos[i].nombre, listadoProductos[i].idProducto, listadoProductos[i].precio, listadoProductos[i].stock);
            }
        }
    }
}

int eProducto_buscarPorId(eProducto listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProducto_cancelarPublicacion(eUsuario listadoUsuarios[], eProducto listadoProductos[], int largoProductos, int largoUsuarios)
{
    int idUsuario, indiceProducto=-1, idProducto;

    eUser_mostrarListado(listadoUsuarios,largoUsuarios);

    printf("\nIngrese ID de usuario cuya publicacion quiera cancelar: ");
    scanf("%d",&idUsuario);

    eProducto_mostrarProductosPorIdUsuario(listadoProductos, listadoUsuarios, largoProductos, largoUsuarios, idUsuario);

    printf("\nIngrese ID de producto a cancelar: ");
    scanf("%d",&idProducto);

    indiceProducto=eProducto_buscarPorId(listadoProductos,  largoProductos, idProducto);

    if(indiceProducto>=0)
    {
        eProducto_mostrarUno(listadoProductos[indiceProducto]);
    }

    return indiceProducto;
}

int comprarProducto(eProducto listadoProductos[],eVenta listadoVentas[],int largoProductos,int largoVentas)
{
    int idComprar, indiceProducto, cantidadCompra, indiceVenta, idVenta;

    eProducto_mostrarListado(listadoProductos, largoProductos);

    printf("Ingrese ID del producto a comprar: ");
    scanf("%d", &idComprar);

    indiceProducto=eProducto_buscarPorId(listadoProductos,  largoProductos, idComprar);

    if(listadoProductos[indiceProducto].stock>0)
    {
        do{
            printf("Ingrese cantidad a comprar (Stock: %d)", listadoProductos[indiceProducto].stock);
            scanf("%d", &cantidadCompra);
        }while(cantidadCompra<=listadoProductos[indiceProducto].stock);


        listadoProductos[indiceProducto].stock-=cantidadCompra;
        listadoProductos[indiceProducto].cantidadVentas+=cantidadCompra;

        indiceVenta = eVenta_buscarLugarLibre(listadoVentas,largoVentas);
        idVenta = eVenta_siguienteId(listadoVentas,largoVentas);

        do{
            printf("Ingrese calificacion (del 1 al 10):");
            scanf("%d", &listadoProductos[indiceProducto].stock);
        }while(listadoVentas[indiceVenta].calificacion<1 || listadoVentas[indiceVenta].calificacion>10);

        listadoVentas[indiceVenta].idVenta=idVenta;
    }
}


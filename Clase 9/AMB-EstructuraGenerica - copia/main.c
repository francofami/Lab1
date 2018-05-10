#include <stdio.h>
#include <stdlib.h>
#include "EstructuraGenerica.h"
//#include "susFunciones.h"
#define CANTIDADUSUARIOS 100
#define CANTIDADPRODUCTOS 1000


int main()
{
    char seguir='s';
    int opcion, retorno;
    char opcionString[2];

    eUsuario listaUsuarios[CANTIDADUSUARIOS];
    eProducto listaProductos[CANTIDADPRODUCTOS];

    eUser_init(listaUsuarios,CANTIDADUSUARIOS);
    eProducto_init(listaProductos,CANTIDADPRODUCTOS);

    while(seguir=='s')
    {
        printf("1- Alta de usuario\n");
        printf("2- Modificar datos de usuario\n");
        printf("3- Baja de usuario\n");
        printf("4- Publicar\n");
        printf("5- Modificar publicacion\n");
        printf("6- Cancelar publicacion\n");
        printf("7- Comprar producto\n");
        printf("8- Listar publicaciones de usuario\n");
        printf("9- Listar publicaciones\n");
        printf("10- Listar usuarios\n");
        printf("11- Salir\n");

        do{
            fflush(stdin);
            scanf("%d",&opcion);
            itoa(opcion, opcionString, 2);
        }while(opcion<1 || opcion>11 || validarNumero(opcionString)==0);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                  retorno=eUser_alta(listaUsuarios,CANTIDADUSUARIOS);
                  if(retorno!=0)
                  printf("Error, no se pudo hacer la alta del usuario. ");
                  if(retorno<0)
                  printf("No hay mas lugar libre.\n");
                }
                break;
            case 2:
                eUser_modificacion(listaUsuarios,CANTIDADUSUARIOS);
                break;
            case 3:
                eUser_baja(listaUsuarios,CANTIDADUSUARIOS, listaProductos, CANTIDADPRODUCTOS);
                break;
            case 4:
                eProducto_altaPublicacion(listaUsuarios, listaProductos, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 5:
                eProducto_modificarPublicacion(listaUsuarios,listaProductos, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 6:
                eProducto_cancelarPublicacion(listaUsuarios,listaProductos, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 7:
                eProducto_comprarProducto(listaUsuarios,listaProductos, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 8:
                eUser_listarPublicacionesUsuario(listaUsuarios,CANTIDADUSUARIOS, listaProductos,CANTIDADPRODUCTOS);
                 break;
            case 9:
                eProducto_mostrarListado(listaProductos,CANTIDADPRODUCTOS);
                break;
            case 10:
                eUser_listarCalificaciones(listaUsuarios,CANTIDADUSUARIOS, listaProductos,CANTIDADPRODUCTOS);
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }

    /*
    printf( "\n \t muestro el array... esta vacio");
    eGen_mostrarListado(listaUsuarios,CANTIDADUSUARIOS);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios");
    eGen_mostrarListadoConBorrados(listaUsuarios,CANTIDADUSUARIOS);
    getchar();


    printf( "\n \t cargo dos elementos y muestro el array");
    eGen_mostrarListado(listaUsuarios,CANTIDADUSUARIOS);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios");
    eGen_mostrarListadoConBorrados(listaUsuarios,CANTIDADUSUARIOS);
    getchar();
    */

    return 0;
}

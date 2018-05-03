#include <stdio.h>
#include <stdlib.h>
#include "EstructuraGenerica.h"
//#include "susFunciones.h"
#define CANTIDADUSUARIOS 10
#define CANTIDADPRODUCTOS 10

int main()
{
    char seguir='s';
    int opcion=0;

    eUsuario listaUsuarios[CANTIDADUSUARIOS];
    eProducto listaProductos[CANTIDADPRODUCTOS];

    eUser_init(listaUsuarios,CANTIDADUSUARIOS);

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

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                eUser_alta(listaUsuarios,CANTIDADUSUARIOS);
                break;
            case 2:
                eUser_modificacion(listaUsuarios,CANTIDADUSUARIOS);
                break;
            case 3:
                eUser_baja(listaUsuarios,CANTIDADUSUARIOS);
                break;
            case 4:
                eProducto_altaPublicacion(listaProductos, listaUsuarios, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 5:
                eProducto_modificarPublicacion(listaProductos, listaUsuarios, CANTIDADPRODUCTOS, CANTIDADUSUARIOS);
                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                 break;
            case 9:

                break;
            case 10:

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

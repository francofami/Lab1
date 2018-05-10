#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDADPROPIETARIOS 20
#define CANTIDADAUTOS 20

int main()
{
    char seguir='s';
    int opcion, retorno;
    char opcionString[2];

    ePropietario listaPropietarios[CANTIDADPROPIETARIOS];
    eAuto listaAutos[CANTIDADAUTOS];


    ePropietario_init(listaPropietarios,CANTIDADPROPIETARIOS);
    eAuto_init(listaAutos,CANTIDADAUTOS);

    inicializarPropietariosHardCode(listaPropietarios);
     hardcoreIngresos(listaAutos);


    while(seguir=='s')
    {
        printf("1- Alta de propietario\n");
        printf("2- Modificar datos de propietario\n");
        printf("3- Baja de propietario\n");
        printf("4- Mostrar listado\n");
        printf("5- Ingreso de auto\n");
        printf("6- Egreso de auto\n");
        printf("7- Listar autos estacionados\n");
        printf("8- Salir\n");


        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                  retorno=ePropietario_alta(listaPropietarios,CANTIDADPROPIETARIOS);
                  if(retorno!=0)
                  printf("Error, no se pudo hacer el alta del propietario. ");
                  if(retorno<0)
                  printf("No hay mas lugar libre.\n");
                }
                break;
            case 2:
                ePropietario_modificacion(listaPropietarios,CANTIDADPROPIETARIOS);
                break;
            case 3:
                ePropietario_baja(listaPropietarios,CANTIDADPROPIETARIOS);
                break;
            case 4:
                ePropietario_mostrarListado(listaPropietarios,CANTIDADPROPIETARIOS);
                break;
            case 5:
                eAuto_ingreso(listaAutos, listaPropietarios, CANTIDADAUTOS,CANTIDADPROPIETARIOS);
                break;
            case 6:
                eAuto_egreso(listaAutos, listaPropietarios, CANTIDADAUTOS,CANTIDADPROPIETARIOS);
                break;
            case 7:
                eAuto_mostrarListado(listaAutos,CANTIDADAUTOS);
                break;
            case 8:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
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
        printf("7- Egresar autos (hardcode)\n");
        printf("8- Listar autos estacionados\n");
        printf("9- Listar autos egresados\n");
        printf("10- Mostrar recaudacion total del estacionamiento\n");
        printf("11- Mostrar recaudacion total por marca\n");
        printf("12- Buscar autos por ID propietario\n");
        printf("13- Mostrar datos de propietarios de autos AUDI\n");
        printf("14- Listar autos estacionados (ordenados por patente)\n");
        printf("15- Salir\n");

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
                egresosHardcode(listaAutos);
                break;
            case 8:
                eAuto_mostrarListado(listaAutos,CANTIDADAUTOS);
                break;
            case 9:
                eAuto_mostrarEgresos(listaAutos, CANTIDADAUTOS, listaPropietarios, CANTIDADPROPIETARIOS);
                break;
            case 10:
                eAuto_recaudacionTotal(listaAutos, CANTIDADAUTOS);
                break;
            case 11:
                eAuto_recaudacionPorMarca(listaAutos, CANTIDADAUTOS);
                break;
            case 12:
                eAuto_buscarPorIdPropietario(listaAutos, CANTIDADAUTOS, listaPropietarios, CANTIDADPROPIETARIOS);
                break;
            case 13:
                eAuto_datosAudi(listaAutos, CANTIDADAUTOS, listaPropietarios, CANTIDADPROPIETARIOS);
                break;
            case 14:
                eAuto_estacionadosPorPatente(listaAutos, CANTIDADAUTOS, listaPropietarios, CANTIDADPROPIETARIOS);
                break;
            case 15:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

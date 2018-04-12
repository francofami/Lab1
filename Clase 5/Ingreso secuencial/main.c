#include <stdio.h>
#include <stdlib.h>
#define alert printf
#include "funcionesVectores.h"



int main()
{
    int edad, i;
    float precio;
    int listadoEdades[5]={22,33,44,11,55}; //Lo que le paso entre {} debe ser del mismo tipo y de la misma cantidad que el array.
    float listadoPrecios[5];

    /* edad=66;

    alert("%d\n",edad);
    alert("%d",&edad);

    alert("&listadoEdades: %d\n", &listadoEdades);
    alert("listadoEdades: %d\n", listadoEdades);
    alert("&listadoEdades: %p\n", &listadoEdades); //Al poner %p se refiere a puntero y muestra la direccion en hexa
    alert("listadoEdades[0]: %d\n", listadoEdades[0]);
    alert("&listadoEdades[0]: %d\n", &listadoEdades[0]);
    alert("listadoEdades[4]: %d\n", listadoEdades[4]);
    alert("listadoEdades[5]: %d\n", listadoEdades[5]);

    for(i=0;i<5;i++)
    {
        alert("Ingrese el numero %d: ",i);
        scanf("%d", &listadoEdades[i]);
    }

    for(i=0;i<5;i++)
    {
        alert("%d: %d\n",i, listadoEdades[i]);
    }

    for(i=0;i<5;i++)
    {
        alert("Ingrese precio %d: ", i);
        scanf("%f", &listadoPrecios[i]);
    }

    for(i=0;i<5;i++)
    {
        alert("%d: %f\n",i, listadoPrecios[i]);
    } */

    ejemploCargaSecuencial();


    return 0;
}

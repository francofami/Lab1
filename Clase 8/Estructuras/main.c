#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nosequenombreponerle.h"
#include "localidad.h"
#define LENGHT 3

void mostrarListado(eLocalidad[], int);

int main()
{
    eLocalidad lokalida;
    eLocalidad listadoLocalidades;


    lokalida.esta2=1; //Eso quiere decir que esta ocupado
    lokalida.id=555;
    strcpy(lokalida.nombreLocalidad, "Maria");

    //printf("%s",lokalida.nombreLocalidad);

    loc_mostrar1(lokalida);

    return 0;
}




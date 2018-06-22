#include<stdio.h>
#include "tramite.h"

eTramite* new_Tramite()
{
    eTramite* aux;
    aux= (eTramite*) malloc(sizeof(eTramite));
}

int setId(eTramite* this, int id)
{
    int seteo=-1;

    if(this!=NULL)
    {
        this->idTramite=id;
        seteo=0;
    }

    return seteo;
}

int getId(eTramite* this)
{
    int id=-1;

    if(this!=NULL)
    {
        id=this->idTramite;
    }

    return id;
}

int setDni(eTramite* this, char* dni)
{
    int seteo=-1;

    if(this!=NULL && dni!=NULL)
    {
        strcpy(this->dni,dni);
        seteo=0;
    }

    return seteo;
}

int getDni(eTramite* this)
{
    int dni=-1;

    if(this!=NULL)
    {
        dni=this->dni; //Acá estoy copiando la direccion de memoria por eso pongo el =
    }

    return dni;
}

int mostrarTramite(eTramite* this)
{
    if(this!=NULL)
    {
        printf("ID: %d - DNI: %s\n", getId(this), getDni(this));
    }
}

int compararPorDni(void* tramiteA, void* tramiteB)
{
    eTramite* tramite1;
    eTramite* tramite2;

    tramite1 = (eTramite*) tramiteA;
    tramite2 = (eTramite*) tramiteB;

    return strcmp(tramite1->dni, tramite2->dni);
}

int mostrarListaTramites(ArrayList* listado)
{
    int listo = -1, length, i;
    eTramite* tramiteActual;

    if(listado!=NULL)
    {
        length=listado->len(listado);
        for(i=0;i<length;i++)
        {
            tramiteActual=(eTramite*) listado->get(listado,i);
            mostrarTramite(tramiteActual);
        }
        listo=0;
    }

    return listo;
}

int cargarTramite(ArrayList* listado, int id, char* dni)
{
    eTramite* tramiteActual;
    int cargo=-1;

    if(listado!=NULL && id>0 && dni!=NULL)
    {
        tramiteActual=new_Tramite();

        setId(tramiteActual, id);
        setDni(tramiteActual, dni);

        listado->add(listado,tramiteActual);
        cargo=0;
    }
    return cargo;
}

int atenderTramite(ArrayList* listaPendientes, ArrayList* listaAtendidos)
{
    int returnAux=-1;
    eTramite* tramiteActual;

    if(listaPendientes!=NULL & listaAtendidos!=NULL)
    {
        tramiteActual = (eTramite*) listaPendientes->pop(listaPendientes,0);
        printf("Cliente a ser atendido (URGENTE): ");

        listaAtendidos->add(listaAtendidos, tramiteActual);

        mostrarTramite(tramiteActual);
    }
}

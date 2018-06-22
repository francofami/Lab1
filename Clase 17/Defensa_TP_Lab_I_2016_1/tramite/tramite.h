#ifndef TRAMITE_H_INCLUDED
#define TRAMITE_H_INCLUDED
#include "ArrayList.h"

typedef struct{
    int idTramite;
    char dni[20];
}eTramite;

eTramite* new_Tramite();

int setId(eTramite* ,int);
int getId(eTramite*);

int setDni(eTramite* ,char*);
int getDni(eTramite*);

int mostrarTramite(eTramite*);

int compararPorDni(void* tramiteA, void* tramiteB);

int mostrarListaTramites(ArrayList* listado);

int cargarTramite(ArrayList*, int id, char* dni);

int atenderTramite(ArrayList*, ArrayList*);

#endif // TRAMITE_H_INCLUDED

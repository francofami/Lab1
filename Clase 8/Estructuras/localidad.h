#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
int id;
int esta2;
char nombreLocalidad[50];
}eLocalidad;


#endif // LOCALIDAD_H_INCLUDED

void loc_mostrar1(eLocalidad aux);
void loc_listarLoc(eLocalidad xd);

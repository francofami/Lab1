#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"

void nuevoProducto();
ArrayList* leerDatos();
ArrayList* leerTemporal();
void ordenarLista(ArrayList* this);
void modificacion();
void guardarListaEnArchivo(ArrayList* this);
void bajaLogica();
void bajaFisica();
void guardarListaEnArchivoTemporal(ArrayList* this);

#endif // FUNCIONES_H_INCLUDED

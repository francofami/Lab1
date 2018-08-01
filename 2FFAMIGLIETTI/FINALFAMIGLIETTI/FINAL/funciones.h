#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"

/** \brief Parser de las letras
 *
 * \param this ArrayList* lista donde se guardan
 * \return int -1 si hay error, 0 si no hubo
 *
 */
int parserLetras(ArrayList* this);

void completar(ArrayList* this);

ArrayList* listarA(ArrayList* listarDos);

void generarCompleto(ArrayList* this);

void generarRepetidos(ArrayList* this);

ArrayList* listarB(ArrayList* this);

void generarDepurado(ArrayList* this);


#endif // FUNCIONES_H_INCLUDED

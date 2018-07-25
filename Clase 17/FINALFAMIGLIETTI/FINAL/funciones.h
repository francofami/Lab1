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

void listar();

#endif // FUNCIONES_H_INCLUDED

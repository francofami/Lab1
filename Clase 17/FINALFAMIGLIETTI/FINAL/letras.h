#ifndef LETRAS_H_INCLUDED
#define LETRAS_H_INCLUDED
#include "ArrayList.h"

struct
{
    char letra;
	char nombre[22];
	int vocal;
	int consonante;

}typedef eLetra;

#endif // LETRAS_H_INCLUDED

/** \brief Constructor.
 *
 * \param void
 * \return eLetra* Puntero a estructura
 *
 */
eLetra* eLetra_new(void);



/** \brief Setter.
 *
 *
 * \param this eLetra* El puntero a la estructura donde se va a asingnar la variable letra.
 * \param letra char* La variable letra que se va a asingar.
 * \return int Devuelve -1 si hay error, sino devuelve 0.
 *
 */
int eLetra_setletra(eLetra* this, char letra);


/** \brief Getter.
 *
 *
 * \param this eLetra* El puntero a estructura donde se obtiene la variable letra.
 * \return int Devuelve -1 si hay error, sino devuelve 0.
 *
 */
int eLetra_getletra(eLetra* this);


/** \brief Setter.
 *
 *
 * \param this eLetra* El puntero a la estructura donde se va a asingnar la variable nombre.
 * \param nombre char* La variable nombre que se va a asingar.
 * \return int Devuelve -1 si hay error, sino devuelve 0.
 *
 */
int eLetra_setnombre(eLetra* this, char* nombre);


/** \brief Getter.
 *
 *
 * \param this eLetra* El puntero a estructura donde se obtiene la variable nombre.
 * \return int Devuelve -1 si hay error, sino devuelve 0.
 *
 */
int eLetra_getnombre(eLetra* this);


/** \brief Setter.
 *
 *
 * \param this eLetra* El puntero a la estructura donde se va a asingnar la variable vocal.
 * \param vocal int La variable vocal que se va a asingar.
 * \return int Devuelve -1 si hay error, sino devuelve 0.
 *
 */
int eLetra_setvocal(eLetra* this, int vocal);

/** \brief Imprime una
 *
 * \param this eLetra*
 * \return void
 *
 */
void eLetra_print(eLetra* this);

/** \brief Imprime todas
 *
 * \param this ArrayList*
 * \return void
 *
 */
void eLetra_printAll(ArrayList* this);


/** \brief Getter.
 *
 *
 * \param this eLetra* El puntero a estructura donde se obtiene la variable vocal.
 * \return int Devuelve -1 si hay error, sino devuelve 0.
 *
 */
int eLetra_getvocal(eLetra* this);

/** \brief Setter.
 *
 *
 * \param this eLetra* El puntero a la estructura donde se va a asingnar la variable consonante.
 * \param consonante int La variable consonante que se va a asingar.
 * \return int Devuelve -1 si hay error, sino devuelve 0.
 *
 */
int eLetra_setconsonante(eLetra* this, int consonante);


/** \brief Getter.
 *
 *
 * \param this eLetra* El puntero a estructura donde se obtiene la variable consonante.
 * \return int Devuelve -1 si hay error, sino devuelve 0.
 *
 */
int eLetra_getconsonante(eLetra* this);

int esV(char letra);

int esC(char letra);

int compararAlfabeticamente(void* letraA, void* letraB);

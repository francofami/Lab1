#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Abre el archivo data.csv y copia su contenido a una lista.
 *
 * \param pFile FILE* El puntero al archivo data.csv
 * \param this ArrayList* La lista donde se copia el contenido del archivo datos.csv
 * \return int Devuelve -1 si hay error, de lo contrario devuelve 0.
 *
 */
int parserEmpleados(FILE* pFile, ArrayList* this);

/** \brief Crea el archivo out.csv con los datos que contiene una lista filtrada.
 *
 * \param pFile FILE* El puntero al archivo out.csv
 * \param pList ArrayList* La lista filtrada
 * \return int Devuelve -1 si hay error, de lo contrario devuelve 0.
 *
 */
int crearArchivo(FILE* pFile, ArrayList* pList);

#endif // FUNCIONES_H_INCLUDED

#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[51];
    float importe;
    int cantidad;
    int activo;
}productos;

/** \brief Constructor. Asigna espacio en memoria a una variable de tipo productos*.
 *
 * \param void
 * \return productos* La variable de tipo empleador* a añadir.
 *
 */
productos* productos_new(void);

/** \brief Libera espacio en memoria ocupado por una variable de tipo productos*.
 *
 * \param this productos* La variable de tipo empleador* a eliminar.
 * \return void
 *
 */
void productos_delete(productos* this);

/** \brief Se le asigna la ID a una variable de tipo productos*.
 *
 *
 * \param this productos* La variable donde se va a asignar la ID.
 * \param id int La ID a asignar.
 * \return int Devuelve -1 si la variable de tipo productos* o la ID es menor a 0, sino devuelve 0.
 *
 */
int productos_setCodigo(productos* this, int codigo);

/** \brief Obtiene la ID de una variable de tipo productos*.
 *
 * \param this productos* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo productos* es igual a NULL, sino la direccion de memoria donde esta guardada la ID.
 *
 */
int productos_getCodigo(productos* this);

/** \brief Se le asigna el nombre a una variable de tipo productos*.
 *
 * \param this productos* La variable donde se va a asignar el nombre.
 * \param nombre char* El nombre a asignar.
 * \return int Devuelve -1 si la variable de tipo productos* o el nombre es igual a NULL, sino 0.
 *
 */
int productos_setDescripcion(productos* this, char* descripcion);

/** \brief
 *
 * \param this productos* Variable en la que se obtiene el elemento.
 * \return int Devuelve -1 si la variable de tipo productos* es igual a NULL, sino la direccion de memoria donde esta guardado el nombre.
 *
 */
int productos_getDescripcion(productos* this);

/** \brief Se le asigna la ID a una variable de tipo productos*.
 *
 *
 * \param this productos* La variable donde se va a asignar la ID.
 * \param id int La ID a asignar.
 * \return int Devuelve -1 si la variable de tipo productos* o la ID es menor a 0, sino devuelve 0.
 *
 */
int productos_setImporte(productos* this, float importe);

/** \brief Obtiene la ID de una variable de tipo productos*.
 *
 * \param this productos* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo productos* es igual a NULL, sino la direccion de memoria donde esta guardada la ID.
 *
 */
int productos_getImporte(productos* this);

/** \brief Se le asigna la ID a una variable de tipo productos*.
 *
 *
 * \param this productos* La variable donde se va a asignar la ID.
 * \param id int La ID a asignar.
 * \return int Devuelve -1 si la variable de tipo productos* o la ID es menor a 0, sino devuelve 0.
 *
 */
int productos_setCantidad(productos* this, int cantidad);

/** \brief Obtiene la ID de una variable de tipo productos*.
 *
 * \param this productos* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo productos* es igual a NULL, sino la direccion de memoria donde esta guardada la ID.
 *
 */
int productos_getCantidad(productos* this);

/** \brief Se le asigna la ID a una variable de tipo productos*.
 *
 *
 * \param this productos* La variable donde se va a asignar la ID.
 * \param id int La ID a asignar.
 * \return int Devuelve -1 si la variable de tipo productos* o la ID es menor a 0, sino devuelve 0.
 *
 */
int productos_setActivo(productos* this, int activo);

/** \brief Obtiene la ID de una variable de tipo productos*.
 *
 * \param this productos* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo productos* es igual a NULL, sino la direccion de memoria donde esta guardada la ID.
 *
 */
int productos_getActivo(productos* this);

void productos_print(productos* this);

void productos_printAll(ArrayList* this);

int compararPorDescripcion(void* productoA, void* productoB);

#endif // PRODUCTOS_H_INCLUDED

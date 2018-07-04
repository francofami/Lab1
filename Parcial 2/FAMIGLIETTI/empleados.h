#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

struct
{
    int id;
    char nombre[51];
    char sueldo[50];
    int edad;
    char profesion[50];

}typedef empleados;

/** \brief Constructor. Asigna espacio en memoria a una variable de tipo empleados*.
 *
 * \param void
 * \return empleados* La variable de tipo empleador* a añadir.
 *
 */
empleados* empleados_new(void);

/** \brief Libera espacio en memoria ocupado por una variable de tipo empleados*.
 *
 * \param this empleados* La variable de tipo empleador* a eliminar.
 * \return void
 *
 */
void empleados_delete(empleados* this);

/** \brief Se le asigna la ID a una variable de tipo empleados*.
 *
 *
 * \param this empleados* La variable donde se va a asignar la ID.
 * \param id int La ID a asignar.
 * \return int Devuelve -1 si la variable de tipo empleados* o la ID es menor a 0, sino devuelve 0.
 *
 */
int empleados_setId(empleados* this, int id);

/** \brief Obtiene la ID de una variable de tipo empleados*.
 *
 * \param this empleados* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo empleados* es igual a NULL, sino la direccion de memoria donde esta guardada la ID.
 *
 */
int empleados_getId(empleados* this);

/** \brief Se le asigna el nombre a una variable de tipo empleados*.
 *
 * \param this empleados* La variable donde se va a asignar el nombre.
 * \param nombre char* El nombre a asignar.
 * \return int Devuelve -1 si la variable de tipo empleados* o el nombre es igual a NULL, sino 0.
 *
 */
int empleados_setNombre(empleados* this, char* nombre);

/** \brief
 *
 * \param this empleados* Variable en la que se obtiene el elemento.
 * \return int Devuelve -1 si la variable de tipo empleados* es igual a NULL, sino la direccion de memoria donde esta guardado el nombre.
 *
 */
int empleados_getNombre(empleados* this);

/** \brief Se le asigna el sueldo a una variable de tipo empleados*.
 *
 * \param this empleados* La variable donde se va a asignar el sueldo.
 * \param sueldo char* El sueldo a asignar.
 * \return int Devuelve -1 si la variable de tipo empleados* o el sueldo es igual a NULL, sino 0.
 *
 */
int empleados_setSueldo(empleados* this, char* sueldo);

/** \brief Obtiene el sueldo de una variable de tipo empleados*.
 *
 * \param this empleados* Variable en la que se obtiene el elemento.
 * \return int Devuelve -1 si la variable de tipo empleados* es igual a NULL, sino la direccion de memoria donde esta guardado el sueldo.
 *
 */
int empleados_getSueldo(empleados* this);

/** \brief Se le asigna la edad a una variable de tipo empleados*.
 *
 *
 * \param this empleados* La variable donde se va a asignar la edad.
 * \param edad int La edad a asignar.
 * \return int Devuelve -1 si la variable de tipo empleados* o la edad es menor a 0, sino devuelve 0.
 *
 */
int empleados_setEdad(empleados* this, int edad);

/** \brief Obtiene la edad de una variable de tipo empleados*.
 *
 * \param this empleados* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo empleados* es igual a NULL, sino la direccion de memoria donde esta guardada la edad.
 *
 */
int empleados_getEdad(empleados* this);

/** \brief Se le asigna la profesión a una variable de tipo empleados*.
 *
 * \param this empleados* La variable donde se va a asignar la profesion.
 * \param profesion char* La profesion a asignar.
 * \return int Devuelve -1 si la variable de tipo empleados* o la profesion es igual a NULL, sino 0.
 *
 */
int empleados_setProfesion(empleados* this, char* profesion);

/** \brief Obtiene la profesion de una variable de tipo empleados*.
 *
 * \param this empleados* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo empleados* es igual a NULL, sino la direccion de memoria donde esta guardada la profesion.
 *
 */
int empleados_getProfesion(empleados* this);

/** \brief
 *
 * \param this empleados*
 * \return void
 *
 */
void empleados_print(empleados* this);

/** \brief Muestra en pantalla todos los elementos del arraylist.
 *
 * \param this ArrayList* El arraylist a imprimir.
 * \return void
 *
 */
void empleados_printAll(ArrayList* this);

/** \brief Esta funcion llama a los setters para asi poder agregar elementos a una lista.
 *
 * \param id int El id del empleado.
 * \param nombre char* El nombre del empleado.
 * \param sueldo char* El sueldo del empleado.
 * \param edad int La edad del empleado.
 * \param profesion char* La profesion del empleado.
 * \return empleados* Una variable que contiene los datos de un empleado.
 *
 */
empleados* empleados_newParametros(int id, char* nombre, char* sueldo, int edad, char* profesion);

/** \brief Filtra empleados segun su edad (mayores a 30) y profesion (Programador).
 *
 * \param item void* Empleado a filtrar.
 * \return int Devuelve 1 para mantener el elemento en la lista de salida y 0 para filtrarlo.
 *
 */
int funcionQueFiltra(void* item);

#endif // EMPLEADOS_H_INCLUDED

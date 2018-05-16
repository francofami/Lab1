#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "propietarios.h"

typedef struct
{
    int marca;
    char patente[20];
    int idPropietario;
    int idAuto;
    int estado;
    float importe;

}eAuto;

#endif // AUTOS_H_INCLUDED

/** \brief Hardcodeo ingreso de autos
 *
 * \param eAuto[] Array de autos
 * \return void
 *
 */
void hardcoreIngresos(eAuto[]);

/** \brief Inicializa los autos en estado 0 (no estacionado)
 *
 * \param ePropietario[] El array que contiene a los autos.
 * \param int El largo del array que contiene a los autos.
 * \return void
 *
 */
void eAuto_init(eAuto[],int);

/** \brief Permite ingresar auto que estaciona
 *
 * \param listadoAutos[] eAuto array de autos
 * \param listadoPropietarios[] ePropietario array de propietarios
 * \param largoAutos int largo de array de autos
 * \param largoPropietarios int largo de array de propietarios
 * \return void
 *
 */
void eAuto_ingreso(eAuto listadoAutos[],ePropietario listadoPropietarios[], int largoAutos, int largoPropietarios);

/** \brief Muestra un solo auto
 *
 * \param parametro eAuto array de autos
 * \return void
 *
 */
void eAuto_mostrarUno(eAuto parametro);

/** \brief Muestra listado de autos estacionados.
 *
 * \param listadoAutos[] eAuto array de autos.
 * \param limite int largo del array de autos.
 * \return void
 *
 */
void eAuto_mostrarListado(eAuto listadoAutos[],int limite);

/** \brief Recorre el vector de usuarios buscando el primero que tenga estado libre y devuelve su índice.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param int El largo del array que contiene los usuarios.
 * \return int Devuelve la posición del vector en la que se encontró el primer usuario libre, de no encontrarlo
 * devuelve -1 o -2 (error).
 */
int eAuto_buscarLugarLibre(eAuto listado[],int limite);

/** \brief Permite el egreso de autos, calculando precio de estadia.
 *
 * \param listadoAutos[] eAuto array de autos.
 * \param listadoPropietarios[] ePropietario array de propietarios.
 * \param largoAutos int largo del array de autos.
 * \param largoPropietarios int laro del array de propietarios.
 * \return void
 *
 */
void eAuto_egreso(eAuto listadoAutos[],ePropietario listadoPropietarios[], int largoAutos, int largoPropietarios);

/** \brief Harcode egreso de autos.
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \return void
 *
 */
void egresosHardcode(eAuto listadoAutos[]);

/** \brief Muestra una lista con los autos que ya egresaron
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \param largoAutos int El largo del array que contiene a los autos.
 * \param listadoPropietarios[] ePropietario El array que contiene a los propietarios.
 * \param largoPropietarios int El largo del array que contiene a los propietarios.
 * \return void
 *
 */
void eAuto_mostrarEgresos(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios);

/** \brief Calcula y muestra en pantalla la recaudacion total del estacionamiento.
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \param largoAutos int El largo del array que contiene a los autos.
 * \return void
 *
 */
void eAuto_recaudacionTotal(eAuto listadoAutos[], int largoAutos);

/** \brief  Calcula y muestra en pantalla la recaudacion total del estacionamiento por marca de auto.
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \param largoAutos int El largo del array que contiene a los autos.
 * \return void
 *
 */
void eAuto_recaudacionPorMarca(eAuto listadoAutos[], int largoAutos);

/** \brief Se ingresa un ID de propietario y lista el nombre y las patentes y autos que tenga.
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \param largoAutos int El largo del array que contiene a los autos.
 * \param listadoPropietarios[] ePropietario El array que contiene a los propietarios.
 * \param largoPropietarios int El largo del array que contiene a los propietarios.
 * \return void
 *
 */
void eAuto_buscarPorIdPropietario(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios);

/** \brief Muestra los datos de los propietarios que tengan autos estacionados de la marca AUDI.
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \param largoAutos int El largo del array que contiene a los autos.
 * \param listadoPropietarios[] ePropietario El array que contiene a los propietarios.
 * \param largoPropietarios int El largo del array que contiene a los propietarios.
 * \return void
 *
 */
void eAuto_datosAudi(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios);

/** \brief Muestra listado de autos estacionados con sus propietarios, ordenado por patente.
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \param largoAutos int El largo del array que contiene a los autos.
 * \param listadoPropietarios[] ePropietario El array que contiene a los propietarios.
 * \param largoPropietarios int El largo del array que contiene a los propietarios.
 * \return void
 *
 */
void eAuto_estacionadosPorPatente(eAuto listadoAutos[], int largoAutos, ePropietario listadoPropietarios[], int largoPropietarios);

/** \brief Busca el ultimo auto en estado OCUPADO y devuelve el siguiente ID
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \param limite int El largo del array que contiene a los autos.
 * \return int El id siguiente al ultimo auto en estado OCUPADO
 *
 */
int eAuto_siguienteId(eAuto listadoAutos[],int limite);

/** \brief Se ingresa el ID del auto a buscar y devuelve la posicion del array.
 *
 * \param listadoAutos[] eAuto El array que contiene a los autos.
 * \param limite int El largo del array que contiene a los autos.
 * \param id int LA ID del auto a buscar
 * \return int La posicion del array del auto que se busca
 *
 */
int eAuto_buscarPorId(eAuto listadoAutos[] ,int limite, int id);

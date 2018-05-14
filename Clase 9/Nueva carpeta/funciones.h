#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombreApellido[100];
    char direccion[100];
    int idPropietario;
    char tarjetaCredito[20];
    int estado;

}ePropietario;

typedef struct
{
    int marca;
    char patente[20];
    int idPropietario;
    int idAuto;
    int estado;
    float importe;

}eAuto;

#endif // FUNCIONES_H_INCLUDED

/** \brief Hardcodeo propietarios
 *
 * \param listadoPropietarios[] ePropietarios Array de propietarios
 * \return void
 *
 */
void inicializarPropietariosHardCode(ePropietario[]);

/** \brief Hardcodeo ingreso de autos
 *
 * \param eAuto[] Array de autos
 * \return void
 *
 */
void hardcoreIngresos(eAuto[]);

/** \brief Hardcodeo egreso de autos
 *
 * \param eAuto[] Array de autos
 * \return void
 *
 */
//void hardcoireEgresos(eAuto[]);

/** \brief Valida que solo se ingresen numeros
 *
 * \param numero int Una copia del numero ingresado por el usuario.
 * \return int Devuelve 0 en caso de error y un 1 si esta bien.
 *
 */
int validarNumero(char numero[]);

/** \brief Inicializa los propietarios en estado 0 (libre), tambien asigna 0 a la id y la tarjeta y deja vacios los campos de nombre y direccion.
 *
 * \param ePropietario[] El array que contiene a los propietarios.
 * \param int El largo del array que contiene a los propietarios.
 * \return void
 *
 */
void ePropietario_init(ePropietario[],int);

/** \brief Recorre el vector de usuarios buscando el primero que tenga estado libre y devuelve su índice.
 *
 * \param ePropietario[] El array que contiene a los propietarios.
 * \param int El largo del array que contiene a los propietarios.
 * \return int Devuelve la posición del vector en la que se encontró el primer propietario libre, de no encontrarlo
 * devuelve -1 o -2 (error).
 */
int ePropietario_buscarLugarLibre(ePropietario[],int );

/** \brief Recorre el vector de propietarios buscando el ultimo que tenga estado ocupado y devuelve el ID del siguiente.
 *
 * \param ePropietario[] El array que contiene a los propietarios.
 * \param limite int El largo del array que contiene a los propietarios.
 * \return int El ID del propietario siguiente al ultimo ocupado, si no devuelve 0.
 *
 */
int ePropietario_siguienteId(ePropietario[] ,int );

/** \brief Permite el alta de propietarios.
 *
 * \param ePropietario[] El array que contiene a los propietarios.
 * \param limite int El largo del array que contiene a los propietarios.
 * \return int En caso de haber lugar para propietarios nuevos devuelve 0 y de no haber devuelve -2 o -3.
 *
 */
int ePropietario_alta(ePropietario[] ,int );

/** \brief Valida que solo se ingresen letras.
 *
 * \param nombre Una copia del nombre ingresado por el usuario.
 * \return int Devuelve 0 en caso de error y un 1 si esta bien.
 *
 */
int validarNombre(char nombre[]);

/** \brief Recibe un id, recorre el vector de propietarios buscando a que posicion corresponde ese ID.
 *
 * \param ePropietario[] El array que contiene a los propietarios.
 * \param limite int El largo del array que contiene a los propietarios.
 * \param id int El ID a buscar
 * \return int La posicion que coincide con el ID, si no coincide devuelve -1.
 *
 */
int ePropietario_buscarPorId(ePropietario[] ,int , int );

/** \brief Permite modificar el nombre del propietario elegido.
 *
 * \param ePropietario[] El array que contiene a los propietarios.
 * \param limite int El largo del array que contiene a los propietarios.
 * \return void
 *
 */
void ePropietario_modificacion(ePropietario[] ,int);

/** \brief Permite dar de baja al propietario elegido (poner propietarios en estado BORRADO).
 *
* \param ePropietario[] El array que contiene a los propietarios.
 * \param limite int El largo del array que contiene a los propietarios.
 * \return void
 *
 */
void ePropietario_baja(ePropietario[] ,int );

/** \brief Muestra nombre e ID de un solo propietario.
 *
 * \param parametro ePropietario Los parametros de un solo propietario.
 * \return void
 *
 */
void ePropietario_mostrarUno(ePropietario parametro);

/** \brief Muestra el listado de todos los propietarios con estado OCUPADO.
 *
 * \param ePropietario[] El array que contiene a los propietarios.
 * \param limite int El largo del array que contiene a los propietarios.
 * \return void
 *
 */
void ePropietario_mostrarListado(ePropietario[] ,int limite);


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

/** \brief Recorre el vector de usuarios buscando el primero que tenga estado libre y devuelve su índice.
 *
 * \param eUsuario[] El array que contiene a los usuarios.
 * \param int El largo del array que contiene los usuarios.
 * \return int Devuelve la posición del vector en la que se encontró el primer usuario libre, de no encontrarlo
 * devuelve -1 o -2 (error).
 */
int eAuto_buscarLugarLibre(eAuto listado[],int limite);

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

/** \brief Permite el egreso de autos, calculando precio de estadia
 *
 * \param listadoAutos[] eAuto array de autos.
 * \param listadoPropietarios[] ePropietario array de propietarios.
 * \param largoAutos int largo del array de autos.
 * \param largoPropietarios int laro del array de propietarios
 * \return void
 *
 */
void eAuto_egreso(eAuto listadoAutos[],ePropietario listadoPropietarios[], int largoAutos, int largoPropietarios);

void egresosHardcode(eAuto listadoAutos[]);

int devolverHorasEstadia();

void eAuto_egreso(eAuto listaAutos[],ePropietario listaPropietarios[],int largoAutos,int largoPropietarios);


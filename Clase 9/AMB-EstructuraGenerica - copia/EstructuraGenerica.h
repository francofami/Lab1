#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
typedef struct
{
    char nombre[50];
    int idUsuario;
    int estado;
}eUsuario;

typedef struct
{
    char nombre[50];
    int idProducto;
    int idUsuario;
    char nombreProducto[50];
    float precio;
    int stock;
    int cantidadVentas;
    int estado;
}eProducto;

typedef struct
{
    int estado;
    int idVenta;
    int idProducto;
    int calificacion;
}eVenta;

#endif // ESTRUCTURAGENERICA_H_INCLUDED

int eUser_init(eUsuario[],int limite);
int eUser_buscarPorId(eUsuario[] ,int limite, int id);
int eUser_siguienteId(eUsuario[] ,int limite);
int eUser_buscarLugarLibre(eUsuario listado[],int limite);

int eUser_alta(eUsuario[] ,int limite);
int eUser_baja(eUsuario[] ,int limite);
int eUser_modificacion(eUsuario[] ,int limite);
void eUser_mostrarUno(eUsuario parametro);
int eUser_mostrarListado(eUsuario[] ,int limite);

int eProducto_altaPublicacion(eUsuario[], eProducto[], int, int);
int eProducto_buscarLugarLibre(eProducto[],int limite);
int eProducto_siguienteId(eProducto[],int limite);
int eProducto_modificarPublicacion(eUsuario[], eProducto[], int, int);
void eProducto_mostrarProductosPorIdUsuario(eProducto[], eUsuario[], int, int, int);
void eProducto_mostrarUno(eProducto parametro);
int eProducto_mostrarListado(eProducto[],int);
int eProducto_init(eProducto[],int);
int eProducto_cancelarPublicacion(eUsuario[], eProducto[], int, int);

int comprarProducto(eProducto[], eVenta[], int, int);
int eVenta_init(eVenta[],int);

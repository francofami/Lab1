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
    int cantidad;
    int estado;
}eProducto;

typedef struct
{
    int idVenta;
    int idProducto;
    int calificacion;
}eVenta;

#endif // ESTRUCTURAGENERICA_H_INCLUDED

int eUser_init(eUsuario[],int limite);
int eGen_buscarPorId(eUsuario[] ,int limite, int id);
int eGen_siguienteId(eUsuario[] ,int limite);
int eGen_buscarLugarLibre(eUsuario listado[],int limite);

int eGen_mostrarUno(eUsuario parametro);
int eGen_mostrarListado(eUsuario[] ,int limite);
int eGen_mostrarListadoConBorrados(eUsuario[] ,int limite);

int eUser_alta(eUsuario[] ,int limite);
int eUser_baja(eUsuario[] ,int limite);
int eUser_modificacion(eUsuario[] ,int limite);

int eGen_ordenar(eUsuario[] ,int limite, int orden);

int eProducto_altaPublicacion(eUsuario[], eProducto[], int, int);
int eProducto_buscarLugarLibre(eProducto[],int limite);
int eProducto_siguienteId(eProducto[],int limite);
int eProducto_modificarPublicacion(eUsuario[], eProducto[], int, int);

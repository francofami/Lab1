#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

struct
{
    char id[50];
    char nombre[51];
    char sueldo[50];
    int edad[50];
    char profesion[50];

}typedef empleados;

empleados* empleados_new(void);
void empleados_delete(empleados* this);
int empleados_setId(empleados* this, char* id);
int empleados_getId(empleados* this);
int empleados_setNombre(empleados* this, char* nombre);
int empleados_getNombre(empleados* this);
int empleados_setSueldo(empleados* this, char* sueldo);
int empleados_getSueldo(empleados* this);
int empleados_setEdad(empleados* this, char* edad);
int empleados_getEdad(empleados* this);
int empleados_setProfesion(empleados* this, char* profesion);
int empleados_getProfesion(empleados* this);
void empleados_print(empleados* this);
empleados* empleados_newParametros(char* id, char* nombre, char* sueldo, char* edad, char* profesion);

#endif // EMPLEADOS_H_INCLUDED

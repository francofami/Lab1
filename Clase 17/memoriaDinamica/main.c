#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nombre[50];
}ePersona;
//Setters: setean, le dan un valor al campo de la estructura en este caso. Se usan solo para una persona. Para usar muchas hago un for.
int ePersona_setId(ePersona* this,int id);
int ePersona_setNombre(ePersona* this, char* nombre[]);

//Getters: obtienen el valor del campo de la estructura en este caso. Se usan solo para una persona. Para usar muchas hago un for.
int ePersona_getID(ePersona*);
char* ePersona_getNombre(ePersona*); //Si no pusiera * al final solo estaria refiriendome a un caracter.

ePersona* newPersona();

//Puedo tener setters y no getters y getters pero no setters.

int main()
{
    ePersona* pPersona;

    pPersona = newPersona();

    //printf("%p\n",pPersona);//Apunta a basura
    //printf("%p\n",&pPersona);//Apunta a la direccion de memoria del puntero (dentro del stack).
    //pPersona = malloc(sizeof(ePersona)); //Recibe un tamaño y devuelve un puntero a void -> se la asigno al puntero
    //Le digo al heap que me reserve el tamaño que le pedi.
    //Malloc puede devolver la direccion de memoria del heap, si no hay mas memoria devuelve NULL
    //printf("%p\n",pPersona);//Apunta a la direccion del heap (montón).

    if(pPersona!=NULL)
    {
        if(ePersona_setId(pPersona, 14)==-1)
        {
            printf("ID Incorrecto");
        }
        else
        {
            if(ePersona_setNombre(pPersona,"Juan")==-1)
            {
                printf("Nombre Incorrecto");
            }
            printf("ID: %d Nombre: %s",ePersona_getID(pPersona),pPersona->nombre);
        }
    }
    return 0;
}


int ePersona_setId(ePersona* this,int id) //Recibe un puntero y el id en este caso. This seria la variable de ePersona
{
    int retorno=-1;

    if(this!=NULL && id>0)
    {
        retorno=1;
        this->id = id;
    }

    return retorno;
}

int ePersona_setNombre(ePersona* this, char* nombre[])
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL && (strlen(nombre)>3)) //Lo de strlen es una condicion que elijo yo de acuerdo a lo que me pida el enunciado
    {
        retorno=1;
        strcpy(this->nombre,nombre);
    }

    return retorno;
}

int ePersona_getID(ePersona* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id;
    }

    return retorno;
}

char* ePersona_getNombre(ePersona* this)
{
    char* retorno=NULL;

    if(this!=NULL)
    {
        retorno = this->nombre; //this->nombre devuelve una direccion de memoria y no un valor.
    }

    return retorno;
}

ePersona* newPersona()
{
    ePersona* pAux;
    pAux=(ePersona*)malloc(sizeof(ePersona));
    return pAux;
}

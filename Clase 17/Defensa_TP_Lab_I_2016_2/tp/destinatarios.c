#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "destinatarios.h"

destinatarios* destinatarios_new(void)
{
    destinatarios* returnAux = (destinatarios*) malloc(sizeof(destinatarios));
    return returnAux;
}

destinatarios* destinatarios_newParametros(char* name, char* mail, int id, int isEmpty)
{
    destinatarios* this;

    this = destinatarios_new();

     if(!destinatarios_setId(this,id) &&
        !destinatarios_setName(this,name) &&
        !destinatarios_setMail(this,mail) &&
        !destinatarios_setIsEmpty(this,isEmpty)
       )
    {
        return this;
    }

    destinatarios_delete(this);
    return NULL;
}


void destinatarios_delete(destinatarios* this)
{
    if(this != NULL)
        free(this);
}


int destinatarios_setIsEmpty(destinatarios* this, int isEmpty)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->isEmpty = isEmpty ;
    }
    return retorno;
}

int destinatarios_getIsEmpty(destinatarios* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->isEmpty;
    }

    return retorno;
}

int destinatarios_setId(destinatarios* this, int id)
{
    int retorno=-1;

    if(this!=NULL && id>0)
    {
        retorno=0;

        this->id = id;
    }

    return retorno;
}

int destinatarios_getId(destinatarios* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id;
    }

    return retorno;
}

int destinatarios_setName(destinatarios* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(this->name,name);
    }
    return retorno;
}

int destinatarios_getName(destinatarios* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->name;
    }

    return retorno;
}

int destinatarios_setMail(destinatarios* this, char* mail)
{
    int retorno = -1;
    if(this != NULL && mail != NULL)
    {
        retorno = 0;
        strcpy(this->mail,mail);
    }
    return retorno;
}

int destinatarios_getMail(destinatarios* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno=this->mail;
    }
    return retorno;
}

int destinatarios_compareMail(void* pdestinatariosA, void* pdestinatariosB)
{
    destinatarios* m1;
    destinatarios* m2;

    m1 = (destinatarios*) pdestinatariosA;
    m2 = (destinatarios*) pdestinatariosB;

    //char* maild1[50];
    //char* maild2[50];

    int retorno = 0;

    /*if(pdestinatariosA!=NULL && pdestinatariosB != NULL)
    {
        strcpy(maild1,destinatarios_getMail(pdestinatariosA));
        strcpy(maild2,destinatarios_getMail(pdestinatariosB));

        retorno = stricmp(maild1,maild2);
    }*/

    retorno= stricmp(m1->mail, m2->mail);

    return retorno ;
}


void destinatarios_print(destinatarios* this)
{
    char name[50];
    char mail[50];
    int isEmpty;

    if(this != NULL)
    {
        strcpy(name,destinatarios_getName(this));
        strcpy(mail,destinatarios_getMail(this));
        isEmpty=destinatarios_getIsEmpty(this);

        printf("\nNombre: %s - Apellido: %s - IsEmpty: %d", name,mail,isEmpty);
    }

}

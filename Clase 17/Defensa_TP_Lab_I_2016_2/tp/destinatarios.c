#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
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

     if(!destinatarios_setId(this,id)
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

int destinatarios_getIsEmpty(destinatarios* this, int* isEmpty)
{
    int retorno = -1;
    if(this != NULL && isEmpty != NULL)
    {
        retorno = 0;
        *isEmpty = this->isEmpty;
    }
    return retorno;
}

int destinatarios_setId(destinatarios* this, int id)
{
    static int ultimoId = -1;
    int retorno = -1;
    if(this != NULL && id == -1)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    else if(this != NULL && id > ultimoId)
    {
        retorno = 0;
        ultimoId = id;
        this->id = ultimoId;
    }
    return retorno;
}

int destinatarios_getId(destinatarios* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
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

int destinatarios_getName(destinatarios* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(name,this->name);
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

int destinatarios_getMail(destinatarios* this, char* mail)
{
    int retorno = -1;
    if(this != NULL && mail != NULL)
    {
        retorno = 0;
        strcpy(mail,this->mail);
    }
    return retorno;
}

int destinatarios_compare(void* pdestinatariosA,void* pdestinatariosB)
{
    char* mailA;
    char* mailB;
    int retorno = 0;
    if(pdestinatariosA!=NULL && pdestinatariosB != NULL)
    {
        destinatarios_getMail(pdestinatariosA,&mailA);
        destinatarios_getMail(pdestinatariosB,&mailB);
        if(strcmp(mailA,mailB)==1)
        {
            retorno = 1;
        }
        else if(strcmp(mailA,mailB)==-1)
        {
            retorno = -1;
        }

    }
    return retorno;

}


void destinatarios_print(destinatarios* this)
{
    char name[51];
    char mail[51];
    int isEmpty;

    if(this != NULL)
    {
        destinatarios_getName(this,name);
        destinatarios_getMail(this,mail);
        destinatarios_getIsEmpty(this,&isEmpty);
        fprintf(stdout,"\nNombre: %s - Apellido: %s - IsEmpty: %d", name,mail,isEmpty);
    }

}

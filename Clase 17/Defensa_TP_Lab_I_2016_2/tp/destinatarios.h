#ifndef DESTINATARIOS_H_INCLUDED
#define DESTINATARIOS_H_INCLUDED

struct
{
    int id;
    char name[51];
    char mail[51];
    int isEmpty;

}typedef destinatarios;


destinatarios* destinatarios_new(void);
void destinatarios_delete(destinatarios* this);
int destinatarios_getIsEmpty(destinatarios* this);
int destinatarios_setIsEmpty(destinatarios* this, int isEmpty);
int destinatarios_setId(destinatarios* this, int id);
int destinatarios_getId(destinatarios* this);
int destinatarios_setName(destinatarios* this, char* name);
int destinatarios_getName(destinatarios* this);
int destinatarios_setMail(destinatarios* this, char* mail);
int destinatarios_getMail(destinatarios* this);
int destinatarios_compareMail(void* pdestinatariosA,void* pdestinatariosB);
void destinatarios_print(destinatarios* this);
destinatarios* destinatarios_newParametros(char* name, char* mail, int id, int isEmpty);

#endif // DESTINATARIOS_H_INCLUDED

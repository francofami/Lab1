#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"
#include "destinatarios.h"

int parserEmployee(FILE* pFile, ArrayList* this);
int parserBlackList(FILE* pFile, ArrayList* this, ArrayList* pList);


#endif // PARSER_H_INCLUDED

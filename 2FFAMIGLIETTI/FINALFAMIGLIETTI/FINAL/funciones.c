#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "letras.h"
#include "ArrayList.h"

int parserLetras(ArrayList* this)
{
    int retorno = -1;

    FILE* pFile;
    char letra;
	char nombre[22];
	int vocal;
	int consonante;
	int numero;
	char dire[50];

    eLetra* aux;

    printf("Ingrese nombre de archivo a abrir: ");
    fflush(stdin);
    gets(dire);

    if(strcmp(dire, "caracter.csv")==0)
    {
    pFile = fopen(dire, "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            aux = (eLetra*) malloc(sizeof(eLetra));

            fscanf(pFile,"%c,%[^,],%d,%d,%d\n",&letra,nombre,&vocal, &consonante, &numero);

            eLetra_setletra(aux, letra);
            eLetra_setnombre(aux,nombre);
            eLetra_setvocal(aux,vocal);
            eLetra_setconsonante(aux,consonante);
            eLetra_setnumero(aux, numero);

            this->add(this,aux);
        }while(!feof(pFile));

    }

    eLetra_printAll(this);

    fclose(pFile);

    }
    else
    {
        printf("Archivo no encontrado");
    }



    return retorno;
}

void completar(ArrayList* this)
{
    FILE* pFile;
    char letra;
	char nombre[22];
	int vocal;
	int consonante;
	int numero;

    eLetra* aux;

    pFile = fopen("caracter.csv", "r");

    if(pFile != NULL)
    {
        this->clear(this);

        while(!feof(pFile))
        {
            aux = eLetra_new();

            fscanf(pFile,"%c,%[^,],%d,%d,%d\n",&letra,nombre,&vocal,&consonante, &numero);

            eLetra_setletra(aux, letra);
            eLetra_setnombre(aux, nombre);
            eLetra_setnumero(aux, numero);

            eLetra_setvocal(aux,esV(aux->letra));
            eLetra_setconsonante(aux,esC(aux->letra));
            eLetra_setnumero(aux,esNum(aux->letra));

            this->add(this,aux);
        }
    }

    fclose(pFile);
}

ArrayList* listarA(ArrayList* this)
{
    ArrayList* listaNueva;
    listaNueva = al_newArrayList();

    ArrayList* listaCompleta;
    listaCompleta = al_newArrayList();

    ArrayList* listaRepetidos;
    listaRepetidos = al_newArrayList();

    ArrayList* listaFinal;
    listaFinal = al_newArrayList();

    int largoLista, i, j, ultimoValor=-1;

    eLetra* aux;
    eLetra* aux2;
    eLetra* auxCompleta;
    eLetra* auxRepetidos;

    largoLista=this->len(this);

    for(i=0;i<largoLista;i++)
    {
        aux = eLetra_new();

        aux = this->get(this, i);

        listaCompleta->add(listaCompleta, aux);
    }

    listaCompleta->sort(listaCompleta,compararAlfabeticamente,0);

    for(i=0;i<largoLista;i++)
    {
        aux = eLetra_new();
        aux = this->get(this,i);

        if(ultimoValor>0)
        {
            aux2 = eLetra_new();
            aux2 = this->get(this,ultimoValor);
        }

            if(i==0 || (aux2->letra != aux->letra) )
            {
                for(j=i+1;j<largoLista;j++)
                {
                    aux2 = eLetra_new();
                    aux2 = this->get(this,j);

                    if(aux->letra == aux2->letra)
                    {
                        listaRepetidos->add(listaRepetidos, aux2);
                        ultimoValor=j;
                    }
                }
            }
        }

    for(i=0;i<largoLista;i++)
    {
        auxCompleta = (eLetra*) listaCompleta->get(listaCompleta, i);
        auxRepetidos = (eLetra*) listaRepetidos->get(listaRepetidos, i);

        if((listaRepetidos->contains(listaRepetidos, auxCompleta))==0)
        {
            listaFinal->add(listaFinal, auxCompleta);
        }
    }

    eLetra_printAll(listaFinal);

    return listaFinal;
}

ArrayList* listarB(ArrayList* this)
{
    ArrayList* listaNueva;
    listaNueva = al_newArrayList();

    char caracter;
    char buffer[22];
    char charAux;

    int  largoLista, i, j, largoCadena;
    eLetra* aux;

    printf("Ingrese caracter: ");
    fflush(stdin);
    caracter=getch();
    printf(" %c\n", caracter);

    largoLista=this->len(this);

    for(i=0;i<largoLista;i++)
    {
        aux = eLetra_new();

        aux = this->get(this, i);

        strcpy(buffer, aux->nombre);

        largoCadena = strlen(buffer);

        for(j=0;j<largoCadena;j++)
        {
            //fflush(stdin);
            //charAux=buffer[j];

            if(buffer[j]==caracter)
            {
                listaNueva->add(listaNueva, aux);
                break;
            }
        }
    }

    listaNueva->sort(listaNueva,compararAlfabeticamente,0);

    int aa;

    aa= listaNueva->len(listaNueva);

    if(aa>0)
    {
        eLetra_printAll(listaNueva);
    }
    else
    {
        printf("\nNo hubo coincidencias.\n");
    }

    return listaNueva;
}

void generarCompleto(ArrayList* this)
{
    FILE* fp;

    fp = fopen("completo.csv", "w");

    if(fp!=NULL)
    {
        char letra;
        char nombre[22];
        int vocal;
        int consonante;
        int numero;
        eLetra* aux;

       int largoLista, i;

       largoLista = this->len(this);

       for(i=0;i<largoLista;i++)
       {
           aux = eLetra_new();
           aux = this->get(this, i);

           letra = aux->letra;
           strcpy(nombre, aux->nombre);
           vocal = aux->vocal;
           consonante = aux->consonante;
           numero = aux->numero;

           fprintf(fp, "%c, %s, %d, %d, %d\n", letra,nombre,vocal,consonante, numero);
       }

       printf("\nArchivo completo.csv generado con exito!\n");
    }

    fclose(fp);
}

void generarRepetidos(ArrayList* this)
{
    FILE* fp;

    fp = fopen("repetido.csv", "w");

    if(fp!=NULL)
    {
        char letra;
        char nombre[22];
        int vocal;
        int consonante;
        int numero;
        eLetra* aux;

       int largoLista, i;

       largoLista = this->len(this);

       for(i=0;i<largoLista;i++)
       {
           aux = eLetra_new();
           aux = this->get(this, i);

           letra = aux->letra;
           strcpy(nombre, aux->nombre);
           vocal = aux->vocal;
           consonante = aux->consonante;
           numero = aux->numero;

           fprintf(fp, "%c, %s, %d, %d, %d\n", letra,nombre,vocal,consonante, numero);
       }

       printf("\nArchivo repetido.csv generado con exito!\n");
    }

    fclose(fp);
}

void generarDepurado(ArrayList* this)
{
    FILE* fp;

    fp = fopen("depurado.csv", "w");

    if(fp!=NULL)
    {
        char letra;
        char nombre[22];
        int vocal;
        int consonante;
        int numero;
        eLetra* aux;

       int largoLista, i;

       largoLista = this->len(this);

       for(i=0;i<largoLista;i++)
       {
           aux = eLetra_new();
           aux = this->get(this, i);

           letra = aux->letra;
           strcpy(nombre, aux->nombre);
           vocal = aux->vocal;
           consonante = aux->consonante;
           numero = aux->numero;

           fprintf(fp, "%c, %s, %d, %d, %d\n", letra,nombre,vocal,consonante, numero);
       }

       printf("\nArchivo depurado.csv generado con exito!\n");
    }

    fclose(fp);
}

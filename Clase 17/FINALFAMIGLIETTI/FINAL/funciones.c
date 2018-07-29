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

    eLetra* aux;

    pFile = fopen("datos.csv", "r");

    if(pFile != NULL)
    {
        retorno = 0;

        do
        {
            aux = (eLetra*) malloc(sizeof(eLetra));

            fscanf(pFile,"%c,%[^,],%d,%d\n",&letra,nombre,&vocal,&consonante);
            eLetra_setletra(aux, letra);
            eLetra_setnombre(aux,nombre);
            eLetra_setvocal(aux,vocal);
            eLetra_setconsonante(aux,consonante);

            this->add(this,aux);
        }while(!feof(pFile));

    }

    fclose(pFile);

    return retorno;
}

void completar(ArrayList* this)
{
    FILE* pFile;
    char letra;
	char nombre[22];
	int vocal;
	int consonante;

    eLetra* aux;

    pFile = fopen("datos.csv", "r");

    if(pFile != NULL)
    {

        this->clear(this);

        while(!feof(pFile))
        {
            aux = eLetra_new();

            fscanf(pFile,"%c,%[^,],%d,%d\n",&letra,nombre,&vocal,&consonante);


            eLetra_setletra(aux, letra);
            eLetra_setnombre(aux, nombre);

            eLetra_setvocal(aux,esV(aux->letra));
            eLetra_setconsonante(aux,esC(aux->letra));

            this->add(this,aux);
        }
    }

    fclose(pFile);
}

ArrayList* listarA(ArrayList* this)
{
    ArrayList* listaNueva;
    listaNueva = al_newArrayList();
    char cadena[10];
    int largoCadena, largoLista, i, j;
    eLetra* aux;

    printf("Ingrese cadena de caracteres: ");
    fflush(stdin);
    gets(cadena);

    largoCadena=strlen(cadena);
    largoLista=this->len(this);

    for(i=0;i<largoCadena;i++)
    {
        printf("\nLetra: %c\n", cadena[i]);

        for(j=0;j<largoLista;j++)
        {
            aux = eLetra_new();

            aux = this->get(this, j);

            if(cadena[i]==aux->letra)
            {
                listaNueva->add(listaNueva, aux);
            }
        }
    }

    listaNueva->sort(listaNueva,compararAlfabeticamente,1);

    eLetra_printAll(listaNueva);

    return listaNueva;
}

ArrayList* listarB(ArrayList* this)
{
    ArrayList* listaNueva;
    listaNueva = al_newArrayList();
    char cadena[10];
    int largoCadena, largoLista, i, j;
    eLetra* aux;

    printf("Ingrese cadena de caracteres: ");
    fflush(stdin);
    gets(cadena);

    largoCadena=strlen(cadena);
    largoLista=this->len(this);

    listaNueva=this->clone(this);

    for(i=0;i<largoCadena;i++)
    {
        for(j=0;j<largoLista;j++)
        {
            aux = eLetra_new();

            aux = this->get(this, j);

            if(cadena[i]==aux->letra)
            {
                listaNueva->remove(listaNueva,j);
            }
        }
    }

    listaNueva->sort(listaNueva,compararAlfabeticamente,0);

    eLetra_printAll(listaNueva);

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

           fprintf(fp, "%c, %s, %d, %d\n", letra,nombre,vocal,consonante);
       }
    }

    fclose(fp);
}

ArrayList* generarRepetidos(ArrayList* this)
{
    FILE* fp;
    FILE* fp2;
    ArrayList* listaNueva;
    listaNueva = al_newArrayList();
    eLetra* aux;
    eLetra* aux2;

    fp = fopen("completo.csv", "r");

    if(fp!=NULL)
    {
        int i, j, largoLista, ultimoValor=-1;

        largoLista = this->len(this);

        this->sort(this,compararAlfabeticamente,1);

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
                        listaNueva->add(listaNueva, aux2);
                        ultimoValor=j;
                    }
                }
            }
        }

        fclose(fp);

    fp2 = fopen("repetidos.csv", "w");

    if(fp2!=NULL)
    {
        char letra;
        char nombre[22];
        int vocal;
        int consonante;
        eLetra* aux;

       int largoListaNueva, i;

       largoListaNueva = listaNueva->len(listaNueva);

       for(i=0;i<largoListaNueva;i++)
       {
           aux = eLetra_new();
           aux = listaNueva->get(listaNueva, i);

           letra = aux->letra;
           strcpy(nombre, aux->nombre);
           vocal = aux->vocal;
           consonante = aux->consonante;

           fprintf(fp, "%c, %s, %d, %d\n", letra,nombre,vocal,consonante);
       }
    }

    fclose(fp2);

    }

    return listaNueva;
}

void generarDepurado(ArrayList* listaCompleta, ArrayList* listaRepetidos)
{
    FILE* fp;
    ArrayList* listaFinal;
    listaFinal=al_newArrayList();

    int largoCompleta, largoRepetidos, i;

    largoCompleta=listaCompleta->len(listaCompleta);

    eLetra* auxCompleta;
    eLetra* auxRepetidos;

    for(i=0;i<largoCompleta;i++)
    {
        auxCompleta = (eLetra*) listaCompleta->get(listaCompleta, i);
        auxRepetidos = (eLetra*) listaRepetidos->get(listaRepetidos, i);

        if((listaRepetidos->contains(listaRepetidos, auxCompleta))==0)
        {
            listaFinal->add(listaFinal, auxCompleta);
        }
    }

    fp = fopen("depurados.csv", "w");

    if(fp!=NULL)
    {
        int largoFinal;
        eLetra* aux;

        char letra;
        char nombre[22];
        int vocal;
        int consonante;

        largoFinal = listaFinal->len(listaFinal);

        for(i=0;i<largoFinal;i++)
        {
            aux = eLetra_new();
            aux = listaFinal->get(listaFinal, i);

            letra=aux->letra;
            strcpy(nombre,aux->nombre);
            vocal=aux->vocal;
            consonante=aux->consonante;

            fprintf(fp, "%c, %s, %d, %d\n", letra,nombre,vocal,consonante);
        }
    }

    fclose(fp);
}

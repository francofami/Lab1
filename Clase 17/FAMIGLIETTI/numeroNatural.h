#ifndef NUMERONATURAL_H_INCLUDED
#define NUMERONATURAL_H_INCLUDED


typedef struct{
    int numero;
    char nombre[51];
    int par;
    int impar;
    int primo;
    int id;
}numeroNatural;

numeroNatural* numeroNatural_new(void);

void numeroNatural_delete(numeroNatural* this);

numeroNatural* numeroNatural_newParametros(int id, int numero, char* nombre, int par, int impar, int primo);

void numeroNatural_print(numeroNatural* this);

void numeroNatural_printAll(ArrayList* this);

int numeroNatural_setNumero(numeroNatural* this, int numero);

int numeroNatural_getNumero(numeroNatural* this);

int numeroNatural_setPar(numeroNatural* this, int par);

int numeroNatural_getPar(numeroNatural* this);

int numeroNatural_setImpar(numeroNatural* this, int impar);

int numeroNatural_getImpar(numeroNatural* this);

int numeroNatural_setPrimo(numeroNatural* this, int primo);

int numeroNatural_getPrimo(numeroNatural* this);

int numeroNatural_setNombre(numeroNatural* this, char* nombre);

int numeroNatural_getNombre(numeroNatural* this);

int esImpar(numeroNatural* this);

int esPar(numeroNatural* this);

int esPrimo(numeroNatural* this);

int numeroNatural_getId(numeroNatural* this);

int numeroNatural_setId(numeroNatural* this, int id);


#endif // NUMERONATURAL_H_INCLUDED

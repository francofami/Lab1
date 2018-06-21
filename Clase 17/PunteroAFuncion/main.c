#include <stdio.h>
#include <stdlib.h>

void funcionBienvenida(char* nombre);
void funcionDespedida(char* nombre);
void funcionDelegaLaFuncionalidad(void(*punteroFuncion) (char* eldato), char* nombre);

int main()
{
    funcionDelegaLaFuncionalidad(funcionBienvenida,"Natalia Natalia");
    getche();
    funcionDelegaLaFuncionalidad(funcionDespedida,"Natalia Natalia");
    getche();
    funcionDelegaLaFuncionalidad(asd,"Natalia Natalia");


    return 0;
}

void funcionBienvenida(char* nombre)
{
    printf("Bienvenida %s, a la empresa.",nombre);
}

void funcionDespedida(char* nombre)
{
    printf("Vos %s estas despedida ------->.",nombre);
}

void funcionDelegaLaFuncionalidad(void(*punteroFuncion) (char* eldato), char* nombre)
{
    punteroFuncion(nombre);
}

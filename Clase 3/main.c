#include <stdio.h>
#include <stdlib.h>

/* Reglas Funciones
1. Firmar la funcion (firma o prototipo): Tipo de dato Nombre de funcion (tipo de dato);
2. En el main invoco la funcion: Nombre de funcion();
3. Definir la funcionalidad (Desarrollar o implementar la funcion):
Tipo de dato Nombre de funcion (tipo de dato)
{
    codigo de la funcion;
} */

void saludar(void);
int sumar(int numeroUno, int numeroDos);
float dividirEnteros(int numeroUno, int numeroDos);
int ingresarNumero();
int getEntero(char* mensaje, char* mensajeError, int maximo, int minimo);

int main()
{
    int resultadoSuma;
    float resultadoDivision;
    int sepudo, edad;
    saludar();
    resultadoSuma=sumar(3,3);
    resultadoDivision=dividirEnteros(10,3);
    sepudo=ingresarNumero();
    printf("%d\n",resultadoSuma);
    printf("%f\n",resultadoDivision);
    if(sepudo==0)
    {
        printf("ok\n");
    }
    else
    {
        printf("mal\n");
    }

    edad=getEntero("Ingrese su edad: ","Error, ingrese edad entre 1 y 199", 199, 1);
    printf("La edad ingresada es: %d", edad);

    return 0;
}

void saludar(void)
{
    printf("Hola mundo\n");
}

int sumar(int numeroUno, int numeroDos)
{
    int asd=0;

    asd=numeroUno+numeroDos;

    return asd;
}

float dividirEnteros(int numeroUno, int numeroDos)
{
    float divi=0;

    divi=(float)numeroUno/numeroDos; //casteo un solo numero para que me tire el resultado en float

    return divi;
}

 int ingresarNumero()
{
    int par=-1, numero;

    printf("Ingrese un numero par: ");
    scanf("%d",&numero);

    if(numero%2==0)
    {
        par=0;
    }

    return par;
}

int getEntero(char* mensaje, char* mensajeError, int maximo, int minimo)
{
    int retorno=-1;

    do{
        printf("%s", mensaje);
        scanf("%d", &retorno);

        if(retorno<maximo && retorno>minimo)
        {
            break;
        }
        printf("%s", mensajeError);
    }while(1==1);

    return retorno;
}

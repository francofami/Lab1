#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#include "productos.h"
#include "validaciones.h"

void nuevoProducto()
{
    FILE* fp;
    FILE* fp2;
    fp = fopen("datos.dat", "ab");
    fp2 = fopen("temporal.dat", "ab");

    int codigo;
    char descripcion[51];
    float importe;
    int cantidad;
    int activo;


    if(fp!=NULL)
    {
        productos* aux;
        aux=productos_new();

        getValidInt("Ingrese codigo: ","Error, el codigo debe ser entre 1 y 1000. ", &codigo,1, 1000,3);

        getValidString("Ingrese descripcion: ","Error, ingrese solo letras. ", "Error, la descripcion no debe superar los 50 caracteres. ",descripcion, 50,3);

        getValidFloat("Ingrese importe: ","Error, el importe debe ser mayor a 0. ", &importe,0.01, 100000000,3);

        getValidInt("Ingrese cantidad: ","Error, la cantidad debe ser mayor a 0. ", &cantidad,1, 100000000,3);

        activo=1;

        productos_setCodigo(aux,codigo);
        productos_setDescripcion(aux,descripcion);
        productos_setImporte(aux,importe);
        productos_setCantidad(aux,cantidad);
        productos_setActivo(aux, activo);

        fwrite(aux,sizeof(productos),1,fp);
        fwrite(aux,sizeof(productos),1,fp2);

        printf("Producto agregado!\n");

        fclose(fp);
        fclose(fp2);
    }
}

ArrayList* leerDatos()
{
    FILE* fp;
    ArrayList* lista=NULL;
    productos* aux;

    fp = fopen("datos.dat","rb");

    if(fp!=NULL)
    {
        lista=al_newArrayList();

        while(!feof(fp))
        {
            aux=productos_new();

            fread(aux,sizeof(productos),1,fp);

            if(feof(fp))
            break;

            lista->add(lista, aux);
        }

        fclose(fp);

        ordenarLista(lista);

        //guardarListaEnArchivoTemporal(lista);

        guardarListaEnArchivo(lista);

    }
    else
        fclose(fp);

    return lista;
}

ArrayList* leerTemporal()
{
    FILE* fp;
    ArrayList* lista=NULL;
    productos* aux;

    fp = fopen("temporal.dat","rb");

    if(fp!=NULL)
    {
        lista=al_newArrayList();

        while(!feof(fp))
        {
            aux=productos_new();

            fread(aux,sizeof(productos),1,fp);

            if(feof(fp))
            break;

            lista->add(lista, aux);
        }

        fclose(fp);
    }
    else
        fclose(fp);

    ordenarLista(lista);

    guardarListaEnArchivoTemporal(lista);

    return lista;
}


void ordenarLista(ArrayList* this)
{
    this->sort(this,compararPorDescripcion,1);
}

void guardarListaEnArchivo(ArrayList* this)
{
    FILE* fp;
    int length, i;
    productos* aux;

    fp = fopen("datos.dat", "wb");

    if(fp!=NULL)
    {
        length = this->len(this);

        if(fp!=NULL)
        {
            for(i=0;i<length;i++)
            {
                aux = productos_new();

                aux = (productos*) this->get(this,i);

                fwrite(aux,sizeof(productos),1,fp);
            }
        }
    }

    fclose(fp);

    fp = fopen("datos.dat", "rb");

    if(fp!=NULL)
    {
        printf("\nCodigo\tImporte\tCantidad\tDescripcion\n");

        while(!feof(fp))
        {
            aux=productos_new();

            fread(aux,sizeof(productos),1,fp);

            if(feof(fp))
            break;

            productos_print(aux);
        }

    }

    fclose(fp);

}

void guardarListaEnArchivoTemporal(ArrayList* this)
{
    FILE* fp;
    fp = fopen("temporal.dat", "wb");
    int i, length;
    productos* aux;

    length=this->len(this);

    if(fp!=NULL)
    {
        for(i=0;i<length;i++)
        {
            aux = productos_new();

            aux = (productos*) this->get(this,i);

            fwrite(aux,sizeof(productos),1,fp);
        }
    }

    fclose(fp);

    fp = fopen("temporal.dat", "rb");

    if(fp!=NULL)
    {
        printf("\nCodigo\tImporte\tCantidad\tDescripcion\n");

        while(!feof(fp))
        {
            aux=productos_new();

            fread(aux,sizeof(productos),1,fp);

            if(feof(fp))
            break;

            productos_print(aux);
        }

    }

    fclose(fp);
}

void modificacion()
{
    ArrayList* lista;
    int codigo, i, length, flag=0;
    productos* aux;
    char descripcion[51];
    float importe;
    int cantidad;

    lista=al_newArrayList();

    lista = leerDatos();

    printf("\nIngrese codigo del producto que desee modificar: ");
    fflush(stdin);
    scanf("%d",&codigo);

    length=lista->len(lista);

    for(i=0;i<length;i++)
    {
        aux = productos_new();
        aux = lista->get(lista,i);

        if(codigo==aux->codigo)
        {
            printf("1- Modificar descripcion\n2- Modificar importe\n3- Modificar cantidad\n");
            fflush(stdin);
            scanf("%d",&codigo);

            switch(codigo)
            {
                case 1:
                    {
                        getValidString("Ingrese descripcion: ","Error, ingrese solo letras. ", "Error, la descripcion no debe superar los 50 caracteres. ",descripcion, 50,3);

                        productos_setDescripcion(aux,descripcion);

                        lista->set(lista, i, aux);
                        guardarListaEnArchivo(lista);
                    }
                break;

                case 2:
                    {
                        getValidFloat("Ingrese importe: ","Error, el importe debe ser mayor a 0. ", &importe,0.01, 100000000,3);

                        productos_setImporte(aux,importe);

                        lista->set(lista, i, aux);
                        guardarListaEnArchivo(lista);
                    }
                break;

                case 3:
                    {
                        getValidInt("Ingrese cantidad: ","Error, la cantidad debe ser mayor a 0. ", &cantidad,1, 100000000,3);

                        productos_setCantidad(aux,cantidad);

                        lista->set(lista, i, aux);
                        guardarListaEnArchivo(lista);
                    }
                break;

                default:
                    printf("Opcion incorrecta.");
            }



            flag=1;
            break;
        }

    }

    if(!flag)
    {
        printf("El codigo ingresado no coincide con ningun producto.\n");
    }
}

void bajaLogica()
{
    ArrayList* lista;
    int codigo, i, length, flag=0;
    productos* aux;

    lista=al_newArrayList();

    lista = leerDatos();

    printf("\nIngrese codigo del producto que desea hacer la baja logica: ");
    fflush(stdin);
    scanf("%d",&codigo);

    length=lista->len(lista);

    for(i=0;i<length;i++)
    {
        aux = productos_new();
        aux = lista->get(lista,i);

        if(codigo==aux->codigo)
        {
            productos_setActivo(aux,0);

            lista->set(lista, i, aux);

            guardarListaEnArchivo(lista);

            flag=1;

            break;
        }
    }
    if(!flag)
    {
        printf("El codigo ingresado no coincide con ningun producto.\n");
    }
}

void bajaFisica()
{
    ArrayList* lista;
    int codigo, i, length, flag=0;
    productos* aux;

    lista = al_newArrayList();

    lista = leerTemporal();

    printf("\nIngrese codigo del producto que desea hacer la baja fisica: ");
    fflush(stdin);
    scanf("%d",&codigo);

    length=lista->len(lista);

    for(i=0;i<length;i++)
    {
        aux = productos_new();
        aux = lista->get(lista,i);

        if(codigo==aux->codigo)
        {
            lista->pop(lista,i); //Arreglar el al_remove del arraylist y usarlo en vez del pop!

            guardarListaEnArchivo(lista);
            guardarListaEnArchivoTemporal(lista);

            flag=1;

            break;
        }
    }

    if(!flag)
    {
        printf("El codigo ingresado no coincide con ningun producto.\n");
    }
}

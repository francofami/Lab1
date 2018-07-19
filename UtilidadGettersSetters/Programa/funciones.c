#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void imprimirIncludesEnPuntoC(char nombreArchivoC[50], char nombreArchivo[50])
{
    FILE* pFile;

    pFile=fopen(nombreArchivoC,"r");

    if(pFile==NULL)
    {
        pFile=fopen(nombreArchivoC,"w");

        fprintf(pFile, "%s", "#include <stdio.h>\n");
        fprintf(pFile, "%s", "#include <stdlib.h>\n");
        fprintf(pFile, "%s", "#include <string.h>\n");
        fprintf(pFile, "%s", "#include \"");
        fprintf(pFile, "%s", nombreArchivo);
        fprintf(pFile, "%s", ".h\"\n");
        fprintf(pFile, "%s", "#include \"ArrayList.h\"");

        fclose(pFile);
    }
    else
        fclose(pFile);
}

void imprimirH(char nombreArchivoH[50], char nombreArchivo[50])
{
    FILE* pFile;

    pFile=fopen(nombreArchivoH,"r");

    if(pFile==NULL)
    {
        pFile=fopen(nombreArchivoH,"w");

        fprintf(pFile, "%s", "#ifndef ");
        strupr(nombreArchivo);
        fprintf(pFile, "%s", nombreArchivo);
        fprintf(pFile, "%s", "_H_INCLUDED\n#define ");
        fprintf(pFile, "%s", nombreArchivo);
        fprintf(pFile, "%s", "_H_INCLUDED\n\n");
        fprintf(pFile, "%s", "struct\n{\n");

        fclose(pFile);
    }
    else
        fclose(pFile);
}

void gettersSetters(char nombreArchivo[50], char nombreEstructura[50], char nombreArchivoH[50])
{
    FILE* pFile;
    FILE* h;
    FILE* fp;

    char nombreVariable[50];
    int opcion;


    pFile = fopen(nombreArchivo, "a");
    h = fopen(nombreArchivoH, "a");
    fp = fopen("temporal.h", "a");

    if(pFile!=NULL && h!=NULL && fp!=NULL)
    {
        printf("Ingrese nombre de variable: ");
        //fflush(stdin);
        //gets(nombreVariable);
        scanf("%s", nombreVariable);

        printf("Ingrese tipo de dato de variable");

        printf("\n1- Int\n");
        printf("2- Float\n");
        printf("3- String\n");

        fflush(stdin);
        scanf("%d",&opcion);

        system("cls");

            switch(opcion)
            {
                case 1:
                    {

                        //Imprime setters
                        fprintf(pFile, "%s", "\n\nint ");
                        fprintf(pFile, "%s_set", nombreEstructura);
                        fprintf(pFile, "%s(", nombreVariable);
                        fprintf(pFile, "%s* this, int ", nombreEstructura);
                        fprintf(pFile, "%s)\n{\n\tint retorno=-1;\n\n\tif(this!=NULL)\n\t{\n\t\tretorno=0;\n\t\tthis->%s=%s;\n\t}\n\n\treturn retorno;\n}", nombreVariable,nombreVariable,nombreVariable);

                        //Imprime getters
                        fprintf(pFile, "%s", "\n\nint ");
                        fprintf(pFile, "%s_get", nombreEstructura);
                        fprintf(pFile, "%s(", nombreVariable);
                        fprintf(pFile, "%s* this", nombreEstructura);
                        fprintf(pFile, ")\n{\n\tint retorno=-1;\n\n\tif(this!=NULL)\n\t{\n\t\tretorno=this->%s;\n\t}\n\n\treturn retorno;\n}",nombreVariable);

                        //Agrega a la estructura del .h
                        fprintf(h, "\tint %s;\n", nombreVariable);

                        //Agrega firma de la funcion a un archivo temporal (con doxygen incluido)
                        fprintf(fp, "%s", "\n\n/** \\brief Setter.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, " * \\param this %s* El puntero a la estructura donde se va a asingnar la variable %s.\n", nombreEstructura, nombreVariable);
                        fprintf(fp, " * \\param %s int La variable %s que se va a asingar.\n", nombreVariable, nombreVariable);
                        fprintf(fp, "%s", " * \\return int Devuelve -1 si hay error, sino devuelve 0.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " */\n");
                        fprintf(fp, "int %s_set%s(%s* this, int %s);\n", nombreEstructura, nombreVariable, nombreEstructura, nombreVariable);

                        fprintf(fp, "%s", "\n\n/** \\brief Getter.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, " * \\param this %s* El puntero a estructura donde se obtiene la variable %s.\n", nombreEstructura, nombreVariable);
                        fprintf(fp, "%s", " * \\return int Devuelve -1 si hay error, sino devuelve 0.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " */\n");
                        fprintf(fp, "int %s_get%s(%s* this);\n", nombreEstructura, nombreVariable, nombreEstructura);


                        printf("\nGetter y Setter generado con exito!\n");
                    }
                    break;
                case 2:
                    {
                        fprintf(pFile, "%s", "\n\nint ");
                        fprintf(pFile, "%s_set", nombreEstructura);
                        fprintf(pFile, "%s(", nombreVariable);
                        fprintf(pFile, "%s* this, float ", nombreEstructura);
                        fprintf(pFile, "%s)\n{\n\tint retorno=-1;\n\n\tif(this!=NULL)\n\t{\n\t\tretorno=0;\n\t\tthis->%s=%s;\n\t}\n\treturn retorno;\n}", nombreVariable,nombreVariable,nombreVariable);

                        fprintf(pFile, "%s", "\n\nint ");
                        fprintf(pFile, "%s_get", nombreEstructura);
                        fprintf(pFile, "%s(", nombreVariable);
                        fprintf(pFile, "%s* this", nombreEstructura);
                        fprintf(pFile, ")\n{\n\tint retorno=-1;\n\n\tif(this!=NULL)\n\t{\n\t\tretorno=this->%s;\n\t}\n\n\treturn retorno;\n}",nombreVariable);

                        fprintf(h, "\tfloat %s;\n", nombreVariable);

                        fprintf(fp, "%s", "\n\n/** \\brief Setter.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, " * \\param this %s* El puntero a la estructura donde se va a asingnar la variable %s.\n", nombreEstructura, nombreVariable);
                        fprintf(fp, " * \\param %s float La variable %s que se va a asingar.\n", nombreVariable, nombreVariable);
                        fprintf(fp, "%s", " * \\return int Devuelve -1 si hay error, sino devuelve 0.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " */\n");
                        fprintf(fp, "int %s_set%s(%s* this, float %s);\n", nombreEstructura, nombreVariable, nombreEstructura, nombreVariable);

                        fprintf(fp, "%s", "\n\n/** \\brief Getter.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, " * \\param this %s* El puntero a estructura donde se obtiene la variable %s.\n", nombreEstructura, nombreVariable);
                        fprintf(fp, "%s", " * \\return int Devuelve -1 si hay error, sino devuelve 0.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " */\n");
                        fprintf(fp, "int %s_get%s(%s* this);\n", nombreEstructura, nombreVariable, nombreEstructura);

                        printf("\nGetter y Setter generado con exito!\n");
                    }
                    break;
                case 3:
                    {
                        fprintf(pFile, "%s", "\n\nint ");
                        fprintf(pFile, "%s_set", nombreEstructura);
                        fprintf(pFile, "%s(", nombreVariable);
                        fprintf(pFile, "%s* this, char* ", nombreEstructura);
                        fprintf(pFile, "%s)\n{\n\tint retorno=-1;\n\n\tif(this!=NULL && %s!=NULL)\n\t{\n\t\tretorno=0;\n\t\tstrcpy(this->%s,%s);\n\t}\n\treturn retorno;\n}", nombreVariable,nombreVariable,nombreVariable,nombreVariable);

                        fprintf(pFile, "%s", "\n\nint ");
                        fprintf(pFile, "%s_get", nombreEstructura);
                        fprintf(pFile, "%s(", nombreVariable);
                        fprintf(pFile, "%s* this", nombreEstructura);
                        fprintf(pFile, ")\n{\n\tint retorno=-1;\n\n\tif(this!=NULL)\n\t{\n\t\tretorno=this->%s;\n\t}\n\n\treturn retorno;\n}",nombreVariable);

                        printf("Ingrese cantidad de caracteres que tiene el string: ");
                        fflush(stdin);
                        scanf("%d", &opcion);

                        fprintf(h, "\tchar %s[%d];\n", nombreVariable, opcion);

                        fprintf(fp, "%s", "\n\n/** \\brief Setter.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, " * \\param this %s* El puntero a la estructura donde se va a asingnar la variable %s.\n", nombreEstructura, nombreVariable);
                        fprintf(fp, " * \\param %s char* La variable %s que se va a asingar.\n", nombreVariable, nombreVariable);
                        fprintf(fp, "%s", " * \\return int Devuelve -1 si hay error, sino devuelve 0.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " */\n");
                        fprintf(fp, "int %s_set%s(%s* this, char* %s);\n", nombreEstructura, nombreVariable, nombreEstructura, nombreVariable);

                        fprintf(fp, "%s", "\n\n/** \\brief Getter.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, " * \\param this %s* El puntero a estructura donde se obtiene la variable %s.\n", nombreEstructura, nombreVariable);
                        fprintf(fp, "%s", " * \\return int Devuelve -1 si hay error, sino devuelve 0.\n");
                        fprintf(fp, "%s", " *\n");
                        fprintf(fp, "%s", " */\n");
                        fprintf(fp, "int %s_get%s(%s* this);\n", nombreEstructura, nombreVariable, nombreEstructura);

                        printf("\nGetter y Setter generado con exito!\n");
                    }
                    break;
                default:
                    break;
            }
        }

        fclose(pFile);
}

void constructor(char nombreArchivoC[50], char nombreEstructura[50])
{
    FILE* pFile;
    FILE* fp;
    char bufferIn[100];

    pFile = fopen(nombreArchivoC, "a");
    fp = fopen("temporal.h", "a");

    if(pFile!=NULL && fp!=NULL)
    {
        fprintf(pFile, "\n\n%s* %s_new(void)\n{\n\t%s* returnAux = (%s*) malloc(sizeof(%s));", nombreEstructura, nombreEstructura, nombreEstructura, nombreEstructura, nombreEstructura);
        fprintf(pFile, "%s", "\n\treturn returnAux;\n} ");

        fprintf(fp, "%s", "/** \\brief Constructor.\n");
        fprintf(fp, "%s", " *\n");
        fprintf(fp, "%s", " * \\param void\n");
        fprintf(fp, " * \\return %s* Puntero a estructura\n", nombreEstructura);
        fprintf(fp, "%s", " *\n");
        fprintf(fp, "%s", " */\n");
        fprintf(fp, "%s* %s_new(void);\n", nombreEstructura, nombreEstructura);

        printf("\nConstructor generado con exito!\n");
    }

    fclose(pFile);

}

void imprimirFinalStruct(char nombreArchivoH[50], char nombreEstructura[50], char nombreArchivo[50])
{
    FILE* pFile;
    FILE* fp;
    char buffer[100];

    fp = fopen("temporal.h", "r");
    pFile = fopen(nombreArchivoH, "a");


    fprintf(pFile, "}typedef %s;\n\n", nombreEstructura);

    strupr(nombreArchivo);
    fprintf(pFile, "#endif // %s_H_INCLUDED\n", nombreArchivo);


    fclose(pFile);

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int main()
{
    FILE* pArchive;
    char aux[50];
    char miNombre[50];
    int i=0;

    ///Crea un archivo, en este caso de texto.
    ///El primer parametro es el path, si se omite va a parar a la carpeta raiz del proyecto.
    ///El segundo param es el tipo de operacion (w = write - esto pisa cualquier archivo creado anteriormentecon ese nombre).
    ///wb escribe en binario.
    ///rb lee binario.
    pArchive=fopen("miNombre.txt","w");

    ///Para escribir archivos de texto.
    fprintf(pArchive, "Me llamo Joel.\n");
    ///Para escribir archivos de texto o binarios.
    //fwrite(&i,sizeof(int),1,pArchive);
    fprintf(pArchive, "Tengo 27 anios.\n");
    fprintf(pArchive, "Mi apellido es Mahafud.\n");
    fprintf(pArchive, "Sexo masculino.\n");
    fprintf(pArchive, "Hello world.\n");

    ///Cierra el archivo y pisa guardando los cambios.
    fclose(pArchive);





    ///Modo solo lectura.
    pArchive=fopen("miNombre.txt","r");


    while(feof(pArchive))///Find end of file.
    {
        ///Obtiene un string desde un archivo.
        fgets(aux,50,pArchive);

        strcpy(miNombre[i],aux);
        i++;


    }

    while(feof(pArchive))///Find end of file.
    {
        printf("%s", miNombre);
    }

    ///Cierra el archivo y pisa guardando los cambios.
    fclose(pArchive);

    return 0;
}
*/

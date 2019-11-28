#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    char mail[50];
    float sueldo;

}eEmpleado;

int main()
{
    FILE* pArchivo;
//    char lector[1000];
    char id[50];
    char nombre[50];
    char apellido[50];
    char mail[50];
    char sueldo[50];
    eEmpleado lista[50];
    eEmpleado unEmpleado;
    int i=0;

    pArchivo = fopen("Empleados.csv", "r");

    ///strtok puede splitear las lineas de un archivo.

//    fgets (lector,1000,pArchivo);
//    fgets (lector,1000,pArchivo);
//    puts(lector);
    fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,mail,sueldo);

    do
    {
        ///Lee hasta la coma excluyendola.

        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,apellido,mail,sueldo);

        unEmpleado.id = atoi(id);

        strcpy(unEmpleado.nombre,nombre);

        strcpy(unEmpleado.apellido,apellido);

        strcpy(unEmpleado.mail,mail);

        unEmpleado.sueldo=atof(sueldo);

        lista[i]=unEmpleado;
        i++;
    }while(!feof(pArchivo));

    fclose(pArchivo);

    for(i=0;i<49;i++)
    {
        if(lista[i].sueldo>5000)
        {
            printf("%d--%s--%s--%s--%.02f\n",lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].mail, lista[i].sueldo);
        }
    }
    return 0;
}

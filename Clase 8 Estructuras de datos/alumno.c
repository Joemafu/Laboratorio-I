#include "alumno.h"

void mostrarAlumno(eAlumno unAlumno)
{

    printf("%d\n%s\n%d\n", unAlumno.legajo, unAlumno.nombre, unAlumno.nota);

}
eAlumno pedirAlumno()
{
    eAlumno miAlumno;

    printf("Ingrese legajo: \n");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: \n");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("Ingrese nota: \n");
    scanf("%d", &miAlumno.nota);

    return miAlumno;
}
int compararAlumnosPorLegajo(eAlumno unAlumno, eAlumno otroAlumno)
{
    int comp;
    comp = 0;
    if(unAlumno.legajo==otroAlumno.legajo)
    {
        comp=1;
    }
    return comp;
}
void cargarAlumnos (eAlumno lista[], int cant)
{
    int i;
    for (i=0; i<cant; i++)
    {
        /*printf("Ingrese un legajo: \n");
        scanf("%d", &listaDeAlumnos[i].legajo);*/

        lista[i] = pedirAlumno();
    }
}
void mostrarListaDeAlumnos(eAlumno lista[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        mostrarAlumno(lista[i]);
    }
}
void ordenarAlumnosPorNombre(eAlumno lista[], int cant)
{
    int i;
    int j;
    eAlumno aux;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)<0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}
void hardcodearAlumnos (eAlumno lista[],int cant)
{
    int i;
    int legajo[5]= {101,102,105,106,107};
    int nota[5]= {10,5,9,7,8};
    char nombre[5][20]= {"Juan","Maria","Jose","Mateo","Rocio"};

    for(i=0; i<cant; i++)
    {
        lista[i].legajo=legajo[i];
        lista[i].nota=nota[i];
        strcpy(lista[i].nombre,nombre[i]);
    }
}


#include "alumno.h"

int inicializarAlumnos (eAlumno* lista,int cantidad)
{
    int i;
    int retorno=-1;

    if(lista!=NULL&&cantidad>0)
    {
        for(i=0; i<cantidad; i++)
        {
            lista[i].estado = LIBRE;
        }
        retorno=1;
    }

    return retorno;
}



void mostrarAlumno(eAlumno unAlumno)
{

    printf("%d\n%s\n%d\n\n", unAlumno.legajo, unAlumno.nombre, unAlumno.nota);

    return;
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
    int flag=0;
    for (i=0; i<cant; i++)
    {
        /*printf("Ingrese un legajo: \n");
        scanf("%d", &listaDeAlumnos[i].legajo);*/

        if(lista[i].estado==LIBRE)
        {
            lista[i] = pedirAlumno();
            lista[i].estado=OCUPADO;
            flag=1;
            break;
        }
        if (flag ==0)
        {
            printf("No hay espacio para cargar mas alumnos.\n");
        }


    }
}



void mostrarListaDeAlumnos(eAlumno lista[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarAlumno(lista[i]);
        }
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
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
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
        lista[i].estado=OCUPADO;
    }
}



int buscarAlumnoLibre (eAlumno lista[],int cantidad)
{
    int i;
    int index=-1;
    for(i=0; i< cantidad; i++)
    {
        if (lista[i].estado==LIBRE)
        {
            index=i;
            break;
        }
    }
    return index;
}

int buscarAlumnoPorLegajo (eAlumno lista[],int cantidad,int legajo)
{
    int i;
    int retorno=-1;
    if(lista!=NULL&&cantidad>0)
    {
        for(i=0; i<cantidad; i++)
        {
            if (lista[i].legajo==legajo)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}



int borrarAlumno (eAlumno lista[], int cantidad)
{
    int legajo;
    int index;
    int retorno=-1;
    char confirmacion;

    printf("Ingrese legajo del alumno a borrar:\n");
    scanf("%d", &legajo);
    fflush(stdin);
    index=buscarAlumnoPorLegajo(lista,cantidad,legajo);
    system("cls");

    if(index!=-1)
    {
        mostrarAlumno(lista[index]);
        printf("Esta seguro de que quiere eliminar el alumno? s/n.\n");
        scanf("%c",&confirmacion);

        if(confirmacion=='s')
        {
            lista[index].estado=0;
            retorno=0;
        }else
        {
            retorno=1;
        }
    }

    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 5

typedef struct
{
//campos o atributos

    int legajo;
    char nombre[50];
    int nota;

}eAlumno;

void mostrarAlumno(eAlumno);
eAlumno pedirAlumno();
int compararAlumnosPorLegajo(eAlumno, eAlumno);
void cargarAlumnos (eAlumno[], int);
void mostrarListaDeAlumnos(eAlumno[], int);
void ordenarAlumnosPorNombre(eAlumno[], int);
void hardcodearAlumnos (eAlumno[],int);

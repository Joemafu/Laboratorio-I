#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 5
#define OCUPADO 1
#define LIBRE 0

typedef struct
{
//campos o atributos

    int legajo;
    char nombre[50];
    int nota;
    int DNI;
    int estado;

}eAlumno;

/** \brief Muestra los alumnos cargados.
 *
 * \param eAlumno - Nombre del array a mostrar.
 * \return void
 *
 */
void mostrarAlumno(eAlumno);


/** \brief Solicita los datos para cargar un alumno.
 *
 * \return eAlumno - Nombre del array a cargar.
 *
 */
eAlumno pedirAlumno();


/** \brief Compara dos alumnos por legajo y devuelve 1 para igual, 0 para distintos.
 *
 * \param eAlumno - Array 1 a comparar.
 * \param eAlumno - Array 2 a comparar.
 * \return int - Devuelve 1 para igual, 0 para distintos.
 *
 */
int compararAlumnosPorLegajo(eAlumno, eAlumno);


/** \brief Llama la función pedirAlumnos y los carga únicamente si encuentra un espacio libre en el array.
 *
 * \param eAlumno - Array a cargar.
 * \param int - Cantidad de subíndices.
 * \return void
 *
 */
void cargarAlumnos (eAlumno[],int);


/** \brief Muestra todos los alumnos en estado OCUPADO
 *
 * \param eAlumno[] - Array a mostrar.
 * \param int - Cantidad de subíndices.
 * \return void
 *
 */
void mostrarListaDeAlumnos(eAlumno[],int);


void ordenarAlumnosPorNombre(eAlumno[],int);


void hardcodearAlumnos (eAlumno[],int);


int inicializarAlumnos (eAlumno*,int);


int buscarAlumnoLibre (eAlumno[],int);


int buscarAlumnoPorLegajo (eAlumno[],int,int);


int borrarAlumno (eAlumno[], int);

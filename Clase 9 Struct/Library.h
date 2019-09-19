#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 3

typedef struct
{
    char nombre[50];
    char apellido[50];
    int DNI;
    int estaVacio;
} ePersona;

/** \brief Inicializa el parámetro "estaVacio" de todo el array en valor = 1.
 *
 * \param ePersona[] Nombre del array eVariable a procesar.
 * \param int Canpacidad del array
 * \return void
 *
 */
void inicializarPersonas(ePersona [],int);

/** \brief Carga la cantidad de personas que se le indique. Setea estaVacio = 0.
 *
 * \param ePersona [] Nombre del array eVariable a cargar.
 * \param int Cantidad de personas a cargar.
 * \return Void
 *
 */
void pedirPersona (ePersona [], int);

int validarDNI (ePersona persona[], int cant, int aux);

/** \brief Muestra la cantidad de eVariables que se le indique (sólo muestra los que tengan estaVacio = 0).
 *
 * \param ePersona [] Nombre del array eVariable a mostrar.
 * \param int Cantidad de personas a mostrar.
 * \return Void
 *
 */
void mostrarPersona (ePersona [], int);

/** \brief Ordena el array según valor de DNI.
 *
 * \param ePersona[] Nombre del array eVariable a ordenar.
 * \param int Cantidad de subíndices del array.
 * \return Void
 *
 */
void ordenarPorDNI(ePersona[],int);

/** \brief Ordena el array por apellido.
 *
 * \param ePersona[] Nombre del array eVariable a ordenar.
 * \param int Cantidad de subíndices del array.
 * \return Void
 *
 */
void ordenarPorApellido(ePersona[],int);

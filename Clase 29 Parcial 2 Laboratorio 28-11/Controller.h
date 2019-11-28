#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vuelo.h"
#include "parser.h"

/** \brief Carga los datos de los elementos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param flightList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* flightList);

/** \brief Listar elementos
 *
 * \param flightList LinkedList*
 * \return int
 *
 */
int controller_ListElement(LinkedList* flightList);

/** \brief Guarda los datos de los elementos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param flightList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* flightList, char* path);

void controller_countPassengers(LinkedList* flightList);

void controller_countPassengersToIreland(LinkedList* flightList);

void controller_filterShortFlights(LinkedList* flightList);

void controller_filterPortugalFlights(LinkedList* flightList);

void controller_filterAlexLifeson(LinkedList* flightList);

void controller_exit(LinkedList* flightList);

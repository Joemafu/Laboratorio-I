#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vuelo.h"

/** \brief Parsea los datos los datos de los vuelos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param elementList LinkedList*
 * \return int
 *
 */
int parser_FlightFromText(FILE* pFile, LinkedList* elementList);

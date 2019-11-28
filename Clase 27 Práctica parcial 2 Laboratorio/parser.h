#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Llamada.h"

/** \brief Parsea los datos los datos de los llamados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
int parser_TicketFromText(FILE* pFile, LinkedList* pArrayListElement);

/** \brief Parsea los datos de los llamados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
int parser_TicketFromBinary(FILE* pFile, LinkedList* pArrayListElement);

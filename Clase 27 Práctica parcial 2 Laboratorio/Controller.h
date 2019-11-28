#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Llamada.h"
#include "parser.h"

/** \brief Carga los datos de los elementos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListElement);

/** \brief Carga los datos de los elementos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
//int controller_loadFromBinary(char* path, LinkedList* pArrayListElement);

/** \brief Alta de elementos
 *
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
//int controller_addElement(LinkedList* pArrayListElement);

/** \brief Modificar datos de elemento
 *
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
//int controller_editElement(LinkedList* pArrayListElement);

/** \brief Baja de elemento
 *
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
//int controller_removeElement(LinkedList* pArrayListElement);

/** \brief Listar elementos
 *
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
int controller_ListElement(LinkedList* pArrayListElement);

/** \brief Ordenar elementos
 *
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
//int controller_sortElement(LinkedList* pArrayListElement);

/** \brief Guarda los datos de los elementos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* pArrayListElement);

/** \brief Guarda los datos de los elementos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
//int controller_saveAsBinary(char* path, LinkedList* pArrayListElement);



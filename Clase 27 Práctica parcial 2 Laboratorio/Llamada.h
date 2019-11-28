#ifndef Ticket_H_INCLUDED
#define Ticket_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AuxFunctions.h"
typedef struct
{
    int id;
    char date[11];
    int clientID;
    int errorCode;
    char status[3];
} Llamada;


/** \brief Creates space in the heap for a new ticket, and asks to the user for the values of each field
 *         except the ID that is autoincremental. Then returns a pointer to the created element.
 *
 * \return Llamada* Pointer to en ticket element.
 *
 */
Llamada* ticket_new();

/** \brief Creates space in the heap for a new ticket, and uses the values that gets by param to set the id,
 *         nombre and horasTrabajadas fields. Then returns a pointer to the created element.
 *
 * \param char* Char array with id value.
 * \param char* Char array with nombre value.
 * \param char* Char array with horasTrabajadas value.
 * \return Llamada* Pointer to en ticket element.
 *
 */
Llamada* ticket_newParametros(char* id,char* date,char* clientID,char* errorCode, char* status);


/** \brief Removes an ticket
 *
 * \param LinkedList* Linked List that contains the ticket.
 * \param int len Length of the linked list.
 * \return void
 *
 */
void ticket_delete(LinkedList* pArrayListticket,int len);


/** \brief Expects an ticket pointer and an int value to set the id field of the ticket.
 *
 * \param this Llamada* Pointer to the ticket to be setted.
 * \param id int Value to be set on the id field
 * \return int
 *
 */
int ticket_setId(Llamada* this,int id);

/** \brief Expects a pointer to ticket and a memory address to an int var, in which it will save
 *         the value of the id field of said ticket.
 *
 * \param this Llamada* Pointer to en ticket element.
 * \param sueldo int* Memory address to an int var
 * \return int
 *
 */
int ticket_getId(Llamada* this,int* id); ///Devuelven 1 en caso de exito.

/** \brief Expects an ticket pointer and an char array to set the nombre field of the ticket.
 *
 * \param this Llamada* Pointer to the ticket to be setted.
 * \param nombre char* Value to be set on the nombre field
 * \return int
 *
 */
int ticket_setDate(Llamada* this,char* date);

/** \brief Expects a pointer to ticket and a memory address to a char array, in which it will save
 *         the value of the name field of said ticket.
 *
 * \param this Llamada* Pointer to en ticket element.
 * \param sueldo int* Memory address to a char array
 * \return int
 *
 */
int ticket_getDate(Llamada* this,char* date);///Devuelven 1 en caso de exito.

/** \brief Expects an ticket pointer and an int value to set the horasTrabajadas field of the ticket.
 *
 * \param this Llamada* Pointer to the ticket to be setted.
 * \param horasTrabajadas int Value to be set on the horasTrabajadas field
 * \return int
 *
 */
int ticket_setClientID(Llamada* this,int clientID);

/** \brief Expects a pointer to ticket and a memory address to an int var, in which it will save
 *         the value of the ClientID field of said ticket.
 *
 * \param this Llamada* Pointer to en ticket element.
 * \param sueldo int* Memory address to an int var
 * \return int
 *
 */
int ticket_getClientID(Llamada* this,int* clientID);///Devuelven 1 en caso de exito.

/** \brief Expects an ticket pointer and an int value to set the sueldo field of the ticket.
 *
 * \param this Llamada* Pointer to the ticket to be setted.
 * \param sueldo int Value to be set on the sueldo field
 * \return int
 *
 */
int ticket_setErrorCode(Llamada* this,int errorCode);


/** \brief Expects a pointer to ticket and a memory address to an int var, in which it will save
 *         the value of the salary field of said ticket.
 *
 * \param this Llamada* Pointer to en ticket element.
 * \param sueldo int* Memory address to an int var
 * \return int
 *
 */
int ticket_getErrorCode(Llamada* this,int* errorCode);///Devuelven 1 en caso de exito.

/** \brief Expects an ticket pointer and an int value to set the sueldo field of the ticket.
 *
 * \param this Llamada* Pointer to the ticket to be setted.
 * \param sueldo int Value to be set on the sueldo field
 * \return int
 *
 */
int ticket_setStatus(Llamada* this,char* status);


/** \brief Expects a pointer to ticket and a memory address to an int var, in which it will save
 *         the value of the salary field of said ticket.
 *
 * \param this Llamada* Pointer to en ticket element.
 * \param sueldo int* Memory address to an int var
 * \return int
 *
 */
int ticket_getStatus(Llamada* this,char* status);///Devuelven 1 en caso de exito.

/** \brief Prints a list of every element on the array.
 *
 * \param pArrayListticket LinkedList*
 * \return void
 *
 */
void ticket_showEveryone(LinkedList* pArrayListticket);

/** \brief Compares two elements by their ID value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
//int compareById (void*, void*);

/** \brief Compares two elements by their name value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
//int compareByName (void*, void*);

/** \brief Compares two elements by their worked hours value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
//int compareByWorkedHours (void*, void*);

/** \brief Compares two elements by their salary value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
//int compareBySalary (void*, void*);

/** \brief Compares two elements by their salary value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
int compareByErrorCode (void* pElement);

int compareToOne (void* pElement);

int compareToTwo (void* pElement);

int compareToThree (void* pElement);

int compareToFour (void* pElement);

int compareToFive (void* pElement);

#endif // Ticket_H_INCLUDED

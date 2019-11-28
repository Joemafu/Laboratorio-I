#ifndef Flight_H_INCLUDED
#define Flight_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AuxFunctions.h"
typedef struct
{
    int idFlight;
    int idPlane;
    int idPilot;
    char date[11];
    char destination[51];
    int amountOfPassengers;
    int departureTime;
    int arrivalTime;

} Flight;

/** \brief Creates space in the heap for a new flight, and uses the values that gets by param to set the id,
 *         nombre and horasTrabajadas fields. Then returns a pointer to the created element.
 *
 * \param char* Char array with id value.
 * \param char* Char array with nombre value.
 * \param char* Char array with horasTrabajadas value.
 * \return Flight* Pointer to en flight element.
 *
 */
Flight* flight_newParametros(char* flightID,char* plane,char* pilot,char* date, char* destination, char* amountOfPassengers,char* departureTime, char* arrivalTime);

/** \brief Expects a pointer to element and an int value to set the id field of the element.
 *
 * \param this Flight* Pointer to the element to be setted.
 * \param id int Value to be set on the id field
 * \return int
 *
 */
int flight_setFlightId(Flight* this,int id);
int flight_setPlaneID(Flight* this,int idPlane);
int flight_setPilotID(Flight* this,int idPilot);
int flight_setDate(Flight* this,char* date);
int flight_setDestination(Flight* this,char* destination);
int flight_setAmountOfPassengers(Flight* this,int amountOfPassengers);
int flight_setDepartureTime(Flight* this,int departureTime);
int flight_setArrivalTime(Flight* this,int arrivalTime);

/** \brief Expects a pointer to element and a memory address to an int var, in which it will save
 *         the value of the id field of said element.
 *
 * \param this Flight* Pointer to an element.
 * \param sueldo int* Memory address to an int var
 * \return int
 *
 */
int flight_getFlightId(Flight* this,int* id);
int flight_getPlaneID(Flight* this,int* idPlane);
int flight_getPilotID(Flight* this,int* idPilot);
int flight_getDate(Flight* this,char* date);
int flight_getDestination(Flight* this,char* destination);
int flight_getAmountOfPassengers(Flight* this,int* amountOfPassengers);
int flight_getDepartureTime(Flight* this,int* departureTime);
int flight_getArrivalTime(Flight* this,int* arrivalTime);

/** \brief Prints a list of every element on the LinkedList.
 *
 * \param flightList LinkedList*
 * \return void
 *
 */
void flight_showEveryone(LinkedList* flightList);

int passengerCounter (void* pElement);

int counterToIreland (void* pElement);

int compareShortFlights(void* pElement);

int compareDestinationPortgual(void* pElement);

int comparePilotAlexLifeson(void* pElement);

#endif // Flight_H_INCLUDED

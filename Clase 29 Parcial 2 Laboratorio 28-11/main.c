#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Vuelo.h"
#include "parser.h"
#include "AuxFunctions.h"

int main()
{
    int option;
    LinkedList* flightList = ll_newLinkedList();

    do
    {
        option=showMenuGetOption("Menu:\n\n\
        1. Cargar archivo.\n\
        2. Imprimir vuelos.\n\
        3. Cantidad de pasajeros\n\
        4. Cantidad de pasajeros a Irlanda\n\
        5. Filtrar vuelos cortos\n\
        6. Listar vuelos a Portugal\n\
        7. Filtrar a Alex Lifeson\n\
        8. Salir\n\
        ",1,8);
        switch(option)
        {
        case 1:
            controller_loadFromText(flightList);
            break;
        case 2:
            controller_ListElement(flightList);
            break;
        case 3:
            controller_countPassengers(flightList);
            break;
        case 4:
            controller_countPassengersToIreland(flightList);
            break;
        case 5:
            controller_filterShortFlights(flightList);
            break;
        case 6:
            controller_filterPortugalFlights(flightList);
            break;
        case 7:
            controller_filterAlexLifeson(flightList);
            break;
        case 8:
            controller_exit(flightList);
            break;
        }
    }
    while(option != 8);

    return 0;
}
